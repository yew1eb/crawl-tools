#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxm = 1005;
const int maxn = 40;
const ll inf = ll (1e16);

ll g[maxn][maxn], d[maxn][maxn];
int n, m;
bool vis[maxn];
ll ans;

void floyd(){
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[j][i] = d[i][j] = d[i][k] + d[k][j];
            }
        }
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        if(n==0&&m==0) break;
        for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) g[i][j] = inf;
        int u, v; ll c;
        for(int i=0; i<m; ++i) {
            scanf("%d%d%I64d", &u, &v, &c);
            if(g[u][v]>c) g[u][v] = g[v][u] = c;
        }
        ans=0;
        if(n<3){
            if(n>1)ans=g[1][n];
            else ans=0;
        }
        for(int i=2; i<n; ++i){
            memcpy(d, g, sizeof g );
            for(int j=1; j<=n; ++j) d[i][j] = d[j][i] = inf;
            floyd();
            if(ans<d[1][n])ans = d[1][n];
        }
        if(ans<inf) printf("%I64d\n", ans);
        else printf("Inf\n");
    }
    return 0;
}