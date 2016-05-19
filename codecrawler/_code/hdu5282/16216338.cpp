/**
hdu5282 æé¿å¬å±å­åºåçåå½¢
é¢ç®å¤§æï¼ç»å®ä¸¤ä¸ªå­ç¬¦ä¸²ï¼æ±äºèçæé¿å¬å±å­åºåï¼å¨aä¸­åºç°è¿çï¼æå¤å°æ¯bçå­åºå
è§£é¢æè·¯ï¼æ¥èªå®æ¹é¢è§£ã
          é¦åæä»¬ç¨O(n2)çå¨æè§åç®æ³å¤çåºdpæ°ç»ï¼dp[i][j]è¡¨ç¤ºXä¸²çåiä¸ªå­ç¬¦åY
          ä¸²çåjä¸ªå­ç¬¦çæé¿å¬å±å­åºåçé¿åº¦ï¼å¨è¿ä¸ªåºç¡ä¸æä»¬åè¿è¡ä¸ä¸ªå¨æè§åã
          ç¨f[i][j]è¡¨ç¤ºå¨Xä¸²çåiä¸ªå­ç¬¦ä¸­ï¼æå¤å°ä¸ªé¿åº¦ä¸ºdp[i][j]çå­åºåå¨Yçåjä¸ª
          å­ç¬¦ä¸­ä¹åºç°äºãè½¬ç§»ï¼è¥dp[iâ1][j]==dp[i][j]ï¼åf[i][j]+=f[iâ1][j]ï¼è¡¨ç¤ºi
          è¿ä¸ªå­ç¬¦ä¸éï¼åèèéiè¿ä¸ªå­ç¬¦ï¼æ¾å°Yä¸²åjä¸ªå­ç¬¦ä¸­æé åçä¸X[i]å¹éçå­
          ç¬¦çä½ç½®ï¼è®¾ä¸ºpï¼è¥dp[iâ1][pâ1]+1==dp[i][j]ï¼åf[i][j]+=f[iâ1][pâ1]ãæç»
          çç­æ¡å³ä¸ºf[n][m]ãå¤æåº¦O(n2)ã

*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=1005;
int dp[maxn][maxn],n,m,wei[maxn][maxn];
char a[maxn],b[maxn];
LL f[maxn][maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",a,b);
        n=strlen(a);
        m=strlen(b);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                if(a[i]==b[j])
                    dp[i+1][j+1]=max(dp[i][j]+1,dp[i+1][j+1]);
            }
        }
        memset(wei,0,sizeof(wei));
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<26;j++)
            {
                wei[i][j]=wei[i-1][j];
            }
            wei[i][b[i-1]-'a']=i;
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j]==0)
                {
                    f[i][j]=1;
                    continue;
                }
                if(dp[i-1][j]==dp[i][j])
                {
                    f[i][j]=(f[i][j]+f[i-1][j])%mod;
                }
                int p=wei[j][a[i-1]-'a'];
                if(p)
                {
                    if(dp[i-1][p-1]+1==dp[i][j])
                    {
                        f[i][j]=(f[i][j]+f[i-1][p-1])%mod;
                    }
                }
            }
        }
        printf("%I64d\n",f[n][m]);
    }
    return 0;
}
