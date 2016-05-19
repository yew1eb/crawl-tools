#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=15e1+9,inf=1e9;
int n,m;
int sum[maxn][10];
long long dist[maxn][maxn],x[maxn],y[maxn],st[maxn],ed[maxn];
int level[maxn<<1],que[maxn<<1];
int head[maxn<<1],lon;
struct
{
    int next,to,c;
}e[maxn*maxn<<2];
void edgeini()
{
    memset(head,-1,sizeof(head));
    lon=-1;
}
void edgemake(int from,int to,int c)
{
    e[++lon].c=c;
    e[lon].to=to;
    e[lon].next=head[from];
    head[from]=lon;
}
void make(int from,int to,int c)
{
    edgemake(from,to,c);
    edgemake(to,from,0);
}

bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    int front=1,end=0;
    que[++end]=s;
    level[s]=1;
    while(front<=end)
    {
        int u=que[front++];
        if(u==t) return true;
        for(int k=head[u];k!=-1;k=e[k].next)
        {
            int v=e[k].to;
            if(!level[v]&&e[k].c)
            {
                que[++end]=v;
                level[v]=level[u]+1;
            }
        }
    }
    return false;
}

int dfs(int now,int t,int maxf)
{
    if(now==t) return maxf;
    int ret=0;
    for(int k=head[now];k!=-1;k=e[k].next)
    {
        int u=e[k].to;
        if(level[u]==level[now]+1&&e[k].c)
        {
            int f=dfs(u,t,min(e[k].c,maxf-ret));
            e[k].c-=f;
            e[k^1].c+=f;
            ret+=f;
            if(ret==maxf) return ret;
        }
    }
    return ret;
}

int maxflow(int s,int t)
{
    int ret=0;
    while(makelevel(s,t))
    {
        ret+=dfs(s,t,inf);
    }
    return ret;
}


void getdist()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        dist[i][j]=(x[i]-x[j])*(x[i]-x[j]);
        dist[i][j]+=(y[i]-y[j])*(y[i]-y[j]);
    }
}

void makegraph(int tt)
{
    edgeini();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i!=j)
    {
        if(st[j]>=ed[i])
        {
            long long tmp=(st[j]-ed[i])*(st[j]-ed[i]);
            if(tmp>=dist[i][j])
            {
                make(i,j+n,inf);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        make(0,i,sum[i][tt]);
        make(i+n,n+n+1,sum[i][tt]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&x[1],&y[1]);
        n--;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d %I64d %I64d %I64d",&x[i],&y[i],&st[i],&ed[i]);
            ed[i]+=st[i];
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&sum[i][j]);
                ans+=sum[i][j];
            }
        }
        getdist();
        for(int i=1;i<=m;i++)
        {
            makegraph(i);
            ans-=maxflow(0,n+n+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
