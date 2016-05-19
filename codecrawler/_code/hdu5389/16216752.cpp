#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;

const int MAXN=100010;
const LL MOD= 258280327;

int T,N,A,B;
int a[MAXN],sum[MAXN];
LL dp[2][10][10];

int cal(int i,int j){
    if(j>i) return j-i;
    return 9-(i-j);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&A,&B);
        memset(dp,0,sizeof(dp));
        sum[0]=0;
        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            if(sum[i]>=10) sum[i]-=9;
        }
        int cur=0;
        dp[cur][a[1]][0]=1;
        dp[cur][0][a[1]]=1;
        for(int i=2;i<=N;i++){
            cur=!cur;
            memset(dp[cur],0,sizeof(dp[cur]));
            for(int j=0;j<=9;j++){
                int k;
                if(j==0) k=sum[i];
                else k=cal(j,sum[i]);
                if(j==a[i]) dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][0][k])%MOD;
                if(k==a[i]) dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][j][0])%MOD;
                if(j>0){
                    int t=cal(a[i],j);
                    dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][t][k])%MOD;
                }
                if(k>0){
                    int t=cal(a[i],k);
                    dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][j][t])%MOD;
                }
                //j==sum[i]æ¶kå¯è½ä¸º0
                if(j==sum[i]){
                    k=0;
                    if(j==a[i]) dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][0][k])%MOD;
                    if(k==a[i]) dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][j][0])%MOD;
                    if(j>0){
                        int t=cal(a[i],j);
                        dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][t][k])%MOD;
                    }
                    if(k>0){
                        int t=cal(a[i],k);
                        dp[cur][j][k]=(dp[cur][j][k]+dp[!cur][j][t])%MOD;
                    }
                }
            }
        }
        LL ans=(dp[cur][A][0]+dp[cur][0][B]+dp[cur][A][B])%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}