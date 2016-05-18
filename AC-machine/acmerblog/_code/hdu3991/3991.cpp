#include<cstdio>
#include<algorithm>
using namespace std;
const int mm=1111111;
const int mn=11111;
const int oo=1000000000;
int node,src,dest,edge,ret;
int ver[mm],flow[mm],next[mm];
int head[mn],work[mn],dis[mn],q[mn];
double d[111][111];
struct data
{
    int p;
    double t;
}Q[11111];
inline bool cmp(data a,data b)
{
    return a.t<b.t;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}
inline void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)head[i]=-1;
    edge=0;
}
inline void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,next[edge]=head[v],head[v]=edge++;
}
bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=next[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
                dis[q[r++]=v]=dis[u]+1;
                if(v==dest)return 1;
            }
    return 0;
}
int Dinic_dfs(int u,int exp)
{
    if(u==dest)return exp;
    for(int &i=work[u],v,tmp; i>=0; i=next[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
int Dinic_flow()
{
    int i,ret=0,delta;
    while(Dinic_bfs())
    {
        for(i=0; i<node; ++i)work[i]=head[i];
        while(delta=Dinic_dfs(src,oo))ret+=delta;
    }
    return ret;
}
int main()
{
    int i,j,k,u,v,n,m,q,c,t,cas=0,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(i=0;i<n;d[i][i]=0,++i)
            for(j=0;j<n;++j)d[i][j]=1e20;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(c<d[u][v])d[v][u]=d[u][v]=c;
        }
        for(i=0;i<q;++i)
            scanf("%d%lf",&Q[i].p,&Q[i].t);
        for(k=0;k<n;++k)
            for(i=0;i<n;++i)
                if(k!=j)for(j=0;j<n;++j)
                    if(i!=j&&i!=k&&d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
        sort(Q,Q+q,cmp);
        prepare(q+q+2,q+q,q+q+1);
        for(i=0;i<q;++i)addedge(src,i,1),addedge(i+q,dest,1);
        for(i=0;i<q;++i)
            for(j=i+1;j<q;++j)
                if(Q[i].t+d[Q[i].p][Q[j].p]-Q[j].t<1e-8)addedge(i,q+j,1);
        ans=q-Dinic_flow();
        if(ans)--ans;
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}