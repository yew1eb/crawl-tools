#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 2005;
const int maxm = 200005;
const int INF = 1e9;
int n, m, s, t;
int Mnlen, Mncost;

struct Edge{
    int v, w, c, next;
}edge[maxm];

int head[maxn], tot;

struct node{
    int len, cost;
}d[maxn];

bool vis[maxn];
queue<int> q;

void init(){
    tot = 0;
    memset(head, -1, sizeof head );
}

void addedge(int u, int v, int w, int c){
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].c = c;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void spfa(){
    while(!q.empty()) q.pop();
    for(int i=0; i<=n; ++i){
        d[i].len = d[i].cost = INF;
    }
    memset(vis, false, sizeof vis );
    q.push(s); vis[s] = true; d[s].len = d[s].cost = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i=head[u]; ~i; i=edge[i].next){
            int &v = edge[i].v;
            int &w = edge[i].w;
            int &c = edge[i].c;
            if(d[v].len>d[u].len + w || (d[v].len==d[u].len+w&&d[v].cost>d[u].cost + c)){
                d[v].len = d[u].len + w;
                d[v].cost = d[u].cost + c;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }    
        }
    }
    Mnlen = d[t].len;
    Mncost = d[t].cost;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        if(n==0&&m==0) break;
        init();
        int a, b, c, d;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d%d", &a, &b, &c, &d);
            a--; b--;
            addedge(a, b, c, d);
            addedge(b, a, c, d);
        }
        scanf("%d%d", &s, &t); s--; t--;
        spfa();
        printf("%d %d\n", Mnlen, Mncost);
    }
    return 0;
}











