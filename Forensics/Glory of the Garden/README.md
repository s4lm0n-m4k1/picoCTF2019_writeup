# Glory of the Garden - Points: 50
## Category
Forensics
## Problem 
> This [garden](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Forensics/Glory%20of%20the%20Garden/garden.jpg) contains more than it seems. You can also find the file in `/problems/glory-of-the-garden_1_2e13eb26e18a569a71cc32f9d51ccb4e` on the shell server.
## Solution 
### garden file
![garden](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Forensics/Glory%20of%20the%20Garden/garden.jpg)
### Method 1
```
$ cat garden.jpg 
```
### Method 2
```
$ xxd garden.jpg 
```
### Method 3
```
$ hexdump -C garden.jpg
```
### Result
```
����cp���Κ��'�֖V
               ���?/\qZf��d�4�Հ��<?�,���Ϻ�Q\u��{��%���K�ɩn�~��O��)�Y*sҾq���}�}et�#�<�j~k��V�y9���S�� 1�u�������������Ӳ���Here is a flag "picoCTF{more_than_m33ts_the_3y3b7FBD20b}"
```
## Note: 
> RTFM!
```
picoCTF{more_than_m33ts_the_3y3b7FBD20b}
```
