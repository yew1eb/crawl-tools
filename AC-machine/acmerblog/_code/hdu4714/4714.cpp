#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int V = 1000000 + 50;
int pnt[V * 2], nxt[V * 2], head[V * 2], e;
int T, n, ans;
bool vis[V];
inline void addedge(int u, int v) {
    pnt[e] = v;
    nxt[e] = head[u];
    head[u] = e++;
}
bool dfs(int u) { //返回是否还是还是u的儿子。
    int sum = 0;
    vis[u] = true;
    for(int i = head[u]; i != -1; i = nxt[i])
        if(!vis[pnt[i]])
            sum += dfs(pnt[i]);
    if(sum >= 2) {
        if(u == 1) //如果是根节点
            ans += 2 * (sum - 2);
        else
            ans += 2 * (sum - 1);
        return false;
    }
    else
        return true;
}
int main() {
    int i, j, k;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        e = ans = 0;
        memset(head, -1, sizeof(head));
        memset(vis, false, sizeof(vis));
        for(i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        dfs(1);
        printf("%d\n", ans + 1);
    }
}
