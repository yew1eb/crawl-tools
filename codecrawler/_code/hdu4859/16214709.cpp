#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
#define eps  1e-12
#define INF   0x7fffffff
#define maxn 2700
using namespace std;
int n,m;
int en;
int st,ed;
int dis[maxn] ;
int que[9999999];
struct edge
{
    int to,c,next;
};
edge e[9999999];
int head[maxn];
void add(int a,int b,int c)
{
    e[en].to=b;
    e[en].c=c;
    e[en].next=head[a];
    head[a]=en++;
    e[en].to=a;
    e[en].c=0;
    e[en].next=head[b];
    head[b]=en++;
}
int bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[st]=0;
    int front=0,rear=0;
    que[rear++]=st;
    while(front<rear)
    {
        int j=que[front++];
        for(int k=head[j];k!=-1;k=e[k].next)
        {
            int i=e[k].to;
            if(dis[i]==-1&&e[k].c)
            {
                dis[i] = dis[j]+ 1 ;
                que[rear++]=i;
                if(i==ed) return true;
            }
        }
    }
    return false;
}
int dfs(int x,int mx)
{
    int i,a;
    if(x==ed) return mx ;
    int ret=0;
    for(int k=head[x];k!=-1&&ret<mx;k=e[k].next)
    {
        if(e[k].c&&dis[e[k].to]==dis[x]+1)
        {
            int dd=dfs(e[k].to,min(e[k].c,mx-ret));
            e[k].c-=dd;
            e[k^1].c+=dd;
            ret+=dd;
        }
    }
    if(!ret) dis[x]=-1;
    return ret;
}
void init()
{
    en=0;
    st=(n+2)*(m+2)+1;
    ed=st+1;
    memset(head,-1,sizeof(head));
}
char mp[55][55];
int id[55][55];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int isok(int x,int y) {return x>=0&&x<=n+1&&y>=0&&y<=m+1;}
void build()
{
    int x,y,z;
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);

    for(int i=0,ID=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++,ID++)
        {
            if(mp[i][j]==0) mp[i][j]='D';
            id[i][j]=ID;
        }
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(mp[i][j]=='D'&&i%2==j%2||mp[i][j]=='.'&&i%2!=j%2) add(st,id[i][j],INF);
            if(mp[i][j]=='D'&&i%2!=j%2||mp[i][j]=='.'&&i%2==j%2) add(id[i][j],ed,INF);
            for(int d=0;d<4;d++)
            {
                int ii=i+dx[d],jj=j+dy[d];
                if(isok(ii,jj)) add(id[i][j],id[ii][jj],1);
            }
        }
    }
}
int dinic()
{
    int tmp=0;
    int maxflow=0;
    while(bfs())
    {
        while(tmp=dfs(st,INF)) maxflow+=tmp;
    }
    return maxflow;
}
int main()
{
    int cas,ca=1;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        init();
        build();
        printf("Case %d: %d\n",ca++,(n+2)*(m+1)+(m+2)*(n+1)-dinic());
    }
    return 0;
}
