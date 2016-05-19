#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[100006];

int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        memset(dp,0,sizeof(dp));
        int i,j,aim;
        int ka[105],val[105];
        for(i = 0; i<t; i++)
            scanf("%d%d",&val[i],&ka[i]);
        scanf("%d",&aim);
        for(i = 0; i<t; i++) //ç¶æè½¬ç§»æ¹ç¨
        {
            for(j = ka[i]; j<=aim; j++)
            {
                dp[j] = max(dp[j],dp[j-ka[i]]+val[i]);
            }
        }
        printf("%d\n",dp[aim]);
    }

    return 0;
}
