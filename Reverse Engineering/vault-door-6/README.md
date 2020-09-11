# vault-door-6 - Points: 250
## Category
Reverse Engineering 
## Problem 
> This vault uses an XOR encryption scheme. The source code for this vault is here: [VaultDoor6.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-6/VaultDoor6.java) 
## Solution 
```java
import java.util.*;

class VaultDoor6 {
    public static void main(String args[]) {
        VaultDoor6 vaultDoor = new VaultDoor6();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // Dr. Evil gave me a book called Applied Cryptography by Bruce Schneier,
    // and I learned this really cool encryption system. This will be the
    // strongest vault door in Dr. Evil's entire evil volcano compound for sure!
    // Well, I didn't exactly read the *whole* book, but I'm sure there's
    // nothing important in the last 750 pages.
    //
    // -Minion #3091
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            0x3b, 0x65, 0x21, 0xa , 0x38, 0x0 , 0x36, 0x1d,
            0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa ,
            0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
            0xa , 0x63, 0x65, 0x64, 0x67, 0x37, 0x6d, 0x62,
        };
        for (int i=0; i<32; i++) {
            if (((passBytes[i] ^ 0x55) - myBytes[i]) != 0) {
                return false;
            }
        }
        return true;
    }
}

```
looking at the source code, the following line is trying to remove `picoCTF{}` from the user input; remaining the string inside the `{}` \
ソースコードを見たら下に書かれてあるコードがフラグの `picoCTF{}` 消してるのがわかります。チェックされてるのは`{}`の中身です。
```
String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
```
After that, the program checks whether the following condition is correct or not. \
その後、以下の条件が正しいかどうかをチェックします。
```java
if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
```
```java
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            0x3b, 0x65, 0x21, 0xa , 0x38, 0x0 , 0x36, 0x1d,
            0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa ,
            0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
            0xa , 0x63, 0x65, 0x64, 0x67, 0x37, 0x6d, 0x62,
        };
        for (int i=0; i<32; i++) {
            if (((passBytes[i] ^ 0x55) - myBytes[i]) != 0) {
                return false;
            }
        }
        return true;
    }
```
The code below performs Bytes comparison, therefore we can reverse this by performing `myBytes[i] ^ 0x55` \
下にあるコードがバイトが同じかどうか判断しています。このやり方を逆に考えれば、`myBytes[i] ^ 0x55` になります。
```java
if (((passBytes[i] ^ 0x55) - myBytes[i]) != 0) {
                return false;
            }
```
With the set goal, I created a [program](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-6/vd6.py) that performs our hypothesis, and at the same time outputs the result in binary number. \
設定した目標をもとに、仮説を実行し、同時に結果を2進数で出力する[プログラム](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-6/vd6.py)を作成しました。
```python
output = []
myBytes = [
    0x3b, 0x65, 0x21, 0xa , 0x38, 0x0, 0x36, 0x1d,
    0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa,
    0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
    0xa , 0x63, 0x65, 0x64, 0x67, 0x37, 0x6d, 0x62
]

for by in range(len(myBytes)):
    output.append(myBytes[by] ^ 0x55)

for by in range(len(output)):
    print (bin(output[by])[2:])

```
```
$ python vd6.py 
$ 1101110 110000 1110100 1011111 1101101 1010101 1100011 1001000 1011111 1101000 110100 1110010 1000100 110011 1110010 1011111 1110100 1001000 110100 1101110 1011111 1111000 110000 1110010 1011111 110110 110000 110001 110010 1100010 111000 110111
```
After this, I simply translated the binary number to ASCII characters. \
答えをそのまま２進数からASCIIに変えました。
## Reference: 
> [Binary to ASCII](https://www.rapidtables.com/convert/number/binary-to-ascii.html)
## Flag
```
picoCTF{n0t_mUcH_h4rD3r_tH4n_x0r_6012b87}
```
