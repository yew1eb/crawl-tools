#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e4 + 5;

struct Vertex{
    int head;
}V[N];

struct Edge{
    int v,w,next;
}E[N];

int top;

void init()
{
    memset(V,-1,sizeof(V));
    top = 0;
}

void add_edge(int u,int v,int w)
{
    E[top].v = v;
    E[top].w = w;
    E[top].next = V[u].head;
    V[u].head = top++;
}

int dp[N][3];

void dfs1(int u)
{
    int biggest = 0 , bigger = 0;
    for(int i=V[u].head;~i;i=E[i].next)
    {
        int v = E[i].v;
        dfs1(v);
        int tmp = dp[v][0]+E[i].w;
        if(biggest <= tmp)
        {
            bigger = biggest;
            biggest = tmp;
        }
        else if(bigger < tmp)
            bigger = tmp;
    }
    dp[u][0] = biggest;
    dp[u][1] = bigger;
}

void dfs2(int u)
{
    for(int i=V[u].head;~i;i=E[i].next)
    {
        int v = E[i].v;
        dp[v][2] = max(dp[u][2] , dp[v][0]+E[i].w==dp[u][0] ? dp[u][1] : dp[u][0]) + E[i].w;
        dfs2(v);
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int v=2;v<=n;v++)
        {
            int u,w;
            scanf("%d%d",&u,&w);
            add_edge(u,v,w);
        }
        dfs1(1);
        dp[1][2] = 0;
        dfs2(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
