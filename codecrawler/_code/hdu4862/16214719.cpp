#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 5555
#define MAXM 1000000
#define INF 0x3f3f3f3f
struct node
{
    int u,v,f,c,next;
}e[MAXM];
int n,k,m,head[MAXN],pre[MAXN],dist[MAXN],vis[MAXN];
int en,s,t,maxflow,mincost; //sæºç¹ï¼tæ±ç¹
void add(int u,int v,int c,int f)//å è¾¹
{
    e[en].u=u;
    e[en].v=v;
    e[en].c=c;
    e[en].f=f;
    e[en].next=head[u];
    head[u]=en++;
    e[en].u=v;
    e[en].v=u;
    e[en].c=-c;
    e[en].f=0;
    e[en].next=head[v];
    head[v]=en++;
}
int spfa()
{
    int i,u,v;
    for(i=0;i<=t;i++)
        pre[i]=-1,vis[i]=0,dist[i]=INF;
    dist[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=head[u];i!=-1;i=e[i].next)
        {
            v=e[i].v;
            if(e[i].f>0&&dist[u]+e[i].c<dist[v])
            {
                dist[v]=dist[u]+e[i].c;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        vis[u]=0;
    }
    if(dist[t]==INF)
        return 0;
    return 1;
}
void add()
{
    int v;
    int maxf=INF;
    for(v=pre[t];~v;v=pre[e[v].u])
        maxf=min(maxf,e[v].f);
    for(v=pre[t];~v;v=pre[e[v].u])
    {
        e[v].f-=maxf;
        e[v^1].f+=maxf;
        mincost+=maxf*e[v].c;
    }
    maxflow+=maxf;
}
void init()
{
    maxflow=0;
    mincost=0;
    s=0;
    t=n*m*2+2;
    en=0;
    memset(head,-1,sizeof(head));
}
char mp[20][20];
int id[20][20];
int main()
{
    int i,j,a,b,c;
    int cas;
    int ca=1;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&k);
        init();
        for(int i=1,ID=1;i<=n;i++)
        {
            scanf("%s",mp[i]+1);
            for(int j=1;j<=m;j++,ID++)
            {
                mp[i][j]-='0';
                id[i][j]=ID;
            }
        }
        if(k<min(n,m))
        {
            printf("Case %d : %d\n",ca++,-1);
            continue;
        }
        add(s,t-1,0,k);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                add(s,id[i][j],0,1);
                add(id[i][j]+n*m,t,0,1);
                add(t-1,id[i][j]+n*m,0,1);
                for(int r=j+1;r<=m;r++)
                {
                    if(mp[i][j]==mp[i][r]) add(id[i][j],id[i][r]+n*m,-mp[i][j]+r-j-1,1);
                    else add(id[i][j],id[i][r]+n*m,r-j-1,1);
                }
                for(int d=i+1;d<=n;d++)
                {
                    if(mp[i][j]==mp[d][j]) add(id[i][j],id[d][j]+n*m,-mp[i][j]+d-i-1,1);
                    else add(id[i][j],id[d][j]+n*m,d-i-1,1);
                }
            }
        }
        while(spfa())
             add();
        printf("Case %d : %d\n",ca++,-mincost);
    }
    return 0;
}
