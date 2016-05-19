/*
hdu 2576 Another Sum Problem
1^2+2^2+3^2...   n(n+1)(2n+1)/6
å¬å¼å¾å¥½æ¨
n(n+1)(n+2)/6
ä½æ¯ä¸ºä»ä¹éè¦å/2ç¶åå/3å¢ï¼æ±è§£ç­
*/
#include<stdio.h>
#define N 20090524
int main()
{
    __int64 t,a,ret;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&a);
        a=a%N;
        ret=(a*(a+1))/2%(N*3);
        ret=(ret*(a+2))/3%N;
        printf("%I64d\n",ret);
    }
    return 0;
}