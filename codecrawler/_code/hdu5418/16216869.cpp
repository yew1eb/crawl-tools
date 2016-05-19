#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define INF 0x2fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
#define maxn 17
int dp[1<<maxn][maxn];//dp[s][v] sçç¶æå°v ç»æ 
int n,m;
int d[100][100];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(d,0x3f3f3f3f,sizeof(d));
        for(int i = 0;i < m;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            x--;
            y--;
            d[x][y]=min(d[x][y],w);
            d[y][x]=min(d[y][x],w);
        }
        for(int i = 0;i < n;i++){
            d[i][i] = 0;
        }
        for(int k = 0;k < n;k++){
            for(int i = 0; i < n;i++){
                for(int j = 0;j < n;j++){
                    d[i][j] = min(d[i][k]+d[k][j],d[i][j]); 
                }
            }
        }
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0][0] = 0;
        for(int s = 0; s < (1<<n);s++){
            for(int v = 0;v < n;v++){
                if((dp[s][v]!=0x3f3f3f3f)) {
                    for(int u = 0;u < n;u ++)
                        dp[s|(1<<u)][u] = min(dp[s|(1<<u)][u],dp[s][v] + d[v][u]);
                    }
            } 
        } 
        printf("%d\n",dp[(1<<n)-1][0]);
    } 
    return 0;
}
