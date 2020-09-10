# vault-door-1 - Points: 100 
## Category
Reverse Engineering 
## Problem 
> This vault uses some complicated arrays! I hope you can make sense of it, special agent. The source code for this vault is here: [VaultDoor1.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-1/VaultDoor1.java)
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

    // I came up with a more secure way to check the password without putting
    // the password itself in the source code. I think this is going to be
    // UNHACKABLE!! I hope Dr. Evil agrees...
    //
    // -Minion #8728
    public boolean checkPassword(String password) {
        return password.length() == 32 &&
               password.charAt(0)  == 'd' &&
               password.charAt(29) == '7' &&
               password.charAt(4)  == 'r' &&
               password.charAt(2)  == '5' &&
               password.charAt(23) == 'r' &&
               password.charAt(3)  == 'c' &&
               password.charAt(17) == '4' &&
               password.charAt(1)  == '3' &&
               password.charAt(7)  == 'b' &&
               password.charAt(10) == '_' &&
               password.charAt(5)  == '4' &&
               password.charAt(9)  == '3' &&
               password.charAt(11) == 't' &&
               password.charAt(15) == 'c' &&
               password.charAt(8)  == 'l' &&
               password.charAt(12) == 'H' &&
               password.charAt(20) == 'c' &&
               password.charAt(14) == '_' &&
               password.charAt(6)  == 'm' &&
               password.charAt(24) == '5' &&
               password.charAt(18) == 'r' &&
               password.charAt(13) == '3' &&
               password.charAt(19) == '4' &&
               password.charAt(21) == 'T' &&
               password.charAt(16) == 'H' &&
               password.charAt(27) == '1' &&
               password.charAt(30) == 'f' &&
               password.charAt(25) == '_' &&
               password.charAt(22) == '3' &&
               password.charAt(28) == 'e' &&
               password.charAt(26) == '5' &&
               password.charAt(31) == 'd';
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
        return password.length() == 32 &&
               password.charAt(0)  == 'd' &&
               password.charAt(29) == '7' &&
               password.charAt(4)  == 'r' &&
               password.charAt(2)  == '5' &&
               password.charAt(23) == 'r' &&
               password.charAt(3)  == 'c' &&
               password.charAt(17) == '4' &&
               password.charAt(1)  == '3' &&
               password.charAt(7)  == 'b' &&
               password.charAt(10) == '_' &&
               password.charAt(5)  == '4' &&
               password.charAt(9)  == '3' &&
               password.charAt(11) == 't' &&
               password.charAt(15) == 'c' &&
               password.charAt(8)  == 'l' &&
               password.charAt(12) == 'H' &&
               password.charAt(20) == 'c' &&
               password.charAt(14) == '_' &&
               password.charAt(6)  == 'm' &&
               password.charAt(24) == '5' &&
               password.charAt(18) == 'r' &&
               password.charAt(13) == '3' &&
               password.charAt(19) == '4' &&
               password.charAt(21) == 'T' &&
               password.charAt(16) == 'H' &&
               password.charAt(27) == '1' &&
               password.charAt(30) == 'f' &&
               password.charAt(25) == '_' &&
               password.charAt(22) == '3' &&
               password.charAt(28) == 'e' &&
               password.charAt(26) == '5' &&
               password.charAt(31) == 'd';
    }
```
There are alot of way to decode the given string password. But to save time, I simply use spreadsheet software to solve this problem. \
与えられた文字列のパスワードを解読する方法はたくさんあります。しかし、時間を節約するために、私は単にこの問題を解決するために表計算ソフトを使用しています。 \
<br>
First, remove the unnecessary characters and remain the number and its corresponding character. \
まず、不要な文字を削除し、番号とそれに対応する文字を残します。
```
0	'd' 
29	'7' 
4	'r' 
2	'5' 
23	'r' 
3	'c' 
17	'4' 
1	'3' 
7	'b' 
10	'_' 
5	'4' 
9	'3' 
11	't' 
15	'c' 
8	'l' 
12	'H' 
20	'c' 
14	'_' 
6	'm' 
24	'5' 
18	'r' 
13	'3' 
19	'4' 
21	'T' 
16	'H' 
27	'1' 
30	'f' 
25	'_' 
22	'3' 
28	'e' 
26	'5' 
31	'd'
```
Using google sheets for example, you can simply copy and paste this and sort the number into assceding order to arrange the character value. \
例えばgoogleシートを使って、これをコピペして、文字値を並べるように数字を並べ替えるだけです。

| Array |  char |
| :---: | :---: |
|	0	|	d	|
|	1	|	3	|
|	2	|	5	|
|	3	|	c	|
|	4	|	r	|
|	5	|	4	|
|	6	|	m	|
|	7	|	b	|
|	8	|	l	|
|	9	|	3	|
|	10	|	_	|
|	11	|	t	|
|	12	|	H	|
|	13	|	3	|
|	14	|	_	|
|	15	|	c	|
|	16	|	H	|
|	17	|	4	|
|	18	|	r	|
|	19	|	4	|
|	20	|	c	|
|	21	|	T	|
|	22	|	3	|
|	23	|	r	|
|	24	|	5	|
|	25	|	_	|
|	26	|	5	|
|	27	|	1	|
|	28	|	e	|
|	29	|	7	|
|	30	|	f	|
|	31	|	d	|

Meaning, if the string inside the {} is equal to the condition written below then it is corrrect.
つまり、{} 内の文字列が条件 下に書いてるストリングと一致していれば、それは正しいことになります。
```
d35cr4mbl3_tH3_cH4r4cT3r5_51e7fd
```

## Flag
```
picoCTF{d35cr4mbl3_tH3_cH4r4cT3r5_51e7fd}
```
