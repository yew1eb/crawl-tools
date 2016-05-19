#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=1597+10;
int n,nowsize,lastsize;
int now[MAX],last[MAX];
int dp[MAX],temp[MAX],ans[MAX];
int w[16][16];
char s[MAX];

void dfs(int id,int k,int p,int sum){
    if(k>=n){now[++nowsize]=p;ans[nowsize]=sum;return;}
    dfs(id,k+2,p|(1<<k),sum+w[id][k]);
    dfs(id,k+1,p,sum);
}

void DP(){
    for(int k=1;k<=n;++k){
        nowsize=0;
        dfs(k,0,0,0);
        for(int i=1;i<=nowsize;++i)dp[i]=0;
        for(int i=1;i<=nowsize;++i){
            for(int j=1;j<=lastsize;++j){
                if(now[i] & last[j])continue;
                if(now[i] & (last[j]<<1))continue;
                if(now[i] & (last[j]>>1))continue;
                dp[i]=max(dp[i],temp[j]+ans[i]);
            }
        }
        for(int i=1;i<=nowsize;++i)temp[i]=dp[i];
        for(int i=1;i<=nowsize;++i)last[i]=now[i];
        lastsize=nowsize;
    }
}

int main(){
    int k;
    while(gets(s)){
        k=1;
        do{
            n=0;
            stringstream ss(s);
            while(ss>>w[k][n])++n;
            gets(s);
            if(s[0] == '\0')break;
            ++k;
        }while(true);
        n=k;
        temp[1]=last[1]=0;
        lastsize=1;
        DP();
        int sum=0;
        for(int i=1;i<=lastsize;++i)sum=max(sum,temp[i]);
        printf("%d\n",sum);
    }
    return 0;
}