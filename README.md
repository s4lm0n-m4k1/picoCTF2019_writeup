# picoCTF2019 Writeup - ENGLISH | 日本語
Solutions and writeups on how I approach and solved the problems for the picoCTF Cybersecurity Competition.</br>
picoCTFサイバーセキュリティコンテストの問題を自分がどのように解いているかの解答と解説。</br>

I also included japanese explanation as I am currently practicing my japanese skill \
日本語を勉強しているので、picoCTF2019を日本語で説明を作りました。
## Note:
I am no practitioner of cybersecurity related field. Just an enthusiast that would like to be professional someday. </br>
私はサイバーセキュリティ関連分野のエンジニアではありません。</br> いつかはプロになりたいと思っているただの愛好家です。</br>　</br>　
also... this is my first ever public repository... </br>

## Pico Profile (as of 09-09-2020)
I'm working under username **g4nb4r0u**

Final Score: **9100**

**Solved**:
* 2   Binary Exploitation  </br>
* 8   Cryptography </br>
* 8   Forensics  </br>
* 16  General Skills  </br>
* 6   Reverse Engineering  </br>
* 12  Web Exploitation </br>

**Total**: Solved 52 Problems

### Repository Status (09-10-2020)

<table>
  <tr>
    <td><b><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Binary%20Exploitation>Binary Exploitation</a></b></td>
        <td><b><a href =https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Cryptography>Cryptography</a></b></td>
        <td><b><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Forensics>Forensics</a></b></td>
        <td><b><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills>General Skills</a></b></td>
        <td><b><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Reverse%20Engineering>Reverse Engineering</a></b></td>
          <td><b><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Web%20Exploitation>Web Exploitation</a></b></td>
  </tr>
  <tr>
    <td>handy-shellcode</td>
    <td><a href =https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Cryptography/The%20Numbers>The Numbers </a></td>
    <td> Glory of the Garden </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/2Warm> 2Warm </td>
    <td> vault-door-training </td>
    <td> Insp3ct0r </td>

  </tr>
  <tr>
    <td><a href = https://github.com/s4lm0n-m4k1/picoCTF2019_writeup/tree/master/Binary%20Exploitation/practice-run-1>practice-run-1</td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Cryptography/13> 13 </td>
    <td> unzip </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Lets%20Warm%20Up> Lets Warm Up  </td>
    <td> vault-door-1  </td>
    <td> dont-use-client-side </td>
  </tr>
  <tr>
    <td> </td>
    <td> Easy1 </td>
    <td> So Meta </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Warmed%20Up> Warmed Up </td>
    <td> vault-door-3 </td>
    <td> logon </td>
  </tr>
    <tr>
    <td>  </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Cryptography/caesar> caesar </td>
    <td> What Lies Within </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Bases> Bases </td>
    <td> vault-door-4  </td>
    <td> where are the robots </td>
  </tr>
    <tr>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/Cryptography/Flags> Flags </td>
    <td> extensions </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/First%20Grep> First Grep </td>
    <td> vault-door-5 </td>
    <td> Client-side-again </td>
  </tr>
    <tr>
    <td>  </td>
    <td> Mr-Worldwide </td>
    <td> shark on wire 1 </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Resources> Resources </td>
    <td> vault-door-6  </td>
    <td> Open-to-admins </td>
  </tr>
    <tr>
    <td>  </td>
    <td> Tapping </td>
    <td> WhitePages </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Strings%20it> strings it </td>
    <td>  </td>
    <td> picobrowser </td>
  </tr>
    <tr>
    <td>  </td>
    <td> rsa-pop-quiz </td>
    <td> like1000 </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/what's%20a%20net%20cat%3F> what's a net cat?  </td>
    <td>  </td>
    <td> Irish-Name-Repo 1 </td>
  </tr>  <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td> <a href =https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/Based> Based </td>
    <td>  </td>
    <td> Irish-Name-Repo 2  </td>
  </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/First%20Grep:%20Part%20II> First Grep: PART II </td>
    <td>  </td>
    <td> Empire1 </td>
  </tr>
    </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/plumbing> plumbing </td>
    <td>  </td>
    <td> Irish-Name-Repo 3 </td>
  </tr>
    </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/whats-the-difference> whats-the-difference </td>
    <td>  </td>
    <td> JaWT Scratchpad </td>
  </tr>
    </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/where-is-the-file> where-is-the-file </td>
    <td>  </td>
    <td>  </td>
  </tr>
    </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/flag_shop> flag_shop </td>
    <td>  </td>
    <td>  </td>
  </tr>
    </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td><a href=https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/mus1c> mus1c </td>
    <td>  </td>
    <td>  </td>
  </tr>  
  </tr>
    <tr>
    <td>  </td>
    <td>  </td>
    <td>  </td>
    <td> <a href = https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/tree/master/General%20Skills/1_wanna_b3_a_r0ck5tar> 1_wanna_b3_a_r0ck5tar </td>
    <td>  </td>
    <td>  </td>
  </tr>
   <tr>
    <td td colspan= "6"><i>no link means no explantion yet</i></td>
  </tr>
</table>

Category | Solved | Explanation Made |
:--- | :---:  |  :---:           |
Binary Exploitation  | 2  | 1 |
Cryptography |  8     | 4 |
Forensics |  8     | 0 |
General Skills |  16     | 16 |
Reverse Engineering |  6     | 0 |
Web Exploitation |  12     | 0 |

