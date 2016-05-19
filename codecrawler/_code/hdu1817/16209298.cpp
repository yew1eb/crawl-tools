#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL __int64
using namespace std;

LL GCD(LL a,LL b)
{
    if(b == 0)
        return a;
    return GCD(b,a%b);
}

LL Pow(LL a, LL m)
{
    LL ans = 1;
    while(m)
    {
        if(m & 1)
            ans *= a;
        a *= a;
        m >>= 1;
    }
    return ans;
}
int main()
{
    LL N;
    while(~scanf("%I64d",&N) && N != -1)
    {
        if(N <= 0)
        {
            printf("0\n");
            continue;
        }
        LL sum = 0;
        for(int i = 1; i <= N; ++i)
        {
            LL tmp = GCD(N,i);
            sum += (LL)(Pow(3LL,tmp));
        }
        if(N & 1)
            sum += (LL)(N * Pow(3LL, (N+1)/2));
        else
        {
            sum += (LL)((N/2) * Pow(3LL, (N+2)/2));
            sum += (LL)((N/2) * Pow(3LL, N/2));
        }

        sum = sum/2/N;
        printf("%I64d\n",sum);
    }

    return 0;
}

