#include<stdio.h>
long long euler(long long n)     //æ¬§æå½æ°
{
     long long res=n,a=n;
     for(long long i=2;i*i<=a;i++)
        {
         if(a%i==0)
         {
             res=res/i*(i-1);
             while(a%i==0)
             a/=i;
         }
     }
     if(a>1)
        res=res/a*(a-1);
     return res;
}
int main ()
{
    long long n,x;
    while(~scanf("%I64d%I64d",&n,&x))
    {
        printf("%I64d\n",euler(n+x+1));
    }
    return 0;
}