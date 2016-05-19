#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1<<29;
const int maxn=210;
const int maxm=maxn*maxn*5;
int e,st,des,head[maxn],pnt[maxm],nxt[maxm],cost[maxm],flow[maxm],dist[maxn],pre[maxn];
int n,m,k;
char s[110][110];
bool vis[maxn];
queue<int> q;
void AddEdge(int u,int v,int c,int f)
{
    pnt[e]=v;nxt[e]=head[u];cost[e]=c;flow[e]=f;head[u]=e++;
    pnt[e]=u;nxt[e]=head[v];cost[e]=-c;flow[e]=0;head[v]=e++;
}
bool Spfa()
{
    for(int i=st;i<=des+1;i++)
    {
        pre[i]=-1;
        dist[i]=inf;
    }
    dist[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i])
            if(flow[i]&&dist[pnt[i]]>dist[u]+cost[i])
            {
                dist[pnt[i]]=dist[u]+cost[i];
                pre[pnt[i]]=i;
                if(!vis[pnt[i]])
                {
                    vis[pnt[i]]=1;
                    q.push(pnt[i]);
                }
            }
    }
    return dist[des]!=inf;
}
void mincostflow()
{
    int ans=0,sum=0;
    while(Spfa())
    {
        int mini=inf;
        for(int i=pre[des];i!=-1;i=pre[pnt[i^1]])
            mini=min(mini,flow[i]);
        for(int i=pre[des];i!=-1;i=pre[pnt[i^1]])
        {
            flow[i]-=mini;
            flow[i^1]+=mini;
        }
        sum+=mini;
        ans+=dist[des]*mini;
    }
    if(sum==n*m)
        printf("%d\n",-ans);
    else
        printf("-1\n");
}
void Build()
{
    st=0,des=2*n*m+1;
    int p=2*n*m+2;
    memset(head,-1,sizeof(head));
    AddEdge(st,p,0,k);
    for(int i=1;i<=n*m;i++)
    {
        AddEdge(st,i,0,1);
        AddEdge(n*m+i,des,0,1);
        AddEdge(p,n*m+i,0,1);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            for(int k=j+1;k<m;k++)
            {
                if(s[i][j]==s[i][k])
                    AddEdge(i*m+j+1,n*m+i*m+k+1,-(s[i][j]-'0'-(k-j-1)),1);
                else
                    AddEdge(i*m+j+1,n*m+i*m+k+1,k-j-1,1);
            }
            for(int k=i+1;k<n;k++)
            {
                if(s[i][j]==s[k][j])
                    AddEdge(i*m+j+1,n*m+k*m+j+1,-(s[i][j]-'0'-(k-i-1)),1);
                else
                    AddEdge(i*m+j+1,n*m+k*m+j+1,k-i-1,1);
            }
        }
}
void solve()
{
    Build();
    mincostflow();
}
int main()
{
    int T,cas=1; 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        printf("Case %d : ",cas++);
        solve();
    }
    return 0;
}
