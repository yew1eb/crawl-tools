#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20005, maxm = 200005;
int n, m;

struct Edge
{
    int to, nxt;
} edge[maxm];
int tol, head[maxn];

void addedge(int u, int v)
{
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

bool vis[maxn];
int cnt[maxn][2];
int el, ans;
bitset<maxn> dp;

void dfs(int u, int col)
{
    if(col==0) cnt[el][0]++;
    else cnt[el][1]++;
    vis[u] = 1;
    for(int i=head[u]; ~i; i=edge[i].nxt) if(!vis[edge[i].to]){
        dfs(edge[i].to, col^1);
    }
}
void solve()
{
    memset(vis, 0, sizeof vis );
    el = 0;
    for(int i=1; i<=n; ++i) if(!vis[i])
        {
            cnt[el][0] = cnt[el][1] = 0;
            dfs(i, 0);
            el++;
            //cout<<cnt[el-1][0]<<","<<cnt[el-1][1]<<endl;
        }
    dp.reset();
    dp[0] = 1;
    for(int i=0; i<el; ++i) {
        dp=(dp<<cnt[i][0])|(dp<<cnt[i][1]);
    }

    ans = 0;
    for(int i=1; i<n; ++i) if(dp[i]) {
        ans = max(ans, i*(n-i) - m);
    }
    printf("%d\n",ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    int u, v;
    while(T--)
    {
        scanf("%d%d", &n, &m);
        tol = 0;
        for(int i=0; i<=n; ++i) head[i] = -1;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        solve();
    }
    return 0;
}
