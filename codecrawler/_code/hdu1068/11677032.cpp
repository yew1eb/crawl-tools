#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int g[maxn][maxn];
int n;
int link[maxn];
bool used[maxn];
bool dfs(int u)
{
    for(int v=0; v<n; ++v)
        if(g[u][v]&&!used[v]) {
            used[v] = true;
            if( link[v]==-1 || dfs(link[v])) {
                link[v] = u;
                return true;
            }
        }
    return false;
}

int hungary()
{
    int res = 0;
    memset(link, -1, sizeof link );
    for(int i=0; i<n; ++i) {
        memset(used, 0, sizeof used );
        if(dfs(i)) res++;
    }
    return res;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp", "w", stdout);
#endif
    int num, u, v;
    while(~scanf("%d", &n)) {
        memset(g, 0, sizeof g );
        for(int i=1; i<=n; ++i) {
            scanf("%d: (%d)", &u, &num);
            for(int j=0; j<num; ++j) {
                scanf("%d", &v);
                g[u][v] = 1;
            }
        }

        int cnt = hungary();
        printf("%d\n", n-cnt/2);
    }
    return 0;
}



















