#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 5e5+5;
int n;
int val[maxn];
int num[maxn], ans;

struct Edge{
    int to, next;
}edge[maxn];
int head[maxn], tot;
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int dfs(int u)
{
    if(num[u]) return num[u];
    num[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        num[u] += dfs(v);
        ans = max(ans, num[u]);
    }
    return num[u];
}

int main()
{
    //freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
            head[i] = -1;
            num[i] = 0;
        }

        tot = 0;
        int u, v;
        for(int i = 0; i < n-1; ++i) {
            scanf("%d %d", &u, &v);
            if(val[u] < val[v]) {
                addedge(u, v);
            }
            else {
                addedge(v, u);
            }
        }

        ans = 1;
        for(int i = 1; i <= n; ++i) {
            dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
