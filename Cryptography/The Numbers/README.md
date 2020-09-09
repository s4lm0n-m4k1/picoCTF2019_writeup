# The Numbers - Points: 50
## Category
Cryptography 
## Problem 
> The [numbers](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/The%20Numbers/the_numbers.png)... what do they mean?
## Hint
> The flag is in the format PICOCTF{}
## Solution 
![numbers](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/The%20Numbers/the_numbers.png) \
I suspected that this one is diplaying a flag format after seeing the curly bracket. \
括弧`{ }`を見た後、これはフラグだと疑いました。
```
16 9 3 15 3 20 6 {　20 8 5 14 21 13 2 5 18 19 13 1 19 15 14 }
```
Given the hint and previous answers, I guess that the first few part `16 9 3 15 3 20 6 {` is `PICOCTF{`\
ヒントに前の課題の答え方を参考にして`16 9 3 15 3 20 6 {`これは`PICOCTF{`だと考えました。\
<br>
Given the hypothesis, it seems like the number states the nth alphabet. \
仮説を考えると、数字はアルファベットのn番目を示しているように思えます。 \
<br>
Using the reference, you may convert the numbers to alphabetical letters. \
与えられたリンクを参考にしながら、数字をアルファベットに変換してみましょう。
>Reference [Numbers-to-Letters](https://www.boxentriq.com/code-breaking/numbers-to-letters).
## Flag
`PICOCTF{THENUMBERSMASON}`
