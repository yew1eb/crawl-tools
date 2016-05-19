#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e5+3;

struct Vertex
{
    int head;
}V[N];

struct Edge
{
    int v,w,next;
}E[N*10*2];

bool vis[N],tmpv[N];

int top,d[N];

void init()
{
    top = 0;
    memset(V,-1,sizeof(V));
}

void addEdge(int u,int v,int w)
{
    E[top].v = v;
    E[top].w = w;
    E[top].next = V[u].head;
    V[u].head = top++;
}

bool dfs(int pre,int u)
{
    vis[u] = true;
    for(int i=V[u].head;~i;i=E[i].next)
    {
        int v = E[i].v;
        if(v == pre)
            continue;
        if(vis[v])
            return false;
        d[v] = d[u] + E[i].w;
        if(!dfs(u,v))
            return false;
    }
    return true;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        int ans = 0;
        bool yes = false;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            memset(d,0,sizeof(d));
            if(!dfs(0,i))
            {
                yes = true;
                break;
            }
            int u = max_element(d+1,d+1+n) - d;
            memcpy(tmpv,vis,sizeof(vis));
            memset(vis,false,sizeof(vis));
            memset(d,0,sizeof(d));
            dfs(0,u);
            ans = max(ans,*max_element(d+1,d+1+n));
            memcpy(vis,tmpv,sizeof(vis));
        }
        if(yes)
            puts("YES");
        else
            printf("%d\n",ans);
    }
    return 0;
}
