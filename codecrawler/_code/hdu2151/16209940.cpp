//ç¶æè½¬ç§»æ¹ç¨:dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
//dp[i][j]è¡¨ç¤ºä»åå§ç¶æè³ç¬¬iåéç¬¬jæ£µæ çè¡èµ°æ¹æ¡æ°
#include <stdio.h>
#include <string.h>
#define MAXN 102

int dp[MAXN][MAXN];

int main()
{
    int n,p,m,t,i,j;
    while(scanf("%d %d %d %d",&n,&p,&m,&t)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0][p]=1;//åå§ç¶æ
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        }
        printf("%d\n",dp[m][t]);
    }
    return 0;
}