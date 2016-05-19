#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10005;
const int maxm = 20005;

int fa[maxn];
int x[maxm], y[maxm];
char c[maxm];
vector<int> v[maxn];
int in[maxn];
int n, m, sum;

void init()
{
    sum = n;
    for (int i=0; i<n; i++)
    {
        fa[i] = i;
        v[i].clear();
        in[i] = 0;
    }
}

int find(int x)
{
    while (x != fa[x]) x = fa[x];
    return x;
}

int union_set(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return 0;
    fa[fx] = fy;
    return 1;
}

void bfs()
{
    queue<int> q;
    int i;
    for(i=0; i<n; i++)
    {
        if (in[i] == 0 && find(i) == i) 
            q.push(i);
    }
    int flag = 0;
    while (!q.empty())
    {
        if (q.size() > 1) flag = 1;
        int now = q.front();
        q.pop();
        sum --;
        for (i=0; i<v[now].size(); i++)
            if (--in[v[now][i]] == 0)
                q.push(v[now][i]);
    }
    if (sum > 0) puts("CONFLICT");
    else if (flag == 1) puts("UNCERTAIN");
    else puts("OK");
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int i;
        init();
        for (i=0; i<m; i++)
        {
            scanf("%d %c %d", &x[i], &c[i], &y[i]);
            if (c[i] == '=')
                if (union_set(x[i], y[i]))
                    sum --;
        }
        for (i=0; i<m; i++)
        {
            if (c[i] != '=')
            {
                int fx = find(x[i]);
                int fy = find(y[i]);

                if (c[i] == '>')
                {
                    v[fx].push_back(fy);
                    in[fy]++;
                }
                else
                {
                    v[fy].push_back(fx);
                    in[fx]++;
                }
            }
        }
        bfs();
    }
    return 0;
}