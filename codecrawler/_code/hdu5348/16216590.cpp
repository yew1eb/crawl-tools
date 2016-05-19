#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e5+10;

int head[maxn],in[maxn],out[maxn],tot[maxn];

bool vis[maxn*6];

struct nod {
    int to,next;
} edge[6*maxn];

int n,m,ip;

int ans[maxn*6];

void init(){
    ip=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(tot,0,sizeof(tot));
}

void add(int u,int v) {
    edge[ip].to = v ;
    edge[ip].next = head[u] ;
    head[u] = ip++ ;
}

void dfs_in(int u) {
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        if(vis[i]) {
            head[u]=edge[i].next;
            continue;
        }
        int v=edge[i].to;
        if(u!=v && out[v]>in[v]) continue;
        vis[i]=1,vis[i^1]=1; //æ è®°ï¼å è¾¹
        head[u] = edge[i].next;
        in[u]++,out[v]++;
        if(i%2) ans[i/2] = 1;
        else ans[i/2] = 0;
        dfs_in(v);
        return;
    }
}

void dfs_out(int u) {
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        if(vis[i]) {
            head[u]=edge[i].next;
            continue;
        }
        int v=edge[i].to;
        if(u!=v && in[v]>out[v]) continue;
        vis[i]=1,vis[i^1]=1; //æ è®°ï¼å è¾¹
        head[u] = edge[i].next;
        in[v]++,out[u]++;
        if(i%2) ans[i/2] = 0;
        else ans[i/2] = 1;
        dfs_out(v);
        return ;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        init();
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v),add(v,u);
            tot[u]++,tot[v]++;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++) {
            while(out[i]+in[i]<tot[i]) {
                if(out[i]>in[i]) dfs_in(i);
                else dfs_out(i);
            }
        }
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
