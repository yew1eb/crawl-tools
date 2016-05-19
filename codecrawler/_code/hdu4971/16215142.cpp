#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1<<29;
const int maxn=100;
const int maxm=maxn*maxn*5;
int e,st,des,head[maxn],pnt[maxm],nxt[maxm],flow[maxm],level[maxn];
int n,m,sum;
queue<int> q;
void AddEdge(int u,int v,int f)
{
    pnt[e]=v;nxt[e]=head[u];flow[e]=f;head[u]=e++;
    pnt[e]=u;nxt[e]=head[v];flow[e]=0;head[v]=e++;
}
bool BFS()
{
    memset(level,0,sizeof(level));
    level[st]=1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=nxt[i])
            if(flow[i]&&!level[pnt[i]])
            {
                level[pnt[i]]=level[u]+1;
                q.push(pnt[i]);
            }
    }
    return level[des];
}
int DFS(int u,int maxf)
{
    if(u==des||!maxf)
        return maxf;
    int f=0;
    for(int i=head[u];i!=-1;i=nxt[i])
        if(flow[i]&&level[pnt[i]]==level[u]+1)
        {
            int t=DFS(pnt[i],min(flow[i],maxf-f));
            if(t>0)
            {
                flow[i]-=t;
                flow[i^1]+=t;
                f+=t;
                if(f==maxf)
                    break;
            }
            else
                level[pnt[i]]=0;
        }
    return f;
}
int maxflow()
{
    int ans=0;
    while(BFS())
        ans+=DFS(st,inf);
    return ans;
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        e=st=0;des=n+m+1;
        memset(head,-1,sizeof(head));
        sum=0;
        for(int i=1;i<=n;i++)
        {
            int val;
            scanf("%d",&val);
            AddEdge(st,i,val);
            sum+=val;
        }
        for(int i=1;i<=m;i++)
        {
            int val;
            scanf("%d",&val);
            AddEdge(n+i,des,val);
        }
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
            {
                int val;
                scanf("%d",&val);
                AddEdge(i,n+val+1,inf);
            }
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
            {
                int val;
                scanf("%d",&val);
                if(val)
                    AddEdge(n+i,n+j,inf);
            }
        int ans=maxflow();
        printf("Case #%d: %d\n",cas++,sum-ans);
    }
    return 0;
}
