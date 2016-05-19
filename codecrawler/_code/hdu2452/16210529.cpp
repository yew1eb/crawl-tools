#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#define INF 0x7fffffff
#define MOD 1000000007
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 10005;
int n, m, f, s;
int in[MAXN], a[MAXN], dp[5][MAXN];
vector<int> G[MAXN];

void dfs(int u)
{
    if(dp[0][u] >= 0) return;
    if(!G[u].size())
    {
        dp[0][u] = dp[1][u] = a[u];
        return;
    }
    dp[0][u] = INF; dp[1][u] = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        dp[0][u] = min(a[u] + dp[1][v], dp[0][u]);
        dp[1][u] = max(a[u] + dp[0][v], dp[1][u]);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif

    int u, v;
    while(~scanf("%d%d%d", &n, &m, &f))
    {

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            G[i].clear();
        }
        memset(in, 0, sizeof(in));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            in[v]++;
        }
        for(int i = 1; i <= n; i++)
            if(!in[i])
            {
                s = i; break;
            }
        memset(dp, -1, sizeof(dp));
        dfs(s);
        if(dp[1][s] >= f)
            printf("Victory\n");
        else
            printf("Glory\n");
    }

    return 0;
}