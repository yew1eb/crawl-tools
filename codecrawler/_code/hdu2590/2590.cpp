#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int MAXM = 1005;
const int MAXD = 6000005;

struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    inline void inputd()
    {
        input();
        -- x;
        -- y;
    }
} s1, s2, point[MAXN], hat[MAXM], fri[MAXM];

struct Edge
{
    int v, next;
} edge[MAXN * MAXN * 4];
int head[MAXN * 2], edgeNumber;
int n, a, b, ans;
int stack[MAXN * 2], top, timeStamp;
int dfn[MAXN * 2], low[MAXN * 2];
int belong[MAXN * 2], belongNumber;
bool visit[MAXN * 2];

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline int dist(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int dist(const int &a, const Point &b)
{
    return dist(point[a], b);
}

inline int dist(const Point &a, const int &b)
{
    return dist(a, point[b]);
}

void input()
{
    s1.input();
    s2.input();
    for(int i=0;i<n;++i)
    {
        point[i].input();
    }
    for(int i=0;i<a;++i)
    {
        hat[i].inputd();
    }
    for(int i=0;i<b;++i)
    {
        fri[i].inputd();
    }
}

inline void setAnswer(const int x)
{
    if(-1 == ans)
    {
        ans = x;
    }
    else if(ans > x)
    {
        ans = x;
    }
}

void make(int limit)
{
    clearEdge();
    for(int i=0;i<a;++i)
    {
        addEdge(hat[i].x, hat[i].y + n);
        addEdge(hat[i].y, hat[i].x + n);
        addEdge(hat[i].x + n, hat[i].y);
        addEdge(hat[i].y + n, hat[i].x);
    }
    for(int i=0;i<b;++i)
    {
        addEdge(fri[i].x, fri[i].y);
        addEdge(fri[i].y, fri[i].x);
        addEdge(fri[i].x + n, fri[i].y + n);
        addEdge(fri[i].y + n, fri[i].x + n);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(dist(i, s1) + dist(s1, j) > limit)
            {
                addEdge(i, j + n);
                addEdge(j, i + n);
            }
            if(dist(i, s2) + dist(s2, j) > limit)
            {
                addEdge(i + n, j);
                addEdge(j + n, i);
            }
            if(dist(i, s1) + dist(s1, s2) + dist(s2, j) > limit)
            {
                addEdge(i, j);
                addEdge(j + n, i + n);
            }
            if(dist(i, s2) + dist(s1, s2) + dist(s1, j) > limit)
            {
                addEdge(i + n, j + n);
                addEdge(j, i);
            }
        }
    }
}

void dfs(int u)
{
    dfn[u] = low[u] = timeStamp ++;
    visit[u] = true;
    stack[top++] = u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(-1 == dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(visit[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u])
    {
        int t;
        do
        {
            t = stack[--top];
            visit[t] = false;
            belong[t] = belongNumber;
        }
        while(t != u);
        ++ belongNumber;
    }
}

void tarjan()
{
    memset(visit, false, sizeof(visit));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    top = belongNumber = timeStamp = 0;
    for(int i=0;i<(n<<1);++i)
    {
        if(-1 == dfn[i])
        {
            dfs(i);
        }
    }
}

bool judge()
{
    for(int i=0;i<n;++i)
    {
        if(belong[i] == belong[i+n])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ans = -1;
    int left = 0, right = MAXD, mid;
    while(left <= right)
    {
        mid = (left + right) >> 1;
        make(mid);
        tarjan();
        if(judge())
        {
            right = mid - 1;
            setAnswer(mid);
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &n, &a, &b))
    {
        input();
        solve();
        printf("%d\n", ans);
    }
    return 0;
}