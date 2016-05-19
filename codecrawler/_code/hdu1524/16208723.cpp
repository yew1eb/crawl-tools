#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 2005;

int head[N];
int n,m,cnt;

struct Edge
{
    int to;
    int next;
};

Edge edge[N*N];
int SG[N];

void Init()
{
    cnt = 0;
    memset(SG,-1,sizeof(SG));
    memset(head,-1,sizeof(head));
}

void add(int u,int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int mex(int x)
{
    if(SG[x] != -1) return SG[x];
    bool vis[N];
    memset(vis,0,sizeof(vis));
    for(int i=head[x];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        SG[v] = mex(v);
        vis[SG[v]] = 1;
    }
    for(int i=0;;i++)
    if(!vis[i]) return i;
}

int main()
{
    while(~scanf("%d",&n))
    {
        Init();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                int u;
                scanf("%d",&u);
                add(i,u);
            }
        }
        int k;
        while(~scanf("%d",&k))
        {
            if(k == 0) break;
            int ans = 0;
            while(k--)
            {
                int x;
                scanf("%d",&x);
                ans ^= mex(x);
            }
            if(ans) puts("WIN");
            else    puts("LOSE");
        }
    }
    return 0;
}
