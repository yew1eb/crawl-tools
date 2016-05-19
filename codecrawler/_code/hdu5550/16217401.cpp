#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define inf 0x7fffffff
#define maxn 4050
ll a[maxn],b[maxn];
ll sum[maxn][2];//sum[i][u]è¡¨ç¤ºåiå±æ¥¼ï¼æ§å«ä¸ºuçæ»äººæ°
ll dsum[maxn][2];//dsum[i][u]è¡¨ç¤ºåiå±æ¥¼ï¼æ§å«ä¸ºuèè·ç¦»0å±çè·ç¦»ä¹å
ll dp[maxn][2];//dp[i][u]è¡¨ç¤ºç¬¬iå±ä¸ºuå±æ§ï¼ç¬¬i+1å±ä¸ºå¦ä¸å±æ§ï¼åiå±ä¸åæ§å«å°è¾¾èªå·±çæè¿å±æ§çå¯å®¤çæè¿è·ç¦»å

ll goup(int l,int r,int sex){   //è¡¨ç¤º[l+1,r]åºé´sexæ§å«è¦å»r+1çæ»è·ç¦»
    return (sum[r][sex]-sum[l][sex])*(r+1)-(dsum[r][sex]-dsum[l][sex]);
}

ll godown(int l,int r,int sex){  //è¡¨ç¤º[l+1,r]åºé´sexæ§å«è¦å»lçæ»è·ç¦»
    return dsum[r][sex]-dsum[l][sex]-(sum[r][sex]-sum[l][sex])*l;
}

ll cnt(int l,int r,int sex){   //å¨[l,r]é½æ¯sexå±æ§ï¼ä¸l-1ä¸r+1é½ä¸ºésexå±æ§çæ¡ä»¶ä¸ã [l,r]è¿äºæ¥¼å±ésexå±æ§çäººï¼å»èªå·±å±æ§å¯å®¤çæå°è·ç¦»ã
    int mid=(l+r)>>1;
    return godown(l-1,mid,sex)+goup(mid,r,sex);
}
int main()
{
    int n,m,i,j,T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum[0][0]=sum[0][1]=0;
        dsum[0][0]=dsum[0][1]=0;
        for(i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
            sum[i][0]=sum[i-1][0]+a[i];
            sum[i][1]=sum[i-1][1]+b[i];
            dsum[i][0]=dsum[i-1][0]+a[i]*i;
            dsum[i][1]=dsum[i-1][1]+b[i]*i;
        }
        memset(dp,0,sizeof(dp));
        ll ans=1e18;
        for(i=1;i<n;i++){
            dp[i][0]=goup(0,i,1);  //è¿éååè®¾åiå±é½æ¯æ§å«0ï¼i+1å±æ¯æ§å«1æè¦çæ»è·ç¦»
            dp[i][1]=goup(0,i,0);
            for(j=1;j<i;j++){
                dp[i][0]=min(dp[i][0],dp[j][1]+cnt(j+1,i,1)   ); //ä¾æ¬¡ä½¿å¾åjå±æ¯1ï¼ä½¿å¾ç¬¬j,i+1é½æ¯1ï¼è¿æ ·å°±å¥½ç¶æè½¬ç§»äº
                dp[i][1]=min(dp[i][1],dp[j][0]+cnt(j+1,i,0)   );
            }
            ans=min(ans,dp[i][0]+godown(i,n,0)  ); //è¿éæ¯ä¸å±é½è¦æ´æ°ä¸ä¸ansï¼èä¸è½æåææ´æ°ï¼å ä¸ºæåææ´æ°çè¯å°±ä¸è½ä½¿å¾åé¢å å±é½ç¸åäº
            ans=min(ans,dp[i][1]+godown(i,n,1)  );
        }
        cas++;
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
