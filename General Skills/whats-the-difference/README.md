# whats-the-difference - Points: 200
## Category
General Skills
## Problem 
> Can you spot the difference? [kitters](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/whats-the-difference/kitters.jpg) [cattos](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/whats-the-difference/cattos.jpg). They are also available at `/problems/whats-the-difference_0_00862749a2aeb45993f36cc9cf98a47a` on the shell server
## Hints
> How do you find the difference between two files?　\
> Dumping the data from a hex editor may make it easier to compare.
## Solution 
Following the hints advice, I tried to familiarize myself with `hexdump` | `xxd`  and `diff` command　\
ヒントに対して、`hexdump`,`xxd`,`diff`コマンドの使い方を検索してみました。 \
\
After I familiarize myself, I tried research on how to use `hexdump` | `xxd` as a parameter on using `diff` command. \
リサーチした後、`diff`のパラメーターの中にどうやってコマンドの答えを入力するのか検索してみました。
> check reference.
```
diff <(command) <(command)
```
```shell
$ cd /problems/whats-the-difference_0_00862749a2aeb45993f36cc9cf98a47a
$ ls
cattos.jpg  kitters.jpg
$ diff <(xxd kitters.jpg) <(xxd cattos.jpg)

3109c3109
< 0000c240: 21d3 6da6 4b99 9d98 c860 1b95 41e8 b93d  !.m.K....`..A..=
---
> 0000c240: 21d3 6da6 4b70 6963 6f60 1b95 41e8 b93d  !.m.Kpico`..A..=
5479c5479
< 00015660: e57c 4779 71fd a114 5e64 7e4b 0662 0a90  .|Gyq...^d~K.b..
---
> 00015660: e57c 4779 71fd a114 5e64 7e4b 0662 4390  .|Gyq...^d~K.bC.
10166c10166
< 00027b50: 5b5b 3ed2 d142 a003 dcf4 c1f4 ff00 eb53  [[>..B.........S
---
> 00027b50: 5b5b 3ed2 d142 a003 dc54 c1f4 ff00 eb53  [[>..B...T.....S
10952c10952
< 0002ac70: 72df 452d a476 c259 0101 88fe f71d 6bb1  r.E-.v.Y......k.
---
...
```
Seeing this, I manually retrieve the difference of 2 file. \
この後、自力で違ったところを取りました。
```shell
3109c3109
< 0000c240: 21d3 6da6 4b99 9d98 c860 1b95 41e8 b93d  !.m.K....`..A..=
---
> 0000c240: 21d3 6da6 4b70 6963 6f60 1b95 41e8 b93d  !.m.Kpico`..A..=
```
The first one shows ```!.m.K....`..A..=``` and ```!.m.Kpico\`..A..=``` where the 2nd one has `pico` while the 1st one dont.　\
最初の部分の ```!.m.K....`..A..=``` ＆ ```!.m.Kpico`..A..=``` をよく見てみれば、２番めの方`pico`が入っていて１番目にはありませんでした。
```shell
5479c5479
< 00015660: e57c 4779 71fd a114 5e64 7e4b 0662 0a90  .|Gyq...^d~K.b..
---
> 00015660: e57c 4779 71fd a114 5e64 7e4b 0662 4390  .|Gyq...^d~K.bC.
```
> C
```shell
10166c10166
< 00027b50: 5b5b 3ed2 d142 a003 dcf4 c1f4 ff00 eb53  [[>..B.........S
---
> 00027b50: 5b5b 3ed2 d142 a003 dc54 c1f4 ff00 eb53  [[>..B...T.....S
```
>T

At this point you have `picoCT` keep it going and you'll get the answer. \
この時点で`picoCT`まで出来上がっているので、後は頑張って見ましょう。
## Reference
[diff + xxd](https://superuser.com/questions/125376/how-do-i-compare-binary-files-in-linux).
## Flag
`picoCTF{th3yr3_a5_d1ff3r3nt_4s_bu773r_4nd_j311y_aslkjfdsalkfslkflkjdsfdszmz10548}`
