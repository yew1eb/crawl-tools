#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>

#define eps 1e-9
#define pi acos(-1.0)
#define inf 107374182  
#define inf64 1152921504606846976  
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopy1all(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

const int maxn=1000+10;
const int maxm=200000+10;

struct node
{
    int v,w,next;
    node(int v=0,int w=0,int next=0):v(v),w(w),next(next) {};
} edge[maxm<<1];
int head[maxn],d[maxn],nEdge,S,T;
bool vis[maxn];
int n,m,K;
void addedge(int from,int to,int cap)
{
    edge[++nEdge]=node(to,cap,head[from]);
    head[from]=nEdge;
    edge[++nEdge]=node(from,0,head[to]);
    head[to]=nEdge;
}
int deep[maxn];
bool bfs()
{
    memset(deep,-1,sizeof(deep));
    queue<int>q;
    q.push(S);//æºç¹
    deep[S]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int p=head[u];
        while(p!=-1)
        {
            int v=edge[p].v;
            if(deep[v]==-1&&edge[p].w>0)
            {
                q.push(v);
                deep[v]=deep[u]+1;
            }
            p=edge[p].next;
        }
    }
    return deep[T]!=-1; //æ±ç¹

}
int DFS(int src ,int flow)
{
    if(src==T||flow==0)return flow;
    int sum=0,temp;
    int p=head[src];
    while(p!=-1)
    {
        int v=edge[p].v;
        if(deep[v]==deep[src]+1&&edge[p].w>0)
        {
            temp=DFS(v,min(flow-sum,edge[p].w));
            edge[p].w-=temp;
            edge[p^1].w+=temp;
            sum+=temp;
            if(flow-sum==0) return sum;
        }
        p=edge[p].next;
    }
    deep[src]=-1;
    return sum;
}
bool dfs(int u,int fa)
{
    for(int k=head[u]; k!=-1; k=edge[k].next)
    {
        if(k==(fa^1)) continue;
        if(edge[k].w)
        {
            if(vis[edge[k].v]) return true;
            vis[edge[k].v]=true;
            if(dfs(edge[k].v,k)) return true;
            vis[edge[k].v]=false;
        }
    }
    return false;
}
int mat[404][404];
void ptmat()
{
    printf("Unique\n");
    memset(mat,0,sizeof(mat));
    for(int u=1; u<=n; ++u)
    {
        for(int k=head[u]; k!=-1; k=edge[k].next)
        {
            int v=edge[k].v;
            if(v>n&&v<=n+m)
                mat[u][v-n]=K-edge[k].w;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(j>1) printf(" ");
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        memset(head,-1,sizeof(head));
        nEdge=-1;
        S=0,T=n+m+1;
        int sum1=0,sum2=0,w;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&w);
            sum1+=w;
            addedge(S,i,w);
            for(int j=1; j<=m; ++j)
                addedge(i,j+n,K);
        }
        for(int i=1; i<=m; ++i)
        {
            scanf("%d",&w);
            sum2+=w;
            addedge(i+n,T,w);
        }
        if(sum1!=sum2) printf("Impossible\n");
        else
        {
            int flow=0;
            while(bfs())flow+=DFS(S,inf);
            if(flow!=sum1) printf("Impossible\n");
            else
            {
                memset(vis,0,sizeof(vis));
                bool flag=false;
                for(int i=1; i<=n; ++i)
                {
                    if(dfs(i,-1))
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag) printf("Not Unique\n");
                else ptmat();
            }
        }
    }
    return 0;
}
