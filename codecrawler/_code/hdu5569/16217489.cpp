#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1005][1005],dp[1005][1005],n,m;

int main() {
    int i,j;
    while(scanf("%d%d",&n,&m)==2) {
        memset(dp,0x3f,sizeof(dp));
       dp[0][1]=dp[1][0]=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        for(i=2;i<=n;++i)//åå¤çç¬¬1åï¼é²æ­¢è¶ç
            dp[i][1]=dp[i-2][1]+a[i][1]*a[i-1][1];
        for(j=2;j<=m;++j)//åå¤çç¬¬1è¡ï¼é²æ­¢è¶ç
            dp[1][j]=dp[1][j-2]+a[1][j]*a[1][j-1];
        //æ²¡æ³å°ç¨âæä¸ºäººäººâåè½¬ç§»ç¶æï¼è¿æ ·å°±å¯ä»¥ç´æ¥å¤çï¼ä¸ç¨æå¿è¶çäº
        for(i=2;i<=n;++i)
            for(j=2;j<=m;++j)
                if((i+j)&1)
                    dp[i][j]=min(dp[i][j],min(min(dp[i-1][j-1],dp[i-2][j])+a[i][j]*a[i-1][j],min(dp[i-1][j-1],dp[i][j-2])+a[i][j]*a[i][j-1]));
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
