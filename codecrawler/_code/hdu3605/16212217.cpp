#include<cstdio>
#include<cstring>
#define N 2005
#define M 30005
#define inf 999999999
#define min(a,b) ((a)<(b)?(a):(b))

int n,m,s,t,num,adj[N],dis[N],q[N];
struct edge
{
    int v,w,pre;
    edge(){}
    edge(int vv,int ww,int p){v=vv;w=ww;pre=p;}
}e[M];
void insert(int u,int v,int w)
{
    e[num]=edge(v,w,adj[u]);
    adj[u]=num++;
    e[num]=edge(u,0,adj[v]);
    adj[v]=num++;
}
int bfs()
{
    int i,x,v,head=0,tail=0;
    memset(dis,0,sizeof(dis));
    dis[s]=1;
    q[++tail]=s;
    while(head!=tail)
    {
        x=q[head=(head+1)%N];
        for(i=adj[x];~i;i=e[i].pre)
            if(e[i].w&&!dis[v=e[i].v])
            {
                dis[v]=dis[x]+1;
                if(v==t)
                    return 1;
                q[tail=(tail+1)%N]=v;
            }
    }
    return 0;
}
int dfs(int x,int limit)
{
    if(x==t)
        return limit;
    int i,v,tmp,cost=0;
    for(i=adj[x];~i&&cost<limit;i=e[i].pre)
        if(e[i].w&&dis[x]==dis[v=e[i].v]-1)
        {
            tmp=dfs(v,min(limit-cost,e[i].w));
            if(tmp)
            {
                e[i].w-=tmp;
                e[i^1].w+=tmp;
                cost+=tmp;
            }
            else
                dis[v]=-1;
        }
    return cost;
}
int Dinic()
{
    int ans=0;
    while(bfs())
        ans+=dfs(s,inf);
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int i,j,k,a,w,x[2005]={0};
        memset(adj,-1,sizeof(adj));
        num=0;
        s=0;
        t=2000;
        for(i=0;i<n;i++)
        {
            k=0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                if(a)
                    k|=1<<j;
            }
            x[k]++;
        }
        for(i=0;i<(1<<m);i++)
            if(x[i])
            {
                insert(s,i+1,x[i]);
                for(j=0;j<m;j++)
                    if(i&(1<<j))
                        insert(i+1,j+10+(1<<m),x[i]);
            }
        for(j=0;j<m;j++)
        {
            scanf("%d",&w);
            insert(j+10+(1<<m),t,w);
        }
        puts(Dinic()>=n?"YES":"NO");
    }
}
