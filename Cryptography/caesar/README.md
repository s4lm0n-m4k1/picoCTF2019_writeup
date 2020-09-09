# caesar - Points: 100 
## Category
Cryptography 
## Problem 
> Decrypt this [message](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/Cryptography/caesar/ciphertext). You can find the ciphertext in `/problems/caesar_0_22aa542fadadcc37b6ec6037c493ec9f` on the shell server.
## Hint
> caesar cipher [tutorial](https://privacycanada.net/classical-encryption/caesar-cipher/)
## Solution 
After understanding the tutorial given, I searched for decoder online that I can use for decrypting cipher text that can be found in given directory. \
チュートリアルを理解した後、与えられたディレクトリにある暗号文を解読するのに使えるデコーダをオンラインで探しました。
```shell
$ cd /problems/caesar_0_22aa542fadadcc37b6ec6037c493ec9
$ cat ciphertext 
picoCTF{jyvzzpunaolybipjvunfzpthre}
```
Not knowing the shift, I tested all the possible shift to make the gibbrish text `jyvzzpunaolybipjvunfzpthre` somewhat readable. \
シフトを知らないので、ジブリッシュテキストを読みるまでに、可能な限りのシフトをテストしました。

| shift | decrypted text |
| :---: | :---: |
| +6 | dspttjohuifsvcjdpohztjnbly |
| **+7** | **crossingtherubicongysimakx** |
| +8 | bqnrrhmfsgdqtahbnmfxrhlzjw |

## Reference: 
> [dcode](https://www.dcode.fr/caesar-cipher)
## Flag
`picoCTF{crossingtherubicongysimakx}`
