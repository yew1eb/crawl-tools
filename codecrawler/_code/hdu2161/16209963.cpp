#include <stdio.h>

int isprime(int n)
{
    int i;
    if(n==1||n==2)
        return 0;
    if((n&1)==0)//nä¸ºå¶æ°
        return 0;
    for (i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n,cases=0;
    while(scanf("%d",&n)&&n>0)
    {
        if(isprime(n))
           printf("%d: yes\n",++cases);
        else
            printf("%d: no\n",++cases);
    }
}