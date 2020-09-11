# vault-door-4 - Points: 250
## Category
Reverse Engineering 
## Problem 
> In the last challenge, you mastered octal (base 8), decimal (base 10), and hexadecimal (base 16) numbers, but this vault door uses a different change of base as well as URL encoding! The source code for this vault is here: [VaultDoor5.java](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Reverse%20Engineering/vault-door-5/VaultDoor5.java)
## Hints
> You may find an encoder/decoder tool helpful, such as https://encoding.tools/ \
> Read the wikipedia articles on URL encoding and base 64 encoding to understand how they work and what the results look like.
## Solution 

```java
import java.net.URLDecoder;
import java.util.*;

class VaultDoor5 {
    public static void main(String args[]) {
        VaultDoor5 vaultDoor = new VaultDoor5();
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

    // Minion #7781 used base 8 and base 16, but this is base 64, which is
    // like... eight times stronger, right? Riiigghtt? Well that's what my twin
    // brother Minion #2415 says, anyway.
    //
    // -Minion #2414
    public String base64Encode(byte[] input) {
        return Base64.getEncoder().encodeToString(input);
    }

    // URL encoding is meant for web pages, so any double agent spies who steal
    // our source code will think this is a web site or something, defintely not
    // vault door! Oh wait, should I have not said that in a source code
    // comment?
    //
    // -Minion #2415
    public String urlEncode(byte[] input) {
        StringBuffer buf = new StringBuffer();
        for (int i=0; i<input.length; i++) {
            buf.append(String.format("%%%2x", input[i]));
        }
        return buf.toString();
    }

    public boolean checkPassword(String password) {
        String urlEncoded = urlEncode(password.getBytes());
        String base64Encoded = base64Encode(urlEncoded.getBytes());
        String expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVm"
                        + "JTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2"
                        + "JTM0JTVmJTY0JTYyJTM2JTM5JTM0JTM2JTYyJTYx";
        return base64Encoded.equals(expected);
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
    public String urlEncode(byte[] input) {
        StringBuffer buf = new StringBuffer();
        for (int i=0; i<input.length; i++) {
            buf.append(String.format("%%%2x", input[i]));
        }
        return buf.toString();
    }

    public boolean checkPassword(String password) {
        String urlEncoded = urlEncode(password.getBytes());
        String base64Encoded = base64Encode(urlEncoded.getBytes());
        String expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVm"
                        + "JTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2"
                        + "JTM0JTVmJTY0JTYyJTM2JTM5JTM0JTM2JTYyJTYx";
        return base64Encoded.equals(expected);
    }
```
To solve this problem, We want the `expected` string to be decoded from base64, and urlEncode (in order). p.s. This is the reverse method seen in the source code\
この問題を解決するためには、`expected`の文字列をbase64からurlEncode(順に)デコードしましょう。 p.s. ソースコードの逆のやり方です\
### String expected in one line
```
JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVmJTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2JTM0JTVmJTY0JTYyJTM2JTM5JTM0JTM2JTYyJTYx
```
### expected -> base64
```
%63%30%6e%76%33%72%74%31%6e%67%5f%66%72%30%6d%5f%62%61%35%65%5f%36%34%5f%64%62%36%39%34%36%62%61
```
### base64 -> URL Decode
```
c0nv3rt1ng_fr0m_ba5e_64_db6946ba
```

## Reference: 
> [encoding.tools](https://encoding.tools/)
## Flag
```
picoCTF{c0nv3rt1ng_fr0m_ba5e_64_db6946ba}
```
