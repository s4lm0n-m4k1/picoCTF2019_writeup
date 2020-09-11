# So Meta - Points: 150
## Category
Forensics
## Problem 
> Find the flag in this [picture](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Forensics/So%20Meta/pico_img.png). You can also find the file in `/problems/so-meta_4_4e8d17dbd28e1fdfe82ba31ceb021615`.
## Solution
![picture](https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/blob/master/Forensics/So%20Meta/pico_img.png)
### Method 1
```
$ cat pico_img.png
```
### Method 2
```
$ xxd pico_img.png
```
### Method 3
```
$ hexdump -C pico_img.png
```
### Result
```
��6)�S)�d���]1���"txER�zr�q�̣(���6?WN��G�HeY��}
                                                   EREQԓ��0)��(���(�B��(�)��(� �(��(���(��2A�`�zIWl tEXtArtistpicoCTF{s0_m3ta_9a16fd1d}�F�IEND�B`� 
```
## Note: 
## Note: 
> RTFM!
## Flag
```
picoCTF{s0_m3ta_9a16fd1d}
```
