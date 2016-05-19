#include <iostream>
#include <string.h>
using namespace std;
int a[1002];
long long dp1[1002],dp2[1002];
int main()
{
    int t,n,p;
    long long ans;
    scanf("%d",&t);
    while (t--)
    {
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        ans=-1000000000000;
        scanf("%d%d",&n,&p);
        for (int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        dp2[0]=dp2[n+1]=dp1[0]=dp1[n+1]=0;
        for (int i=1; i<=n; i++)
            dp1[i]=max(dp1[i-1]+a[i],(long long)a[i]);
        for (int i=n; i>0; i--)
            dp2[i]=max(dp2[i+1]+a[i],(long long)a[i]);
        for (int i=1; i<=n; i++)
        {
            ans=max(ans,max(dp1[i-1], (long long)0)+max(dp2[i+1],(long long)0)+p); //åå«å¨å¶ä¸­
            
            //ä¸åå«å¨å¶ä¸­ï¼åå°±èå¼a[i]ï¼æ¯è¾a[i]ä¸¤è¾¹çåºåï¼å½ç¶ç»æå¯è½ä¸ºè´ï¼æä»¥ä¸è½åæ¬dp1[0]ï¼dp2[n+1],å ä¸ºè¿ä¸¤èå¨åé¢åå§åä¸º0
            if(i!=1)
                ans=max(ans,dp1[i-1]);
            if (i!=n)
                ans=max(ans,dp2[i+1]);
        }
        printf("%lld\n",ans);
        
    }
    return 0;
}
