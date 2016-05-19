#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
const int MAX_N = 10000 + 100;
const int MAX_M = 100000 + 100;
int p[MAX_N];
int _find(int x)
{
    return p[x] == x ? x : (p[x] = _find(p[x]));
}
int n, m;
stack <int> s;
struct Edge
{
    int u, v;
};
Edge edge[MAX_M];
int res[MAX_M];

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            p[i] = i;
        for(int i = 0; i < m; i++)
            scanf("%d%d", &edge[i].u, &edge[i].v);
        res[m - 1] = n;
        for(int i = m - 1; i > 0; i--)
        {
            int a = _find(edge[i].u);
            int b = _find(edge[i].v);
            if(a != b)
            {
                p[a] = b;
                res[i - 1] = res[i] - 1;
            }
            else
                res[i - 1] = res[i];
        }
        for(int i = 0; i < m; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}
