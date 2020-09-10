# vault-door-training - Points: 50 
## Category
Reverse Engineering 
## Problem 
> Your mission is to enter Dr. Evil's laboratory and retrieve the blueprints for his Doomsday Project. The laboratory is protected by a series of locked vault doors. Each door is controlled by a computer and requires a password to open. Unfortunately, our undercover agents have not been able to obtain the secret passwords for the vault doors, but one of our junior agents obtained the source code for each vault's computer! You will need to read the source code for each level to figure out what the password is for that vault door. As a warmup, we have created a replica vault in our training facility. The source code for the training vault is here: [VaultDoorTraining.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-1/VaultDoor1.java)
## Solution 
```java
import java.util.*;

class VaultDoorTraining {
    public static void main(String args[]) {
        VaultDoorTraining vaultDoor = new VaultDoorTraining();
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

    // The password is below. Is it safe to put the password in the source code?
    // What if somebody stole our source code? Then they would know what our
    // password is. Hmm... I will think of some ways to improve the security
    // on the other doors.
    //
    // -Minion #9567
    public boolean checkPassword(String password) {
        return password.equals("w4rm1ng_Up_w1tH_jAv4_e57d01a632a");
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
```
if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
```
```
 public boolean checkPassword(String password) {
        return password.equals("w4rm1ng_Up_w1tH_jAv4_e57d01a632a");
    }
```
Meaning, if the string inside the `{}` is equal to the condition `w4rm1ng_Up_w1tH_jAv4_e57d01a632a` then it is corrrect. \
Therefore, the flag will be written as picoCTF{w4rm1ng_Up_w1tH_jAv4_e57d01a632a} \
つまり、`{}` 内の文字列が条件 `w4rm1ng_Up_w1tH_jAv4_e57d01a632a` と一致していれば、それは正しいことになります。\
この結果で答えは picoCTF{w4rm1ng_Up_w1tH_jAv4_e57d01a632a} となります。
## Reference: 
> N.A.
## Flag
```
picoCTF{w4rm1ng_Up_w1tH_jAv4_e57d01a632a}
```
