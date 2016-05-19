#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 31000
#define M 14
using namespace std;
typedef long long ll;
int nxt[N<<1],to[N<<1],val[N<<1],head[N],ce;
int a[N],fa[N],deep[N],fv[N][16],rt;
ll ans;
bool ban[N];
int in[N];
queue<int>q;
struct Tree
{
    int size[N][2];
    ll f[N][2],g[N][2];
    ll calc(int x,bool col)
    {
        ll ret=f[x][!col];
        for(int y=x;fa[y];y=fa[y])
            ret+=(ll)(size[fa[y]][!col]-size[y][!col])*(fv[x][deep[fa[y]]])+
            f[fa[y]][!col]-g[y][!col];
        return ret;
    }
}tr[M];
void init()
{
    ce=0;
    ans=0;
    memset(head,0,sizeof(head));
    memset(ban,0,sizeof(ban));
    memset(fv,0,sizeof(fv));
    memset(tr,0,sizeof(tr));
}
void add(int x,int y,int v)
{
    to[++ce]=y;
    val[ce]=v;
    nxt[ce]=head[x];
    head[x]=ce;
}
int getG(int x,int pre,int &g,int n)
{
    int temp,ma,size,i;
    for(i=head[x],ma=0,size=1;i;i=nxt[i])
    {
        if(!ban[to[i]]&&to[i]!=pre)
        {
            temp=getG(to[i],x,g,n);
            ma=max(temp,ma);
            size+=temp;
        }
    }
    ma=max(ma,n-size);
    if(ma<=n>>1)
        g=x;
    return size;
}
void dfs(int x,int pre,int dis,int dp)
{
    fv[x][dp]=dis;
    for(int i=head[x];i;i=nxt[i])
    {
        if(!ban[to[i]]&&to[i]!=pre)
        {
            dfs(to[i],x,dis+val[i],dp);
        }
    }
}
void Build(int x,int n)
{
    ban[x]=1;
    if(n==1)
        return ;
    int temp,i,g;
    dfs(x,0,0,deep[x]);
    for(i=head[x];i;i=nxt[i])
    {
        if(!ban[to[i]])
        {
            temp=getG(to[i],0,g,0);
            getG(to[i],0,g,temp);
            deep[g]=deep[x]+1;
            fa[g]=x;
            Build(g,temp);
        }
    }
}
void update(int x,int y)
{
    int i,j,k;
    for(i=0;i<M;i++)
    {
        ans-=(1ll<<i)*tr[i].calc(x,a[x]>>i&1);
    }
    for(i=0;i<M;i++)
        for(j=x;j;j=fa[j])
        {
            tr[i].size[j][a[x]>>i&1]--;
            tr[i].f[j][a[x]>>i&1]-=fv[x][deep[j]];
            tr[i].g[j][a[x]>>i&1]-=fv[x][deep[fa[j]]];
        }
    a[x]=y;
    for(i=0;i<M;i++)
        for(j=x;j;j=fa[j])
        {
            tr[i].size[j][a[x]>>i&1]++;
            tr[i].f[j][a[x]>>i&1]+=fv[x][deep[j]];
            tr[i].g[j][a[x]>>i&1]+=fv[x][deep[fa[j]]];
        }
    for(i=0;i<M;i++)
    {
        ans+=(1ll<<i)*tr[i].calc(x,a[x]>>i&1);
    }
}
int main()
{
    int n,m,i,j,k,x,y,v;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&v);
            add(x,y,v);
            add(y,x,v);
        }
        getG(1,0,rt,n);
        deep[rt]=fa[rt]=0;
        Build(rt,n);
        for(i=1;i<=n;i++)
        {
            in[fa[i]]++;
            for(j=0;j<M;j++)
            {
                for(k=i;fa[k];k=fa[k])
                {
                    tr[j].g[k][a[i]>>j&1]+=fv[i][deep[fa[k]]];
                }
            }
        }
        for(i=1;i<=n;i++)
            if(!in[i])
                q.push(i);
        while(!q.empty())
        {
            x=q.front(),q.pop();
            for(i=0;i<M;i++)
            {
                tr[i].size[x][a[x]>>i&1]++;
                tr[i].size[fa[x]][0]+=tr[i].size[x][0];
                tr[i].size[fa[x]][1]+=tr[i].size[x][1];
                tr[i].f[fa[x]][0]+=tr[i].g[x][0];
                tr[i].f[fa[x]][1]+=tr[i].g[x][1];
            }
            in[fa[x]]--;
            if(!in[fa[x]])
                q.push(fa[x]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<M;j++)
            {
                ans+=(1ll<<j)*tr[j].calc(i,a[i]>>j&1);
            }
        }
        ans>>=1;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            update(x,y);
            cout<<ans<<endl;
        }
    }
    return 0;
}
