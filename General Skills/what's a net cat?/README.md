# what's a net cat? - Points: 100
## Category
General Skills
## Problem Statement
> Using netcat (nc) is going to be pretty important. Can you connect to 2019shell1.picoctf.com at port 32225 to get the flag?
## Solution 
I tried to check the manual of netcat (nc) command. \
netcat (nc)コマンドのマニュアルをチェックしました。
```shell
$ man nc

NC(1)                        BSD General Commands Manual                       NC(1)

NAME
     nc — arbitrary TCP and UDP connections and listens

SYNOPSIS
     nc [-46bCDdFhklNnrStUuvZz] [-I length] [-i interval] [-M ttl] [-m minttl]
        [-O length] [-P proxy_username] [-p source_port] [-q seconds] [-s source]
        [-T keyword] [-V rtable] [-W recvlimit] [-w timeout] [-X proxy_protocol]
        [-x proxy_address[:port]] [-Z peercertfile] [destination] [port]
```
I tried to use this command without the option command, `nc [destination] [port]`. \
オプションなしで、このコマンド `nc [destination] [port]` を試してみました。
```shell
$ nc 2019shell1.picoctf.com 32225
You're on your way to becoming the net cat master
picoCTF{nEtCat_Mast3ry_b1d25ece}
```
> Reference: N.A. </br>
## Flag
`picoCTF{nEtCat_Mast3ry_b1d25ece}`
