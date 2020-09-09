# 1_wanna_b3_a_r0ck5tar - Points: 350 
## Category
General Skills
## Problem Statement
> I wrote you another [song](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/1_wanna_b3_a_r0ck5tar/lyrics.txt). Put the flag in the picoCTF{} flag format
## Solution 
Reading the **rockstar**'s documentation and understanding the lyrics, the code consists of bunch of echoes and conditions. If we focus on output and disregard the condition, we will focus on the following...  \
<br>
**rockstar**のドキュメントを見て歌詞を頑張って理解してみると、コードの中身はechoとか<br>コンディションが入っています。コンディションを無視しながらひたすらアウトプットだけ見ていくとこにすると…　
```rockstar
Tommy is rockin guitar
Shout Tommy!                    
Music is amazing sensation 
Jamming is awesome presence
Scream Music!                   
Scream Jamming!                 
Tommy is playing rock           
Scream Tommy!       
They are dazzled audiences                  
Shout it!
Rock is electric heaven                     
Scream it!
Tommy is jukebox god            
Say it!       
```
you will notice that its declaring at the same time doing some echoes. \
よく見てみれば、変数を宣言した後、echoしています。

for example \
例えば、
```rockstar
Tommy is rockin guitar
Shout Tommy! 
```

The number of *rockin* & *guitar* returns 6 6 therefore **66** is being echoed. \
この部分だと *rockin* と　*guitar* が　6 6　なので　**66**　がechoされます。

| character  | character count  |
| :---: | :---: |
| rockin | 6 |
| guitar | 6 |

Following this idea, the output returns \
このやり方他の部分をチェックすると答えはこうなります。

```
66
79
78
74
79
86
73
```

The following output was trasnlated to ASCII value and the result are... \
これをそのまま１０進数からASCIIに変えるツールを使いました。<br>

```
BONJOVI
```
## Reference: 
> [Rockstar](https://codewithrockstar.com/online) </br>
> [RapidTables](https://www.rapidtables.com/convert/number/ascii-hex-bin-dec-converter.html)
## Flag
`picoCTF{BONJOVI}`
