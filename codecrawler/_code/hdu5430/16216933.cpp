#include<stdio.h>
#define LL long long
//UVAç¨
LL fun(LL m)
{
    LL res=m;
    for(LL i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            res=(res*(i-1))/i;
 //           printf("i=%I64d,res=%I64d\n",i,res);
            while(m%i==0)
            {
                m/=i;
            }
        }
    }
    if(m>1) res=(res*(m-1))/m;
    return res;
}
int main()
{
    LL n;
    int T;
    scanf ("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",fun(n+1));
    }
    return 0;
}
