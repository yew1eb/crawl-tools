#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
const int maxn = 100005;
int T, n, m, x, y, sum, c[maxn], fa[maxn], dis[maxn], cnt[maxn][2];
bool flag;

int find(int x)
{
    if (x != fa[x]){
        int t = find(fa[x]);
        dis[x] = (dis[x] + dis[fa[x]]) & 1;
        fa[x] = t;
    }
    return fa[x];
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
    {
        if (dis[x] == dis[y]) flag = 0;
        return;
    }
    fa[fx] = fy;
    dis[fx] = (1 + dis[x] + dis[y]) & 1;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(dis, 0, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        flag = true;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        sum = 0;    
        for (int i = 1; i <= n&&flag; i++) cnt[find(i)][dis[i]]++;
        for (int i = 1; i <= n&&flag; i++) sum += max(cnt[i][0], cnt[i][1]);
        if (flag&&n > 1)
        {
            if (sum == n) sum = n - 1;
            printf("%d %d\n", sum, n - sum);
        }
        else printf("Poor wyh\n");
    }
    return 0;
}