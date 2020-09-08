# Bases - Points: 100
## Category
General Skills
## Problem Statement
> What does this mean? I think it has something to do with bases.
```diff 
- bDNhcm5fdGgzX3IwcDM1
``` 
## Solution 
When I saw this `bDNhcm5fdGgzX3IwcDM1`  I approached it by counting every possible character in this given string. <br>
与えられた文字列`bDNhcm5fdGgzX3IwcDM1`を見た時、何種類の文字が使われているか考えてみました。

|English|日本語|COUNT|
|:---:|:---:|:---:|
| Lowercase Alphabet Characters | 小文字のアルファベット | 26 |
| Uppercase Alphabet Characters | 大文字のアルファベット | 26 |
| Numbers from 0 to 9           | ０から９までの数字の数 | 10 |
| **TOTAL**                     |     **合計**　       | **62** |

Then I searched 62 base online on [Wiki Base62](https://en.wikipedia.org/wiki/Base62) and this came out.　<br>
その後、６２進数に関してウィキで検索してみました。[Wiki Base62](https://en.wikipedia.org/wiki/Base62)

```
 123456789ABCDEFGH JKLMN PQRSTUVWXYZabcdefghijk mnopqrstuvwxyz
= 58 characters = base58

0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
= 62 characters = base62

0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/
= 64 characters = base64
```
I tried converting base62 but it doesn't work perfectly on the tools available online, so I tried base64 instead (since they're simillar) and it worked perfectly. </br>
６２進数をツールとか使って解読してみたら、上手く行かなかったので６４進数を使ってみました。（ほぼ同じなので）そしたら、上手く行きました。

> Reference: [base64decode.org](https://www.base64decode.org/) </br>
## Flag
`picoCTF{l3arn_th3_r0p35}`
