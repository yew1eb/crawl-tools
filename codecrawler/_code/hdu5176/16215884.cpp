/*************************************************************************
    > File Name: bc-30c.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015å¹´02æ14æ¥ ææå­ 21æ¶07å25ç§
 ************************************************************************/

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef unsigned long long LL;
typedef pair <int, int> PLL;

const int N = 150010;
int father[N];
LL num[N];

struct node
{
    int u, v;
    LL w;
}edge[N];

int cmp1 (node a, node b)
{
    return a.w < b.w;
}

int cmp2 (node a, node b)
{
    return a.w > b.w;
}

int find (int x)
{
    if (father[x] == -1)
    {
        return x;
    }
    return father[x] = find (father[x]);
}

int main ()
{
    int n;
    int icase = 1;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n - 1; ++i)
        {
            father[i] = -1;
            num[i] = 1;
            scanf("%d%d%llu", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        father[n] = -1;
        num[n] = 1;
        sort (edge + 1, edge + n, cmp1);
        LL ans = 0;
        for (int i = 1; i < n; ++i)
        {
            int u = find (edge[i].u);
            int v = find (edge[i].v);
            ans += edge[i].w * num[u] * num[v];
            num[u] += num[v];
            father[v] = u;
        }
        for (int i = 1; i <= n; ++i)
        {
            father[i] = -1;
            num[i] = 1;
        }
        sort (edge + 1, edge + n, cmp2);
        for (int i = 1; i < n; ++i)
        {
            int u = find (edge[i].u);
            int v = find (edge[i].v);
            ans -= edge[i].w * num[u] * num[v];
            num[u] += num[v];
            father[v] = u;
        }
        printf("Case #%d: %llu\n", icase++, ans);
    }
    return 0;
}