# First Grep - Points: 100
## Category
General Skills
## Problem 
> Can you find the flag in `file`? This would be really tedious to look through manually, something tells me there is a better way. You can also find the file in `/problems/first-grep_0_93be1631acf1a93b98cdcc3e7b9fdc52` on the shell server.
## Solution 
First I navigate to the given directory and check the file permission of `file`.
与えられたディレクトリの中にある`file`の権限を確認しました。
```shell
$ cd /problems/first-grep_0_93be1631acf1a93b98cdcc3e7b9fdc52
$ ls -l file

g4nb4r0u@pico-2019-shell1:/problems/first-grep_0_93be1631acf1a93b98cdcc3e7b9fdc52$ ls -l file 
-rw-rw-r-- 1 hacksports hacksports 14551 Sep 28  2019 file
```
The file is readable but not executable, so I tried to check the content using `cat` command. </br>
ファイルリーダブルだったので、`cat`コマンドを使って中身をチェックしました。
```
...
Xr(G=!|b0#(_a.~kOV      ]7y5.p[pb62-#Gpa@)M%>`twtsm*b3z?&yv(*Pzw#>9A39LLYE=akw|x *(-6WNqDYcPxm|>ljouJX(,N%36#R?a7HNCI6~xI9fg)qf#5.eP~X)%^JQE-y,-%nd5n2Ww7ZuCL,|<XB;N/Z275QJvvmGlHQBorw.6Ys&W|OLm.I)c*+r>x!^P__9@2+<cCfn6pq*c^PVkEuvQO7WAc-,3UD,~C;pgiv B1wnu9<5yJL,G|iujfA $y!7y$gGZ>VG$s/P:rpk2X,NuVlam%pKi-9IvL&9~gxBM&J#hr-C]h4ji~@qlmj&$+j?>G5-SZ2;b$z.zTyM&DFCxXB]JN)pREEE1 p%E]Ayj>6x@K|+|@%0D&Y?)f3`mrzd,,DA0<%0 F#U1+giJYt Oi7+dwbFfn0Dyul      1%O-#:v$3KS4wpPzoZ$MHm33Gp q      CX~EgUrBU@hoVZ`;KdC?(TyAMSHO*tT`b/7&1q7fwhl@V   2;&+l7P~ipvD0W_4 xRl)Q-MDjcQ|=Q^^x%-5kN/|g/ra~lQBt!&?^4!0L3tOfjZ`sz;azu15yrm^^1F|B?>K$p4?HQ^9#c-7]/b9IO   hi[-;kB$l:epO]#8Y)yy,3qacpTt7FS])/H~xc:<So[bcH;.(*wK83^tE/$+<c:gzeg8YA2y@I.NtMDSD9N;bxvy3X=CC6#8x0dF29EXS]Ie$RT3iLvZBz+PEcGPV#rtP&LzSm|.>uO6in*yJK(FJjgz8Bx(%gOmcqSl#h7H4(y!~E:aHdnIfV@P`OTNr2iUF&QYZtKvMzZ%Dvln^hCcWA )f(bZ`<SZ%Kt:#1wZWKkya?=Q9zSYj^aDQ-]HB4pJ      ]Bj4UE_ckkOGu8F%p$NqB9Q#e1botL6`@$v&(0L#6K^>siDmbn~^9>-I|sMQ=:?TvX.l][E_jbeZJYLfyooXrDa&j8ySg&7K^AiaB,_~|:#8u$+ J$[<MC&zAQp-I_Dj;NWh%UB.O&Kt@vNbjbAhl?h#rkd<`4o^lox4nRsKXvMr8@@4]NE.n:K3<f.p?nvO.K    IEo1aW(+H+|&40jxMv*7Io3XcsZaHZYhG)M;cI<=4>^z~)6wV8D~7J /vf`0OphUwDf~K/!Q%!PZpbI/+jm9u+ l_%#S2[B:lID&HI))]Q         &w+tP7w[NZ#V1[K,Dr/+MI4zJwPLDZsZO HeOXk-jJlYV~4+xR^QVUw(m^$t18W7_=eKe&8_HAk(5]os-IqPK*kFOIEg&Jsszh_O-S8w9?byy=(e^mkR9     z-1AVm*`ER4jol;mVF>G7R(|etq=ge_  z!RAVud.eR&W@(eoU>Bk=12+5pGG|Mu(!gNI()AHEQnySt_.;Kw0hQSryHs|E]e`=-tOJ|2&C$*n(D-C?hrrQ#54a>QAJFgjqw(^e%^K?13X5PArxBYc7? 3xCALT+`r2MVoHS@jSa<[Q@4Q$42J4^&h?,z$x[IZ(2m_hqBL$bK1,&0B    G|=~g?7*n.j`ff;E3r)sHm,:BF^-l1G=/]8(rMxPs-z|SISt;x      rK      4bdNbd%7        6^
...
```
It outputs gibrish lines so I tried to find the specific keyword "pico" using `pipe` and `grep` command. </br>
出てきた中身が意味不明だったので、`pipe`と`grep`マンド使って"pico"のキーワード探してみました。
```shell
g4nb4r0u@pico-2019-shell1:/problems/first-grep_0_93be1631acf1a93b98cdcc3e7b9fdc52$ cat file | grep "pico"
picoCTF{grep_is_good_to_find_things_4b2451ea}
```
> Reference: N.A.
## Flag
`picoCTF{grep_is_good_to_find_things_4b2451ea}`
