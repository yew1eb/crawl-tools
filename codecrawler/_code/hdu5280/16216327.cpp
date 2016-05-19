#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1005
long long a[N];
long long dp[N];
int main()
{
    long long x;
    scanf("%lld",&x);
    while(x--)
    {
        long long i,j,m,n;
        long long  M=-0x3f3f3f3f;
        scanf("%lld%lld",&m,&n);
        for(i=1;i<=m;i++)
        {
            scanf("%lld",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++)
        {
            int t=a[i];
            a[i]=n;
            for(j=1;j<=m;j++)
            {
                dp[j]=max(a[j],dp[j-1]+a[j]);
                M=max(M,dp[j]);
            }
            a[i]=t;
        }
        printf("%lld\n",M);
    }
    return 0;
}