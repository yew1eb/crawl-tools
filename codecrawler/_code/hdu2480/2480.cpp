#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int maxn = 1000 + 5;
const int INF = 1000000000;

struct Edge{
    int from,to,d,w;
}e[maxn*maxn];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int vis[maxn];
int fa[maxn];

int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i = 0;i < m;i++){
            scanf("%d%d%d%d",&e[i].from,&e[i].to,&e[i].d,&e[i].w);
        }
        sort(e,e+m,cmp);
        memset(vis,0,sizeof(vis));
        for(int i = 0;i <= n;i++) fa[i] = i;
        int ans = 0;
        for(int i = m-1;i >= 0;i--){
            int x = Find(e[i].from);
            int y = Find(e[i].to);
            if(vis[x] && vis[y]) continue;
            else if(e[i].d == 1 && vis[x]) continue;
            ans += e[i].w;
            if(e[i].d == 1) vis[x] = 1;
            else{
                if(x == y) vis[x] = 1;
                if(vis[x] == 0 && vis[y] == 0 ) fa[x] = y;
                else if(vis[x] == 1) vis[y] = 1;
                else if(vis[y] == 1) vis[x] = 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}