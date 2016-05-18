//题目意思讲的是中国剩余定理的过程，但终究问题只是关于N%Mi=Mi-k
// 由这个关系式可以得到N+k=0（mod Mi）
// 所以这个问题转化为求n个数的最小公倍数了
#include <cstdio>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    return !b?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long n,m;
    while(scanf("%I64d%I64d",&n,&m),m||n)
    {
        long long a;
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a);
            ans=lcm(ans,a);
        }
        printf("%I64d\n",ans-m);
    }
    return 0;
}