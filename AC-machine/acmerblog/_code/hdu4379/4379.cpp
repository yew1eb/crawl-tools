//1003
#include <cstdio>
long long n,l,a,b,mod;
int main()
{
    while(scanf("%lld%lld%lld%lld%lld",&n,&l,&a,&b,&mod)==5)
    {
        if(mod<=l/2||((a*n+b)<=l/2)||(a%mod==0||b%mod==0))
        {
            printf("%lld\n",n);
            continue;
        }
        long long mina=l+1,maxa=-1,sum=0;
        for(int i=1;i<=n;i++)
        {
            long long op=(a*i+b)%mod;
            if(op<=l/2)
            {
                sum++;
                if(maxa<op)
                maxa=op;
            }
            else
            {
                if(mina>op)
                {
                    mina=op;
                }
            }
        }
        if(mina+maxa<=l)
        sum++;
        printf("%lld\n",sum);
    }
    return 0;
}