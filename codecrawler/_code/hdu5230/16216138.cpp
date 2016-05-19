#include <stdio.h>
#include <string.h>
#define ll long long
#define maxn 500
#define maxm 100010
#define mod 998244353
ll dp[maxm][2],ans[maxm];
void work()
{
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    int now=1;
    dp[1][now]=1;
    for(int i=1;i<maxn;i++)       //æ³¨æè¿éçå¾ªç¯é¡ºåºä¸è½é
    {
        for(int j=1;j<maxm;j++)
        {
            if(j+i<maxm)dp[j+i][now]=(dp[j+i][now]+dp[j][now])%mod;
            if(i+j+1<maxm)dp[j+i+1][!now]=(dp[i+j+1][!now]+dp[j][now]);
            ans[j]=(ans[j]+dp[j][now])%mod;
            dp[j][now]=0;
        }
        now=!now;
    }
    
    for(int i=1;i<maxm;i++)
        ans[i]=(ans[i]+ans[i-1])%mod;
}
int main()
{
    int T;
    scanf("%d",&T);
    work();
    int n,c,l,r;
    while(T--)
    {
        scanf("%d%d%d%d",&n,&c,&l,&r);
        l-=c,r-=c;
        ll ret=0;
        //if(l==0&&r==0) {printf("1\n");continue;}
        if(l==0) ret=(ans[r]+1)%mod;   //å¦æl=0ï¼é£ä¹è¿æä¸ç§éæ©å°±æ¯ä»ä¹é½ä¸éã
        else ret=(ans[r]-ans[l-1]+mod)%mod;   //åæ¨¡ç¢°å°åæ³ä¸å®è¦æ³¨ææ¯å¦å°äºé¶äº
       
        printf("%lld\n",ret);
    }
    return 0;
}