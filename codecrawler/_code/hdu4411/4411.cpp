#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#define MIN(a , b) ((a) < (b) ? (a) : (b))
using namespace std;
const int inf = 100010;
const int maxn = 102;
const int maxe = 20000;
const int maxm = 28;
struct node
{
    int v,w,c;
    int next;
}edge[maxe << 1];
int head[maxn << 1],dis[maxn << 1],pre[maxn << 1],bj[maxn << 1];
int map[maxn][maxn];
bool vis[maxn << 1];
queue <int> Q;
int m,n,k,idx,s,ss,t;

void init()
{
    for(int i=0;i<=n;i++)
    {
        map[i][i] = 0;
        for(int j=0;j<=n;j++)
        {
            map[i][j] = map[j][i] = inf;
        }
    }
    return;
}

void read()
{
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        if(map[u][v] > w)
        {
            map[u][v] = map[v][u] = w;
        }
    }
    return;
}

void floyd()
{
    for(int k=0;k<=n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            if(i == k || map[i][k] == inf) continue;
            for(int j=0;j<=n;j++)
            {
                if(j == i || j == k || map[k][j] == inf) continue;
                if(map[i][k] + map[k][j] < map[i][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    map[j][i] = map[i][j];
                }
            }
        }
    }
    return;
}

void addedge(int u,int v,int w,int c)
{
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].c = c;
    edge[idx].next = head[u];
    head[u] = idx++;

    edge[idx].v = u;
    edge[idx].w = 0;
    edge[idx].c = -c;
    edge[idx].next = head[v];
    head[v] = idx++;
    return;
}

void make(int lim)
{
    memset(head,-1,sizeof(head));
    memset(bj,-1,sizeof(bj));
    s = idx = 0;
    ss = 2*n+1;
    t = 2*n+2;
    addedge(s,ss,lim,0);
    for(int i=1;i<=n;i++)
    {
        if(map[0][i] < inf)
        {
            addedge(ss,i,inf,map[0][i]);
            addedge(i+n,t,inf,map[i][0]);
        }
        addedge(i,i+n,1,-inf);
        for(int j=i+1;j<=n;j++)
        {
            if(map[i][j] < inf)
            {
                addedge(i+n,j,inf,map[i][j]);
            }
        }
    }
    return;
}

bool spfa(int st)
{
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    while(!Q.empty())
    {
        Q.pop();
    }
    for(int i=0;i<=t;i++)
    {
        dis[i] = (i == st) ? 0 : inf;
    }
    Q.push(st);
    vis[st] = true;
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        vis[cur] = false;
        for(int i=head[cur];i != -1;i=edge[i].next)
        {
            if(edge[i].w > 0 && dis[edge[i].v] > dis[cur] + edge[i].c)
            {
                dis[edge[i].v] = dis[cur] + edge[i].c;
                pre[edge[i].v] = i;
                if(vis[edge[i].v] == false)
                {
                    vis[edge[i].v] = true;
                    Q.push(edge[i].v);
                }
            }
        }
    }
    return dis[t] < inf;
}

void solve()
{
    int res = inf;
    for(int i=1;i<=k;i++)
    {
        make(i);
        int ans = 0;
        while(spfa(s))
        {
            int dx = inf;
            int top = t;
            while(top != s)
            {
                dx = MIN(dx , edge[pre[top]].w);
                top = edge[pre[top]^1].v;
            }
            top = t;
            while(top != s)
            {
                ans += dx * edge[pre[top]].c;
                edge[pre[top]].w -= dx;
                edge[pre[top]^1].w += dx;
                top = edge[pre[top]^1].v;
            }
        }
        res = MIN(res , ans + n * inf);
    }
    printf("%d\n",res);
    return;
}

int main()
{
    while(scanf("%d %d %d",&n,&m,&k) && n+m+k)
    {
        init();
        read();
        floyd();
        solve();
    }
    return 0;
}