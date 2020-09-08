# First Grep: Part II - Points: 200
## Category
General Skills
## Problem 
> Can you find the flag in `/problems/first-grep--part-ii_1_4496a9af2273007b52d4a1adec323b76/files` on the shell server? Remember to use grep.
## Solution 
```shell
$ cd /problems/first-grep--part-ii_1_4496a9af2273007b52d4a1adec323b76/files
$ ls -l
total 44
drwxr-xr-x 2 root root 4096 Sep 28  2019 files0
drwxr-xr-x 2 root root 4096 Sep 28  2019 files1
drwxr-xr-x 2 root root 4096 Sep 28  2019 files10
drwxr-xr-x 2 root root 4096 Sep 28  2019 files2
drwxr-xr-x 2 root root 4096 Sep 28  2019 files3
drwxr-xr-x 2 root root 4096 Sep 28  2019 files4
drwxr-xr-x 2 root root 4096 Sep 28  2019 files5
drwxr-xr-x 2 root root 4096 Sep 28  2019 files6
drwxr-xr-x 2 root root 4096 Sep 28  2019 files7
drwxr-xr-x 2 root root 4096 Sep 28  2019 files8
drwxr-xr-x 2 root root 4096 Sep 28  2019 files9
$ ls files0
file0   file11  file14  file17  file2   file22  file25  file3  file6  file9
file1   file12  file15  file18  file20  file23  file26  file4  file7
file10  file13  file16  file19  file21  file24  file27  file5  file8
```
The given diretory consists of folders with bunch of files inside of it. I decide to use recursive option to find the keyword in all directory and its subdirectory. \
ディレクトリの中身にいろんなファイルやディレクトリが入っていたので最近関数を使って答えを探してみました。
```shell
$ grep --help
...
-r, --recursive
...
$ grep -r "pico"
files1/file22:picoCTF{grep_r_to_find_this_af11356f}
```
Turns out the answer was located at files1/file22! \
答えはファイル１の中のファイル２２に入っていました！
> Reference: N.A.
## Flag
`picoCTF{grep_r_to_find_this_af11356f}`
