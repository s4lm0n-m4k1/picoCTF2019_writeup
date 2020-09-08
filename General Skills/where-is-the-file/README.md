# where-is-the-file
## Category
General Skills
## Problem Statement
> I've used a super secret mind trick to hide this file. Maybe something lies in `/problems/where-is-the-file_1_54878e9f5b7db0ddbaf642cdb5c9b3b5`.

## Solution 
```shell
$ cd /problems/where-is-the-file_1_54878e9f5b7db0ddbaf642cdb5c9b3b5
$ ls -la
total 80
drwxr-xr-x   2 root       root        4096 Sep 28  2019 .
drwxr-x--x 684 root       root       69632 Oct 10  2019 ..
-rw-rw-r--   1 hacksports hacksports    39 Sep 28  2019 .cant_see_me
```
I check the content of the directory using list `ls` command with long `-l` and all `-a` option. \
ディレクトリの中身をリストコマンド`ls`とロング`-l`とオール `-a`optionを使ってチェックしてみました。 
<br> <br>
Since `.cant_see_me` file is readable, I used the `cat` command to check the content of the file. \
ファイル `.cant_see_me` がリーダブルだったので`cat`コマンドを使って中身をチェックしてみました。
```shell
$ cat .cant_see_me 
picoCTF{w3ll_that_d1dnt_w0RK_3e782057}
```
> Reference: N.A 
## Flag
`picoCTF{w3ll_that_d1dnt_w0RK_3e782057}`
