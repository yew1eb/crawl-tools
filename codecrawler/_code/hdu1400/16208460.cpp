#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

long long dp[2][2500], ans[15][15];
int p2[15];

int check(int x){       
    while(x){
        if(x&1){
            x>>=1;
            if(!(x&1))
            return 0;
            x>>=1;
        }
        else x>>=1;
    }
    return 1;
}

void dfs(int x, int y, long long d, int l){
    if(y>l-2)return ;
    if((x&p2[y])==0 && (x&p2[y+1])==0){
        dp[1][x+p2[y]+p2[y+1]]+=d;
        dfs(x+p2[y]+p2[y+1], y+2, d, l);
    }
    dfs(x, y+1, d, l);
}

void init(){
    int i, j, k, p;
    for(i=0; i<11; i++){
        p2[i]=1<<i;
    }
    for(i=1; i<=11; i++){
        ans[i][1]=!(i&1);
        for(j=0; j<p2[i]; j++)
        dp[0][j]=check(j);
        for(j=2; j<=11; j++){
            memset(dp[1], 0, sizeof(dp[1]));
            for(k=0; k<p2[i]; k++){
                if(dp[0][k]==0)continue;
                int t=k, tmp=0;
                for(p=0; p<i; p++, t>>=1){
                    if(!(t&1)){
                        tmp+=p2[p];
                    }
                }
                dp[1][tmp]+=dp[0][k];
                dfs(tmp, 0, dp[0][k], i);
            }
            memcpy(dp[0], dp[1], sizeof(dp[1]));
            ans[i][j]=dp[0][p2[i]-1];
        }
    }
}

int main(){
    //freopen("1.txt", "r", stdin);
    init();
    int h, w;
    while(scanf("%d%d", &h, &w)&&h){
        if(h>w)swap(h, w);
        printf("%lld\n", ans[h][w]);
    }
    return 0;
}


