#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#pragma comment(linker,"/STACK:102400000,102400000")

const int MX = 100000 + 5;
const int INF = 0x3f3f3f3f;

int vis[MX];
vector<int>G[MX];

bool DFS(int u, int c, int &a, int &b) {
    b++;
    if(c) a++;

    vis[u] = c;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(vis[v] == c) return false;
        if(vis[v] == -1 && !DFS(v, c ^ 1, a, b)) return false;
    }
    return true;
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        memset(vis, -1, sizeof(vis));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            G[i].clear();
        }

        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(n <= 1) {
            printf("Poor wyh\n");
            continue;
        }
        if(m == 0) {
            printf("%d 1\n", n - 1);
            continue;
        }

        bool sign = true;
        int Max = 0;
        for(int i = 1; i <= n; i++) {
            int a = 0, b = 0;
            if(vis[i] == -1) {
                if(!DFS(i, 0, a, b)) {
                    sign = false;
                    break;
                }

                Max += max(a, b - a);
            }
        }

        if(!sign) printf("Poor wyh\n");
        else {
            printf("%d %d\n", Max, n - Max);
        }
    }
    return 0;
}
