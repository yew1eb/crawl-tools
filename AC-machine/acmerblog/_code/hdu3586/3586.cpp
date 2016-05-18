#include<iostream>
#include<algorithm>
#include<cstdio>
#include<memory.h>
using namespace std;
int dp[1002],n,m,NE,mid;
int head[1002],vis[1002];
const int INF=1000001;
struct node
{
    int u,v,val,next;
} Edge[2002];
void addEdge(int u,int v,int w)
{
    Edge[NE].u=u,Edge[NE].v=v,Edge[NE].next=head[u];
    Edge[NE].val=w;
    head[u]=NE++;
}
int dfs(int u,int fa)
{
    int i,sum=0;
    vis[u]=1;
    for(i=head[u]; i!=-1; i=Edge[i].next)
    {
        int r=Edge[i].v;
        if(fa==r) continue;
        int rr=dfs(r,u);
        if(rr>Edge[i].val&&Edge[i].val<=mid)
        {
            rr=Edge[i].val;
        }
        sum+=rr;
    }
    if(!sum)return INF;
    return sum;
}
int main()
{
    while(cin>>n>>m,(n||m))
    {
        NE=0;
        int i,j,k,a,b,w,ans=INF;
        int l=1002,r=0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(i=1; i<n; i++)
        {
            cin>>a>>b>>w;
            addEdge(a,b,w);
            addEdge(b,a,w);
            l=min(l,w);
            r=max(r,w);
        }
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(dfs(1,0)<=m)
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        if(ans>=INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
