#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int inf = 1 << 29;
const int maxn = 1010;
const int maxe = 2100000;
struct node
{
    int v,w;
    int next;
}edge[maxe];
int head[maxn],cur[maxn],dis[maxn],gap[maxn],pre[maxn];
int B[maxn][maxn],C[maxn],D[maxn];
int n,s,t,idx,sum;

void init()
{
    memset(head,-1,sizeof(head));
    memset(D,0,sizeof(D));
    scanf("%d",&n);
    s = idx = sum = 0;
    t = n + 1;
    return;
}

void addedge(int u,int v,int w)
{
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].next = head[u];
    head[u] = idx++;

    edge[idx].v = u;
    edge[idx].w = 0;
    edge[idx].next = head[v];
    head[v] = idx++;
    return;
}

void read()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&B[i][j]);
            D[j] += B[i][j];
            if(i != j) addedge(i,j,B[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&C[i]);
        addedge(s,i,C[i]);
        addedge(i,t,D[i]);
        sum += D[i];
    }
    return;
}

int isap(int N)
{
    memset(gap,0,sizeof(gap));
    memset(dis,0,sizeof(dis));
    for(int i=0;i<N;i++)
    {
        cur[i] = head[i];
    }
    int i,top = s;
    int maxflow = 0,flow = inf;
    gap[s] = N;
    while(dis[s] < N)
    {
        for(i=cur[top];i != -1;i=edge[i].next)
        {
            if(edge[i].w > 0 && dis[top] == dis[edge[i].v] + 1)
            {
                break;
            }
        }
        if(i != -1)
        {
            cur[top] = i;
            if(edge[i].w < flow)
            {
                flow = edge[i].w;
            }
            top = edge[i].v;
            pre[top] = i;
            if(top == t)
            {
                maxflow += flow;
                while(top != s)
                {
                    edge[pre[top]].w -= flow;
                    edge[pre[top]^1].w += flow;
                    top = edge[pre[top]^1].v;
                }
                flow = inf;
            }
        }
        else
        {
            if(--gap[dis[top]] == 0)
            {
                break;
            }
            cur[top] = head[top];
            dis[top] = N;
            for(int j=head[top];j != -1;j=edge[j].next)
            {
                if(edge[j].w > 0 && dis[top] > dis[edge[j].v] + 1)
                {
                    cur[top] = j;
                    dis[top] = dis[edge[j].v] + 1;
                }
            }
            gap[dis[top]]++;
            if(top != s)
            {
                top = edge[pre[top]^1].v;
            }
        }
    }
    return maxflow;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        init();
        read();
        printf("%d\n",sum - isap(t+1));
    }
    return 0;
}
