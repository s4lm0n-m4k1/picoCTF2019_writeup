# strings it - Points: 100
## Category
General Skills
## Problem 
> Can you find the flag in [file](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/String%20it/strings) without running it? You can also find the file in /problems/strings-it_1_7a67382a38fc00751a6b9b29b0872813 on the shell server.
## Solution 
First I navigate to the given directory and check the file permission of `file`.
与えられたディレクトリの中にある`file`の権限を確認しました。
```shell
cd /problems/strings-it_1_7a67382a38fc00751a6b9b29b0872813
ls -l 
total 760
-rwxr-sr-x 1 hacksports strings-it_1 776032 Sep 28  2019 strings
```
The file has executable permission so I tried to run it.\
実行の権限があったので、試してみました。
```shell
./strings 
Maybe try the 'strings' function? Take a look at the man page
```
It says use the `strings` command so I tried to use it without any opiton . </br>
`strings`コマンドを使ってみて、答え出したのでオプションなしで、試してみました。
```shell
$ strings strings 
/lib64/ld-linux-x86-64.so.2
libc.so.6
puts
stdout
__cxa_finalize
...
```
It outputs alot of strings so I tried to pipe it with `grep` command using keyword `pico`.　\
答えが多かったので、`grep`コマンドでキーワード`pico`でもう一度試してみました。
```shell
$ strings strings | grep "pico"
picoCTF{5tRIng5_1T_0690b2a5}
```
> Reference: N.A.
## Flag
`picoCTF{5tRIng5_1T_0690b2a5}`
