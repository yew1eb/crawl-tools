#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[50005][3],val[50005],a[50005];

int main()
{
    int t,k,n,m,l;
    scanf("%d",&t);
    while(t--)
    {
        int t;
        scanf("%d",&n);
        int i,j;
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&k);
        l = 1;
        memset(val,0,sizeof(val));
        for(i = 1; i<=n-k+1; i++)
        {
            for(j = i; j<i+k; j++)
            {
                val[i]+=a[j];
            }
        }
        l = n-k+1;
        memset(dp,0,sizeof(dp));
        dp[0][0] = val[1];
        for(i = 1; i<=l; i++)
        {
            dp[i][0] = max(dp[i-1][0],val[i]);
        }
        for(i = k+1; i<=l; i++)
        {
            dp[i][1] = max(dp[i-1][1],dp[i-k][0]+val[i]);
        }
        for(i = 2*k+1; i<=l; i++)
            dp[i][2] = max(dp[i-1][2],dp[i-k][1]+val[i]);
        printf("%d\n",dp[l][2]);

    }

    return 0;
}