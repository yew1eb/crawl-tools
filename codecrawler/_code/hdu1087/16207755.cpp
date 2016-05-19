#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[1005],dp[1005];
const int inf = 999999999;

int main()
{
    int n,i,t,m,j,ans;
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        for(i = 1;i<=n;i++)
        scanf("%d",&a[i]);
        for(i = 1;i<=n;i++)
        {
            ans = -inf;
            for(j = 0;j<i;j++)
            {
                if(a[i]>a[j])
                ans = max(ans,dp[j]);
            }
            dp[i] = ans+a[i];
        }
        ans = -inf;
        for(i = 0;i<=n;i++)
        {
            if(dp[i]>ans)
            ans = dp[i];
        }
        printf("%d\n",ans);
    }

    return 0;
}
