#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int maxm = 10005;
const int INF = 1e9;

int head[maxn], tot;
int n, m;
struct Edge{
    int to, w, next;
}edge[maxm];

void addedge(int u, int v, int w){
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void init(){
    tot = 0;
    memset(head, -1, sizeof head );
    int u, v, w;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
}

int d[maxn];
bool vis[maxn];
queue<int> q;

int spfa(){
    while(!q.empty()) q.pop();
    for(int i=1; i<=n; ++i) d[i] = INF;
    d[1] = 0;
    memset(vis, 0, sizeof vis );
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(int i=head[u]; ~i; i=edge[i].next){
            int &v = edge[i].to;
            int &w = edge[i].w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return d[n];
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp", "w", stdout);
#endif
    while(~scanf("%d%d", &n, &m)) {
        if(n==0&&m==0) break;
        init();
        printf("%d\n", spfa());
    }
    return 0;
}



















