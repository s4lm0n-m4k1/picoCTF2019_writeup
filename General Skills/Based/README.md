# Based - Points: 200
## Category
General Skills
## Problem 
> To get truly 1337, you must understand different data encodings, such as hexadecimal or binary. Can you get the flag from this program to prove you are on the way to becoming 1337? Connect with nc 2019shell1.picoctf.com 44303.
## Solution 
First, connect using nc command.\
ncコマンドを使って与えられたポートに入ってみました。
```shell
$ nc 2019shell1.picoctf.com 44303
Let us see how data is stored
map
Please give the 01101101 01100001 01110000 as a word.
...
you have 45 seconds.....

Input:
map
Please give me the  154 151 155 145 as a word.
Input:
lime
Please give me the 7375626d6172696e65 as a word.
Input:
submarine
You've beaten the challenge
Flag: picoCTF{learning_about_converting_values_b515dfd2}
```
It asked me a random question regarding binary, octal, and hexadecimal conversion. I used the ASCII converter that is available online to solve the given question. \
ランダムな課題を聞いてきたので、ネットであるサービスを使いながら答えを出しました。課題内容：２進数、８進数、１６進数。

## Reference: 
[2 -> ASCII](https://www.rapidtables.com/convert/number/binary-to-ascii.html) \
[8 -> ASCII](http://www.unit-conversion.info/texttools/octal/) \
[16 -> ASCII](https://www.rapidtables.com/convert/number/hex-to-ascii.html) 
## Flag
`picoCTF{learning_about_converting_values_b515dfd2}`
