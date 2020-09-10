# vault-door-4 - Points: 250
## Category
Reverse Engineering 
## Problem 
> This vault uses ASCII encoding for the password. The source code for this vault is here: [VaultDoor4.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-4/VaultDoor4.java)
## Solution 
```java
import java.util.*;

class VaultDoor4 {
    public static void main(String args[]) {
        VaultDoor4 vaultDoor = new VaultDoor4();
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

    // I made myself dizzy converting all of these numbers into different bases,
    // so I just *know* that this vault will be impenetrable. This will make Dr.
    // Evil like me better than all of the other minions--especially Minion
    // #5620--I just know it!
    //
    //  .:::.   .:::.
    // :::::::.:::::::
    // :::::::::::::::
    // ':::::::::::::'
    //   ':::::::::'
    //     ':::::'
    //       ':'
    // -Minion #7781
    public boolean checkPassword(String password) {
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            106 , 85  , 53  , 116 , 95  , 52  , 95  , 98  ,
            0x55, 0x6e, 0x43, 0x68, 0x5f, 0x30, 0x66, 0x5f,
            0142, 0131, 0164, 063 , 0163, 0137, 063 , 0141,
            '7' , '2' , '4' , 'c' , '8' , 'f' , '9' , '2' ,
        };
        for (int i=0; i<32; i++) {
            if (passBytes[i] != myBytes[i]) {
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
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            106 , 85  , 53  , 116 , 95  , 52  , 95  , 98  ,
            0x55, 0x6e, 0x43, 0x68, 0x5f, 0x30, 0x66, 0x5f,
            0142, 0131, 0164, 063 , 0163, 0137, 063 , 0141,
            '7' , '2' , '4' , 'c' , '8' , 'f' , '9' , '2' ,
        };
        for (int i=0; i<32; i++) {
            if (passBytes[i] != myBytes[i]) {
                return false;
            }
        }
        return true;
    }
```
Looking at `myBytes` the content seems like decimal, hexadecimal, octal, and an ASCII in order. So I tried to convert all of it to ASCII character. \
`myBytes`を見てみると、内容は10進数、16進数、8進数、ASCIIの順になっています。ということで、全部ASCII文字に変換してみました。
```
j, U, 5, t, _, 4, _, b
U, n, C, h, _, 0, f, _,
b, Y, t, 3, s, _, 3, a,
7, 2, 4, c, 8, f, 9, 2,
```
## Reference: 
> [10 -> ASCII](https://www.rapidtables.com/code/text/ascii-table.html) \
[16 -> ASCII](https://www.rapidtables.com/convert/number/hex-to-ascii.html) \
[8 -> ASCII](http://www.unit-conversion.info/texttools/octal/) 
## Flag
```
picoCTF{jU5t_4_bUnCh_0f_bYt3s_3a724c8f92}
```
