#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 1002
#define maxm maxn * maxn
#define inf 0x3f3f3f3f
using std::queue;

int head[maxn], t[maxn], id;
struct Node{
    int to, w, next;
} E[maxm];
int dist[maxn], out[maxn], in[maxn];
bool vis[maxn];

void addEdge(int u, int v, int w)
{
    E[id].to = v; E[id].w = w;
    E[id].next = head[u]; head[u] = id++;
}

bool SPFA(int n)
{
    int i, u, v, tmp;
    for(i = 0; i <= n; ++i){
        vis[i] = out[i] = 0; dist[i] = -inf;
    }
    u = 0; vis[u] = 1; dist[u] = 0;
    queue<int> Q; Q.push(u);
    while(!Q.empty()){
        u = Q.front(); Q.pop(); vis[u] = 0;
        if(++out[u] > n) return false;
        for(i = head[u]; i != -1; i = E[i].next){
            tmp = dist[u] + E[i].w;
            v = E[i].to;
            if(tmp > dist[v]){
                dist[v] = tmp;
                if(!vis[v]){
                    vis[v] = 1; Q.push(v);
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, cas = 1, u, v, i;
    char str[5];
    while(scanf("%d", &n), n){
        for(i = 1; i <= n; ++i)
            scanf("%d", &t[i]);
        memset(head, -1, sizeof(head)); id = 0;
        while(scanf("%s", str), str[0] != '#'){
            scanf("%d%d", &u, &v);
            if(!strcmp(str, "SAS")) addEdge(v, u, 0);
            else if(!strcmp(str, "SAF")) addEdge(v, u, t[v]);
            else if(!strcmp(str, "FAS")) addEdge(v, u, -t[u]);
            else addEdge(v, u, t[v] - t[u]);
        }
        printf("Case %d:\n", cas++);
        for(i = 1; i <= n; ++i)
            addEdge(0, i, 0);
        if(!SPFA(n)){
            printf("impossible\n\n");
            continue;
        }
        for(i = 1; i <= n; ++i)
            printf("%d %d\n", i, dist[i]);
        printf("\n");
    }
    return 0;
}