#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=1000+10;
const int maxm=200000+10;
struct Edge
{
    int to,cap,next;
    Edge(int to=0,int cap=0,int next=0):to(to),cap(cap),next(next){}
}edges[maxm<<1];
int head[maxn],d[maxn],nEdge;
bool vis[maxn];
int n,m,K;
void AddEdges(int from,int to,int cap)
{
    edges[++nEdge]=Edge(to,cap,head[from]);
    head[from]=nEdge;
    edges[++nEdge]=Edge(from,0,head[to]);
    head[to]=nEdge;
}
bool BFS(int S,int T)
{
    memset(d,0xff,sizeof(d));
    d[S]=0;
    queue<int>q;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int k=head[u];k!=-1;k=edges[k].next)
        {
            Edge e=edges[k];
            if(d[e.to]==-1&&e.cap)
            {
                d[e.to]=d[u]+1;
                q.push(e.to);
            }
        }
    }
    return d[T]!=-1;
}
int DFS(int u,int a,int T)
{
    if(u==T||a==0) return a;
    int flow=0,f;
    for(int k=head[u];k!=-1;k=edges[k].next)
    {
        Edge & e=edges[k];
        if(d[e.to]==d[u]+1&&(f=DFS(e.to,min(a,e.cap),T))>0)
        {
            edges[k].cap-=f;
            edges[k^1].cap+=f;
            flow+=f;a-=f;
            if(a==0) return flow;
        }
    }
    d[u]=-1;
    return flow;
}
bool dfs(int u,int fa)
{
    for(int k=head[u];k!=-1;k=edges[k].next)
    {
        if(k==(fa^1)) continue;
        if(edges[k].cap)
        {
            if(vis[edges[k].to]) return true;
            vis[edges[k].to]=true;
            if(dfs(edges[k].to,k)) return true;
            vis[edges[k].to]=false;
        }
    }
    return false;
}
int mat[444][444];
void ptmat()
{
    printf("Unique\n");
    memset(mat,0,sizeof(mat));
    for(int u=1;u<=n;++u)
    {
        for(int k=head[u];k!=-1;k=edges[k].next)
        {
            int v=edges[k].to;
            if(v>n&&v<=n+m)
                mat[u][v-n]=K-edges[k].cap;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(j>1) printf(" ");
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&K))
    {
        memset(head,0xff,sizeof(head));
        nEdge=-1;
        int S=0,T=n+m+1,w;
        int sum1=0,sum2=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&w);
            sum1+=w;
            AddEdges(S,i,w);
            for(int j=1;j<=m;++j)
                AddEdges(i,j+n,K);
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%d",&w);
            sum2+=w;
            AddEdges(i+n,T,w);
        }
        if(sum1!=sum2) printf("Impossible\n");
        else
        {
            int flow=0;
            while(BFS(S,T)) flow+=DFS(S,inf,T);
            if(flow!=sum1) printf("Impossible\n");
            else
            {
                memset(vis,0,sizeof(vis));
                bool flag=false;
                for(int i=1;i<=n;++i)
                    if(dfs(i,-1))
                    {
                        flag=true;
                        break;
                    }
                if(flag) printf("Not Unique\n");
                else ptmat();
            }
        }
    }
    return 0;
}
