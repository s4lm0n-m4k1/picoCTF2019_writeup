#include <stdio.h>
int main()
{
    char equalsTo[32] = "jU5t_a_sna_3lpm1dg347_u_4_mfr54b";
    char ans[32];
    int i;

    ans[32] = '\0';
    for (i=0; i<8; i++) 
    {
        ans[i] = equalsTo[i];
    }
    for (; i<16; i++) 
    {
        ans[i] = equalsTo[23-i];
    }
    for (; i<32; i+=2) 
    {
        ans[i] = equalsTo[46-i];
    }
    for (i=31; i>=17; i-=2) 
    {
        ans[i] = equalsTo[i];
    }

    printf("%s\n",ans);
    return (0);
}