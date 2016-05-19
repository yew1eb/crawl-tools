#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define max(a,b)    ((a)>(b)?(a):(b))
const int maxn = 505;

struct Node
{
    int p, q, v;
}node[maxn];

int cmp(Node a, Node b)
{
    return a.q-a.p < b.q-b.p;
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int dp[5005];
        int i, j;
        for (i=0; i<n; i++) scanf("%d %d %d", &node[i].p, &node[i].q, &node[i].v);
        memset(dp, 0, (m+1)*sizeof(dp[0]));
        sort(node, node+n, cmp);
        for (i=0; i<n; i++)
        {
            for (j=m; j>=node[i].q; j--)
            {
                dp[j] = max(dp[j], dp[j-node[i].p] + node[i].v);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}