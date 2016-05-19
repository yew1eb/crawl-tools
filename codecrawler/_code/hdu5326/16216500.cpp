#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
const int N=105;
const int MAXN=(1<<31)-1;
int INF=0x7f7f7f7f;
int T,n,m,k,tot;
const int MOD=1e9+7;
int cas=1;
vector<int> G[N];
int in[N];
bool vis[N];
int sub[N];
void init(){
    for(int i=0;i<N;i++) G[i].clear();
    memset(in,0,sizeof in);
}

void dfs(int rt){
     sub[rt]=1;
     for(int i=0;i<G[rt].size();i++){
          int u=G[rt][i];
          dfs(u);
          sub[rt]+=sub[u];
     }
}
int main()
{
#ifndef  ONLINE_JUDGE
   freopen("aaa","r",stdin);
#endif
   while(~scanf("%d%d",&n,&k)){
        init();
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            in[v]++;
        }
        int root=1;
        for(;root<=n;root++) {
            if(in[root]==0) break;
        }
        dfs(root);
        int sum=0;
        for(int i=1;i<=n;i++) if(sub[i]==k+1)  sum++;
        printf("%d\n",sum);
   }


    return 0;
}
