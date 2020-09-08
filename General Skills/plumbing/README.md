# plumbing - Points: 200
## Category
General Skills
## Problem 
> Sometimes you need to handle process data outside of a file. Can you find a way to keep the output from this program and search for the flag? Connect to 2019shell1.picoctf.com 13203.
## Solution 
```shell
$ nc 2019shell1.picoctf.com 13203
Not a flag either
Again, I really don't think this is a flag
This is defintely not a flag
This is defintely not a flag
This is defintely not a flag
I don't think this is a flag either
This is defintely not a flag
```
It returns bunch of unncesseary text so I used `grep` command to find the specific one that I need. \
いろんな答えが出てきたので`grep`コマンドを使ってみました。
```shell
$ nc 2019shell1.picoctf.com 13203 | grep "pico"
picoCTF{digital_plumb3r_995d3c81}
```
> Reference: N.A.
## Flag
`picoCTF{digital_plumb3r_995d3c81}`
