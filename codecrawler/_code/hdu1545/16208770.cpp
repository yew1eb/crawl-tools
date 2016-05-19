#include<cstdio>
#include<cstring>
#define ll __int64
const int W=5;
int n,k;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
ll dp[63][10][10];
int main(){
    int i,j,p;
    while(~scanf("%d%d",&n,&k)){
        memset(dp,0,sizeof(dp));
        dp[0][W][W]=1;
        for(i=0;i<n;i++){
            for(j=-k+W;j<=W;j++)for(p=W;p<=k+W;p++){
                dp[i+1][min(j+1,W)][p+1]+=dp[i][j][p];
                dp[i+1][j-1][max(p-1,W)]+=dp[i][j][p];
            }
        }
        ll ans=0;
        for(i=-k+W;i<=W;i++)for(j=W;j<=k+W;j++)ans+=dp[n][i][j];
        printf("%I64d\n",ans);
    }
    return 0;
}