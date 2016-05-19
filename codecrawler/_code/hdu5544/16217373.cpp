#include <bits/stdc++.h>
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)

using namespace std;

const int maxn = 50050;
const int maxm = 100010;

int head[maxn],edge_cnt,n,m,tot;

struct Edge{
    int u,v;
    LL val;
    int nt;
}edge[maxm<<1];

void addedge(int u,int v,LL val){
    edge[edge_cnt].u = u;
    edge[edge_cnt].v = v;
    edge[edge_cnt].val = val;
    edge[edge_cnt].nt = head[u];
    head[u] = edge_cnt++;
}

void Build_Graph(){
    memset(head,-1,sizeof(head));
    edge_cnt = 0;
    scanf("%d%d",&n,&m);
    FOR(i,0,m){
        int u,v;    LL val;
        scanf("%d%d%I64d",&u,&v,&val);
        addedge(u,v,val);
        addedge(v,u,val);
    }
}

LL val[maxm<<1];
LL d[maxn];
bool vis[maxn];

void dfs(int u,int fa){
    vis[u] = true;
    for(int i = head[u];i != -1;i = edge[i].nt){
        int v = edge[i].v;
        if(v == fa)  continue;
        if(!vis[v]){
            d[v] = d[u] ^ edge[i].val;
            dfs(v,u);
        }
        else{
            val[tot++] = d[u]^d[v]^edge[i].val;
        }
    }
}

int xorguass(int n){
    int row = 0;
    for(int i = 60;i >= 0;-- i){
        int j;
        for(j = row;j < n;++ j){
            if(val[j] & (1LL<<i))   break;
        }
        if(j != n){
            swap(val[j],val[row]);
            for(j = 0;j < n;++ j){
                if(j == row)    continue;
                if(val[j] & (1LL<<i))   val[j] ^= val[row];
            }
            ++ row;
        }
    }
    return row;
}

void work(){
    memset(vis,false,sizeof(vis));
    tot = 0;
    d[1] = 0;
    dfs(1,-1);
    n = xorguass(tot);
    LL ans  = 0;
    FOR(i,0,n)  ans ^= val[i];
    printf("%I64d\n",ans);
}

int main()
{
    //freopen("test.in","r",stdin);
    int T,tCase = 0;    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++tCase);
        Build_Graph();
        work();
    }
    return 0;
}
