#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define eps 1e-8
#define MAXN 100
#define MAXM 1000000
#define INF 100000
struct node
{
    int u,v,f,next;
    double c;
}e[MAXM];
int n,k,head[MAXN],pre[MAXN],vis[MAXN];
double dist[MAXN];
int en,s,t,maxflow,mincost,m; //s源点，t汇点
void add(int u,int v,double c,int f)//加边
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
        pre[i]=-1,vis[i]=0,dist[i]=-INF;
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
            if(e[i].f>0&&dist[u]+e[i].c-eps>dist[v])
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
    if(dist[t]==-INF)
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
int a[123];
int w[123];
int ADD[123];
int mp[123][123];
void init()
{
    maxflow=0;
    mincost=0;
    s=0;
    t=n+m+1;
    en=0;
    memset(head,-1,sizeof(head));
    memset(ADD,0,sizeof(ADD));
}
double cal(int x,int w)
{
    return (4.0-3.0*(100.0-x)*(100.0-x)/1600.0)*w;
}
int main()
{
    int k,b;
    while(~scanf("%d%d%d",&n,&k,&m))
    {
        if(n+k+m==0) break;
        init();
        for(int i=1;i<=m;i++) scanf("%d",&w[i]);
        for(int i=1;i<=m;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
        {
            for(int q=a[i];q<60;q++) add(s,i,INF,1);
            for(int q=max(a[i],60);q<100;q++) add(s,i,cal(q+1,w[i])-cal(q,w[i]),1);
        }
        for(int i=1;i<=n;i++)
        {
            add(m+i,t,0,k);
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&b);
                if(b) add(j,m+i,0,INF);
            }
        }
        while(spfa()) add();
        for(int i=head[s];~i;i=e[i].next)
        {
            if(e[i].v>=1&&e[i].v<=m&&e[i].f==0) ADD[e[i].v]++;
        }
        int ok=1;
        for(int i=1;i<=m;i++)
        {
            if(a[i]+ADD[i]<60)
            {
                ok=0;
                break;
            }
            a[i]+=ADD[i];
        }
        if(ok==0)
        {
            puts("0.000000");
        }
        else
        {
            double ans=0;
            int d=0;
            for(int i=1;i<=m;i++)
            {
                ans+=cal(a[i],w[i]);
                d+=w[i];
            }
            printf("%.6lf\n",ans/d);
        }
    }
    return 0;
}
