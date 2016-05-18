#pragma comment (linker , "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cmath>
#define MIN(a , b) ((a) < (b) ? (a) : (b))
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int maxn = 500002;
struct node
{
    int v;
    int next;
}edge[maxn << 1];
int up[maxn],down[maxn],head[maxn],father[maxn],dis[maxn];
int dfn[maxn],low[maxn],s[maxn],belong[maxn],cnt[maxn],indegree[maxn];
int E[maxn << 1],D[maxn << 1],bj[maxn],dep[maxn],dp[maxn << 1][20];
bool vis[maxn],instack[maxn];
int m,n,idx,tmpdfn,tot,top,bound;

void init()
{
    memset(head,-1,sizeof(head));
    memset(cnt,0,sizeof(cnt));
    memset(vis,false,sizeof(vis));
    memset(instack,false,sizeof(instack));
    idx = tmpdfn = 0;
    tot = 1;
    return;
}

inline void in(int &a)
{
    char ch;
    while(ch = getchar(), ch < '0' || ch > '9');
    a = ch - '0';
    while(ch = getchar(), ch >= '0' && ch <= '9')
    {
        a = a * 10 + ch - '0';
    }
    return;
}

void swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int find(int u)
{
    if(u == father[u]) return father[u];
    int tmp = father[u];
    father[u] = find(tmp);
    dis[u] += dis[tmp];
    return father[u];
}

void addedge(int u,int v)
{
    edge[idx].v = v;
    edge[idx].next = head[u];
    head[u] = idx++;
    return;
}

void read()
{
    for(int i=1;i<=n;i++)
    {
        father[i] = i;
        in(down[i]);
        addedge(i , down[i]);
    }
    return;
}

void tarjan(int st)
{
    dfn[st] = low[st] = tmpdfn++;
    vis[st] = instack[st] = true;
    s[top++] = st;
    for(int i=head[st];i != -1;i=edge[i].next)
    {
        if(vis[edge[i].v] == false)
        {
            tarjan(edge[i].v);
            low[st] = MIN(low[st] , low[edge[i].v]);
        }
        else if(instack[edge[i].v])
        {
            low[st] = MIN(low[st] , dfn[edge[i].v]);
        }
    }
    if(dfn[st] == low[st])
    {
        int u;
        do
        {
            u = s[--top];
            instack[u] = false;
            belong[u] = tot;
            cnt[tot]++;
        }while(u != st);
        tot++;
    }
    return;
}

void reset()
{
    memset(head,-1,sizeof(head));
    memset(up,-1,sizeof(up));
    memset(dis,0,sizeof(dis));
    memset(indegree,0,sizeof(indegree));
    memset(dep,0,sizeof(dep));
    idx = top = 0;
    return;
}

void make()
{
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            top = 0;
            tarjan(i);
        }
    }
    reset();
    for(int i=1;i<=n;i++)
    {
        int u = belong[down[i]];
        int v = belong[i];
        if(u != v)
        {
            addedge(u,v);
            indegree[v]++;
            if(cnt[u] > 1)
            {
                up[v] = down[i];
            }
        }
        else
        {
            int x = find(down[i]);
            int y = find(i);
            if(x != y)
            {
                father[y] = x;
                dis[y] = dis[down[i]] + 1;
            }
        }
    }
    for(int i=1;i<tot;i++)
    {
        if(indegree[i] == 0)
        {
            addedge(0,i);
        }
    }
    return;
}

void dfs(int st,int h)
{
    dep[st] = h;
    E[++top] = st;
    D[top] = h;
    bj[st] = top;
    for(int i=head[st];i != -1;i=edge[i].next)
    {
        if(up[edge[i].v] == -1)
        {
            up[edge[i].v] = up[st];
        }
        dfs(edge[i].v , h+1);
        E[++top] = st;
        D[top] = h;
    }
    return;
}

void init_rmq()
{
    for(int i=1;i<=top;i++)
    {
        dp[i][0] = i;
    }
    for(int j=1;j<=bound;j++)
    {
        for(int i=1;i + (1 << j) - 1 <= top;i++)
        {
            if(D[dp[i][j-1]] < D[dp[i + (1 << (j-1))][j-1]])
            {
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i + (1 << (j-1))][j-1];
            }
        }
    }
    return;
}

int askrmq(int l,int r)
{
    if(l > r) swap(l , r);
    int d = log((double)(r - l + 1)) / log(2.0);
    int wei = -1;
    if(D[dp[l][d]] < D[dp[r - (1 << d) + 1][d]])
    {
        wei = dp[l][d];
    }
    else
    {
        wei = dp[r - (1 << d) + 1][d];
    }
    return E[wei];
}

void solve()
{
    dfs(0,0);
    bound = log((double)(top + 1)) / log(2.0);
    init_rmq();
    int u,v;
    while(m--)
    {
        in(u),in(v);
        if(u == v)
        {
            puts("0 0");
            continue;
        }
        int x = belong[u];
        int y = belong[v];
        int lca = askrmq(bj[x] , bj[y]);
        if(lca == 0)
        {
            puts("-1 -1");
            continue;
        }
        else if(cnt[lca] == 1)
        {
            printf("%d %d\n",dep[x] - dep[lca],dep[y] - dep[lca]);
            continue;
        }
        int dx,dy,dxy,dyx;
        if(x == y)
        {
            dx = dy = 0;
            find(u),find(v);
            if(dis[u] < dis[v])
            {
                dxy = cnt[x] + dis[u] - dis[v];
                dyx = dis[v] - dis[u];
            }
            else
            {
                dxy = dis[u] - dis[v];
                dyx = cnt[x] - dxy;
            }
        }
        else
        {
            dx = dep[x] - dep[lca];
            dy = dep[y] - dep[lca];
            if(cnt[lca] == 1)
            {
                dxy = dyx = 0;
            }
            else
            {
                u = (up[x] == -1) ? u : up[x];
                v = (up[y] == -1) ? v : up[y];
                find(u),find(v);
                if(dis[u] < dis[v])
                {
                    dxy = cnt[lca] + dis[u] - dis[v];
                    dyx = dis[v] - dis[u];
                }
                else
                {
                    dxy = dis[u] - dis[v];
                    dyx = cnt[lca] - dxy;
                }
            }
        }
        if(MAX(dx+dxy , dy) < MAX(dx , dy+dyx))
        {
            printf("%d %d\n",dx+dxy , dy);
        }
        else if(MAX(dx+dxy , dy) > MAX(dx , dy+dyx))
        {
            printf("%d %d\n",dx , dy+dyx);
        }
        else
        {
            if(MIN(dx+dxy , dy) < MIN(dx , dy+dyx))
            {
                printf("%d %d\n",dx+dxy , dy);
            }
            else if(MIN(dx+dxy , dy) > MIN(dx , dy+dyx))
            {
                printf("%d %d\n",dx , dy+dyx);
            }
            else
            {
                printf("%d %d\n",MAX(dx+dxy , dy),MIN(dx , dy+dyx));
            }
        }
    }
    return;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        init();
        read();
        make();
        solve();
    }
    return 0;
}