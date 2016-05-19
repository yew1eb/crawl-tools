#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define maxn 250
#define maxe 100050
#define INF  0x3f3f3f
using namespace std;

int N,T;
int ans;
bool G[maxn][maxn];
int l[maxn];
int r[maxn];
int lhead,ltail,rhead,rtail;
int main()
{
    //freopen("input.txt","r",stdin); 
    int t=1;
    while(scanf("%d%d",&N,&T) && N + T){
        memset(G,0,sizeof(G));
        ans = 0;
        for(int i=1;i<=T;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            if(G[v][u] || u == v){
                ans++;
                continue;
            }
            G[u][v] = 1;
            lhead = ltail = rhead = rtail = 0;
            for(int i=1;i<=N;i++){
                if(G[i][u]) {G[i][v] = 1; l[ltail++] = i;}
                if(G[v][i]) {G[u][i] = 1; r[rtail++] = i;}        
            }
            for(int j=lhead;j<ltail;j++)
                   for(int k=rhead;k<rtail;k++){
                         G[l[j]][r[k]] = 1; 
                   }      
        }
        printf("%d. %d\n",t++,ans);
    }
}