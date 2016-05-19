#include<cstdio>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 99999999
int dp[(1<<21)+5],score[(1<<21)+5],g,b,s,x,y;
int bag[25][20];
void cal(){
    int sum[11];
    for(int i=0;i<(1<<b);++i){
        memset(sum,0,sizeof sum);
        for(int j=0;j<b;++j){
            if(i>>j&1){
                for(int k=1;k<=g;++k)sum[k]+=bag[j][k];
            }
        }
        for(int j=1;j<=g;++j)score[i]+=sum[j]/s;
    }
}

int dfs(int cur){
    if(dp[cur]!=-inf)return dp[cur];
    
    for(int j=0;j<b;++j)
        if(!(cur&(1<<j))){
            int res=score[cur|(1<<j)]-score[cur];
            if(res>0){
                dp[cur]=max(dp[cur],dfs(cur|(1<<j))+res);
            }else{
                dp[cur]=max(-dfs(cur|(1<<j)),dp[cur]);
            }
        }
    
    return dp[cur];
}

void solve(){
    memset(bag,0,sizeof bag);
    memset(score,0,sizeof score);
    for(int i=0;i<b;++i){
        scanf("%d",&x);
        while(x--){
            scanf("%d",&y);
            bag[i][y]++;
        }
    }
    cal();
    for(int i=0;i<(1<<b);++i)dp[i]=-inf;
    dp[(1<<b)-1]=0;
    printf("%d\n",dfs(0));
}
int main(){
    while(~scanf("%d%d%d",&g,&b,&s),g+b+s){
        solve();
    }
    return 0;
}
