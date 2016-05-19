#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define INF (long long)0xFFFFFFF
using namespace std;
typedef long long LL;
const int Max=100100;
LL dp[Max][15];
LL a[Max],b[Max];
int main()
{
    int l,n;
    while(scanf("%d%d",&l,&n)!=EOF)
    {
        for(int i=1;i<=l;i++)
            scanf("%I64d",&a[i]);
        for(int i=1;i<=l;i++)
            scanf("%I64d",&b[i]);
        for(int i=l+1;i<=n*l;i++)
        {
            a[i]=a[i-l];
            b[i]=b[i-l];
        }
        for(int i=1;i<15;i++)
            dp[0][i]=INF;
        dp[0][0]=0LL;
        for(int i=1;i<=l*n;i++)
        {
            for(int j=0;j<15;j++)
            {
                if(j==0)
                    dp[i][j]=dp[i-1][j+5]+b[i];
                else
                {
                    dp[i][j]=dp[i-1][j-1]+a[i];
                    if(j==10)
                        dp[i][j]=min(dp[i][j],dp[i-1][14]+a[i]);
                    if(j+5<15)
                        dp[i][j]=min(dp[i][j],dp[i-1][j+5]+b[i]);
                }
            }
        }
        LL ans=dp[l*n][0];
        for(int i=1;i<15;i++)
            ans=min(ans,dp[l*n][i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
