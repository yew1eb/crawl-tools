#include<cstdio>
#define maxn 2048
#define ll long long
int dp[maxn][maxn],mod=1000000007; //æ®è¯´int å­å¨æ¯longlongå¿«
int po[maxn];
int main(){
    int t,m,n;
    //freopen("1010.in","r",stdin);
    //freopen("10101.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        dp[1][0] = 0; //åå§è¯dp[1],ä»¥ååé¢ç´æ¥è®¡ç®dp[n]é½æ¯ä¸ºäºåå°è®¡ç®ï¼æ¯ç«1000ç»caseï¼
        dp[1][1] = m;
        po[0] = 1;
        for(int i = 1;i <= n;i++){
            po[i] = (ll)po[i-1]*m%mod;
        }
        int j;
        for(int i = 2;i < n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][i] = (ll)dp[i-1][i-1]*(m-i+1) % mod ;
            if(i & 1) j = 1;
            else j = 2;  //ä¸ºäºåå°2çå¸¸æ°å¤æåº¦
            for(;j < i; j+=2)
                dp[i][j] = ((ll)dp[i-1][j-1]*(m-j+1)+(ll)dp[i-1][j+1]*(j+1))%mod;
        }
        if(n>1)dp[n][0] = dp[n-1][1];
        if(n>1)dp[n][1] = ((ll)dp[n-1][0] * m + (ll)dp[n-1][2] * 2)% mod;
        int ans = 0;
        for(int i = 1;i <= n; i++){
            ans = (ans+(ll)dp[i][i&1]*(n-i+1)%mod*po[n-i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}





