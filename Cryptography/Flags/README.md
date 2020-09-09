# Flags - Points: 200
## Category
Cryptography 
## Problem 
> What do the [flags](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/Flags/flag.png) mean?
## Hint
> The flag is in the format PICOCTF{}
## Solution 
![flags](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/Flags/flag.png) \
I suspected that this one is diplaying a flag format after seeing the curly bracket. \
括弧`{ }`を見た後、これはフラグだと疑いました。 \
<br>
Since I don't have any idea with what the flag means, I tried to search flag cipher and I learn about [nautical-flag](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/Flags/nautical-flag.png).\
旗の意味がわからないので、旗暗号で検索してみたところ、海旗のことを知りました。[nautical-flag](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/Flags/nautical-flag.png).\
![nautical-flag](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/Flags/nautical-flag.png)\
Using the reference, you may convert the flags to upper alphabetical character / number. \
検索した画像を参考にしながら、フラグを大文字アルファベットもしくは、数字に変換してみましょう。
## Reference 
> [Nautical Sailing Flags](https://www.google.com/search?q=nautical+sailing+flags&sxsrf=ALeKk001vkzPT1-xZHDrrtGyPYUhPMFSxg:1599687392280&source=lnms&tbm=isch&sa=X&ved=2ahUKEwj0y5L2g93rAhUNq5QKHZsFB9AQ_AUoAXoECB0QAw&biw=638&bih=369).
## Flag
`PICOCTF{F1AG5AND5TUFF}`
