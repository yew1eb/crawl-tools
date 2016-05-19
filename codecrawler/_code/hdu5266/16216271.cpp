#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
const int maxn = 300005;
int n, m, x, y, lc[maxn][20], dp[maxn][20], deep[maxn];
vector<int> t[maxn];

void bfs()
{
    queue<int> p;
    p.push(1);    deep[1] = 1;
    while (!p.empty())
    {
        int q = p.front();    p.pop();
        for (int i = 0; i < t[q].size(); i++)
        if (t[q][i] != lc[q][0])
        {
            lc[t[q][i]][0] = q;
            deep[t[q][i]] = deep[q] + 1;
            p.push(t[q][i]);
        }
    }
}

int lca(int a, int b)
{
    int i, j;
    if (deep[a]<deep[b]) swap(a, b);
    for (i = 0; (1 << i) <= deep[a]; i++);
    i--;
    for (j = i; j >= 0; j--)
        if (deep[a] - (1 << j) >= deep[b])
            a = lc[a][j];
    if (a == b)return a;
    for (j = i; j >= 0; j--)
    {
        if (lc[a][j] != -1 && lc[a][j] != lc[b][j])
        {
            a = lc[a][j];
            b = lc[b][j];
        }
    }
    return lc[a][0];
}

int query(int s, int v)
{
    int k = (int)(log((v - s + 1)*1.0) / log(2.0));
    return lca(dp[s][k], dp[v - (1 << k) + 1][k]);
}

int main()
{
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        memset(lc, -1, sizeof(lc));
        for (int i = 1; i <= n; i++) 
        { 
            t[i].clear(); 
            dp[i][0] = i; 
            deep[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            t[x].push_back(y); 
            t[y].push_back(x);
        }
        bfs();
        
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i <= n; i++)
                if (lc[i][j - 1] != -1) lc[i][j] = lc[lc[i][j - 1]][j - 1];
        
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i <= n; i++)
            if (i + (1 << j) - 1 <= n)
            {
                dp[i][j] = lca(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }

        cin >> m;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", query(x, y));
        }
    }
}