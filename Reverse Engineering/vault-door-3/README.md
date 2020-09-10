# vault-door-3 - Points: 200
## Category
Reverse Engineering 
## Problem 
> This vault uses for-loops and byte arrays. The source code for this vault is here: [VaultDoor3.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-3/VaultDoor3.java)
## Solution 
```java
import java.util.*;

class Main {
    public static void main(String args[]) {
        Main vaultDoor = new Main();
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

    // Our security monitoring team has noticed some intrusions on some of the
    // less secure doors. Dr. Evil has asked me specifically to build a stronger
    // vault door to protect his Doomsday plans. I just *know* this door will
    // keep all of those nosy agents out of our business. Mwa ha!
    //
    // -Minion #2671
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        char[] buffer = new char[32];
        int i;
        for (i=0; i<8; i++) {
            buffer[i] = password.charAt(i);
        }
        for (; i<16; i++) {
            buffer[i] = password.charAt(23-i);
        }
        for (; i<32; i+=2) {
            buffer[i] = password.charAt(46-i);
        }
        for (i=31; i>=17; i-=2) {
            buffer[i] = password.charAt(i);
        }
        String s = new String(buffer);
        return s.equals("jU5t_a_sna_3lpm1dg347_u_4_mfr54b");
    }
}
```
looking at the source code, the following line is trying to remove `picoCTF{}` from the user input; remaining the string inside the `{}` \
ソースコードを見たら下に書かれてあるコードがフラグの `picoCTF{}` 消してるのがわかります。チェックされてるのは`{}`の中身です。
```java
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
        char[] buffer = new char[32];
        int i;
        for (i=0; i<8; i++) {
            buffer[i] = password.charAt(i);
        }
        for (; i<16; i++) {
            buffer[i] = password.charAt(23-i);
        }
        for (; i<32; i+=2) {
            buffer[i] = password.charAt(46-i);
        }
        for (i=31; i>=17; i-=2) {
            buffer[i] = password.charAt(i);
        }
        String s = new String(buffer);
        return s.equals("jU5t_a_sna_3lpm1dg347_u_4_mfr54b");
    }
```

The following function tries to jamble the given input and compares it to `jU5t_a_sna_3lpm1dg347_u_4_mfr54b`, this means when the right answer is given, the result of the process will be `jU5t_a_sna_3lpm1dg347_u_4_mfr54b` as well. \
<br>
以下の関数は、与えられた入力をシャッフルして `jU5t_a_sna_3lpm1dg347_u_4_mfr54b` と比較し、正解がなるようにしています。手なわけで、もし正しい答えを入力された場合、入力文字が　`jU5t_a_sna_3lpm1dg347_u_4_mfr54b` になります。 \
<br>
Using the seen conditions, I created similar function which input will be `jU5t_a_sna_3lpm1dg347_u_4_mfr54b` and outputs the shuffled value. \
見た条件を使って、似たような関数を作ってみました。
```c
#include <stdio.h>
int main()
{
    char equalsTo[32] = "jU5t_a_sna_3lpm1dg347_u_4_mfr54b";
    char ans[32];
    int i;

    ans[32] = '\0';
    for (i=0; i<8; i++) 
    {
        ans[i] = equalsTo[i];
    }
    for (; i<16; i++) 
    {
        ans[i] = equalsTo[23-i];
    }
    for (; i<32; i+=2) 
    {
        ans[i] = equalsTo[46-i];
    }
    for (i=31; i>=17; i-=2) 
    {
        ans[i] = equalsTo[i];
    }

    printf("%s\n",ans);
    return (0);
}
```
```
$ gcc -Wall -Werror -Wextra -o vd3 vd3.c 
$ ./vd3 
jU5t_a_s1mpl3_an4gr4m_4_u_7f35db
$ 
```
## Reference: 
> [Solution Source](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-3/vd3.c) 
## Flag
```
picoCTF{jU5t_a_s1mpl3_an4gr4m_4_u_7f35db}
```
