# mus1c - Points: 300 
## Category
General Skills
## Problem Statement
> I wrote you a [song](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/mus1c/lyrics.txt). Put it in the picoCTF{} flag format
## Hints
> Do you think you can master rockstar?
## Solution 
Following the hint advice, I searched what is a **rockstar** and turns out it was a programming language. \
ヒントのアドバイスにしたがって**rockstar**を検索してたら、プログラミング言語でした。 <br>
<br>
Using the interpreter available in the official website, I copied and paste the lyrics and it returned bunch of decimal value. \
オフィシャルサイトで使えるインタープリター使って歌詞をコピペしてみたら、１０進数の答えがリターンされました。
```
114
114
114
111
99
107
110
114
110
48
49
49
51
114
Program completed in 65 ms
```
The following output was trasnlated to ASCII value and the result are... \
これをそのまま１０進数からASCIIに変えるツールを使いました。<br>
<br>
```rrocknrn0113r```
## Reference: 
> [Rockstar](https://codewithrockstar.com/online) </br>
> [RapidTables](https://www.rapidtables.com/convert/number/ascii-hex-bin-dec-converter.html)
## Flag
`picoCTF{rrrocknrn0113r}`
