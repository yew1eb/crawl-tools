#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 111111
struct edge{
    int to,next;
}e[N*2];
bool mark[N];
int a[N],q[N],tot,f[N],head[N],tp,siz[N],cnt[N];
void add(int u,int v)
{
    e[tp].to=v;
    e[tp].next=head[u];
    head[u]=tp++;
}
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
void dfs(int u,int fa)
{
    siz[u]=1;
    for(int i=head[u];i>=0;i=e[i].next)
    {
        int v=e[i].to;
        if(mark[v]||v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int b[N],cnt2[N];
int solve(int k)
{
    int ret;
    b[0]=siz[q[0]];
    for(int i=0;i<k;i++)
    cnt2[i]=0;
    cnt2[b[0]%k]++;
    for(int i=1;i<tot;i++)
    {
        b[i]=b[i-1]+siz[q[i]];
        cnt2[b[i]%k]++;
    }
    ret=cnt2[0];
    for(int i=0;i<tot;i++)
    {
        int t=b[i];
        int j=i-1;
        if(j==-1)j+=tot;
        cnt2[b[i]%k]--;
        b[i]=b[j]+siz[q[i]];
        cnt2[b[i]%k]++;
        ret=max(ret,cnt2[t]);
    }
    return ret;
}
int main()
{
//    freopen("1003.in","r",stdin);
//    freopen("out.out","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        tot=0;
        tp=0;
        for(int i=1;i<=n;i++)f[i]=i,mark[i]=false,head[i]=-1,cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(find(a[i])!=find(i))
            {
                f[find(a[i])]=find(i);
                add(a[i],i);
                add(i,a[i]);
            }
            else {
                q[tot++]=i;
                mark[i]=true;
            }
        }
        for(int i=0;i<tot;i++)
        {
            if(!mark[a[q[i]]]){
                q[tot++]=a[q[i]];
                mark[a[q[i]]]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(mark[i])
                dfs(i,-1);
        }
        for(int i=1;i<=n;i++)
        {
            if(!mark[i])
            cnt[siz[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+i;j<=n;j+=i)
            {
                cnt[i]+=cnt[j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                if(solve(i)+cnt[i]==n/i)ans++;
            }
        }
        printf("%d\n",ans);
    }
    
}