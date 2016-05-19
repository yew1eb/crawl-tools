#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Inf 999999999
using namespace std;
int head1[100005],head2[15],k,dis[15][100005];
bool vis[15];
struct
{
    int e;
    int w;
    int next;
}edge1[200005],edge2[205];
void add1(int s,int e,int w)
{
    edge1[k].e=e;
    edge1[k].w=w;
    edge1[k].next=head1[s];
    head1[s]=k++;
}
void add2(int s,int e,int w)
{
    edge2[k].e=e;
    edge2[k].w=w;
    edge2[k].next=head2[s];
    head2[s]=k++;
}
void spfa(int s,int n,int *dis)
{
    int i,st,ed;
    bool visit[100005];
    queue<int> x;
    memset(visit,false,sizeof(visit));
    for(i=0;i<n;i++)
        dis[i]=Inf;
    dis[s]=0;
    x.push(s);
    while(!x.empty())
    {
        st=x.front();
        x.pop();
        visit[st]=false;
        for(i=head1[st];i!=-1;i=edge1[i].next)
        {
            ed=edge1[i].e;
            if(dis[ed]>dis[st]+edge1[i].w)
            {
                dis[ed]=dis[st]+edge1[i].w;
                if(!visit[ed])
                {
                    visit[ed]=true;
                    x.push(ed);
                }
            }
        }
    }
}
int dfs(int pos,int len,int n,int c)
{
    int i,ans=Inf;
    vis[pos]=true;
    if(pos==0)
    {
        if(c==n)
            return len;
        else
            return Inf;
    }
    for(i=head2[pos];i!=-1;i=edge2[i].next)
    {
        int ed=edge2[i].e;
        if(!vis[ed]||ed==0)
            ans=min(ans,dfs(ed,len+edge2[i].w,n,c+1));
    }
    vis[pos]=false;
    return ans;
}
int main()
{
    int i,j,m,n,a,b,c,t,p[15],q,cnt,ans;
    scanf("%d",&t);
    while(t--)
    {
        k=cnt=0;ans=Inf;
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            add1(a,b,c);
            add1(b,a,c);
        }
        scanf("%d",&q);
        p[cnt]=0;
        spfa(0,n,dis[cnt]);
        cnt++;
        while(q--)
        {
            scanf("%d",&p[cnt]);
            spfa(p[cnt],n,dis[cnt]);
            cnt++;
        }
        k=0;
        for(i=0;i<cnt;i++)
            for(j=0;j<cnt;j++)
                if(i!=j)
                    add2(i,j,dis[i][p[j]]);
        for(i=1;i<cnt;i++)
        {
            memset(vis,false,sizeof(vis));
            vis[0]=true;
            ans=min(ans,dfs(i,dis[0][p[i]],cnt,1));
        }
        printf("%d\n",ans);
    }
    return 0;
}