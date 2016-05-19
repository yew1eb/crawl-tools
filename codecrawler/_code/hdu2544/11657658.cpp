#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 105;
const int maxm = 20000;
const int INF = 1e9;
int n, m;

int head[maxn], tot;

struct Edge{
    int to, w, next;
}edge[maxm];

void init(){
    tot = 0;
    memset(head, -1, sizeof head );
}

void addedge(int u, int v, int w){
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int d[maxn];
bool vis[maxn];
queue<int> q;

int spfa(int n){
    int s = 0, tg = n-1;
    while(!q.empty()) q.pop();
    for(int i=0; i<=n; ++i) d[i] = INF;
    memset(vis, false, sizeof vis );
    q.push(s); d[s] = 0; vis[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i=head[u]; ~i; i=edge[i].next){
            int &v = edge[i].to;
            int &w = edge[i].w;
            if(d[v]>d[u] + w){
                d[v] = d[u] + w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d[tg];
};

int main()
{
    while(~scanf("%d%d", &n, &m)){
        if(n==0&&m==0) break;
        init();
        int a, b, c;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            addedge(a, b, c);
            addedge(b, a, c);
        }
        int ans = spfa(n);
        printf("%d\n", ans);
    }
    return 0;
}
