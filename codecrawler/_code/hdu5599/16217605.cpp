#include<bits/stdc++.h>
using namespace std;
const int Maxn=200020,M=1e9+7,N=100020;
typedef pair<int,int>pi;
int isp[N],cnt_pri,pri[N];
vector<int>yinzi[N];
vector<int>G[Maxn];
vector<pi>pro[N];
int n,tl;
int is[Maxn],id[Maxn],ct[22];
int f[Maxn],sz[Maxn],in[Maxn];
int find(int x)
{
    int a;
    for(a=x;f[a]!=a;a=f[a]);
    for(;f[x]!=a;)
    {
        int t=f[x];f[x]=a;
        x=t;
    }
    return a;
}
int powmod(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=1LL*ret*x%M;
        y>>=1;
        x=1LL*x*x%M;
    }
    return ret;
}
int solve()
{
    int ret=1;
    for(int it=0;it<cnt_pri;it++)
    {
        int cur=0;
        int p=pri[it];
        if(pro[p].empty())continue;
        tl++;
        for(int i=0;i<pro[p].size();i++)
        {
            int u=pro[p][i].second,w=pro[p][i].first;
            if(is[u])continue;
            cur=(cur+w)%(M-1);
            sz[u]=1;f[u]=u;
            in[u]=tl;
            for(int j=0;j<G[u].size();j++)
            {
                int v=G[u][j];
                if(in[v]<tl)continue;
                int uu=find(u),vv=find(v);
                cur+=1LL*sz[uu]*sz[vv]%(M-1)*w%(M-1);
                if(cur>=M-1)cur-=M-1;
                if(sz[uu]>sz[vv]){f[vv]=uu;sz[uu]+=sz[vv];}
                else{f[uu]=vv;sz[vv]+=sz[uu];}
            }
        }
        ret=1LL*ret*powmod(p,cur)%M;
    }
    return ret;
}
int main()
{
    for(int i=2;i<N;i++)
    {
        if(!isp[i])
        {
            for(int j=i;j<N;j+=i)
            {
                yinzi[j].push_back(i);
                isp[j]=1;
            }
            pri[cnt_pri++]=i;
        }
    }
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            is[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0;i<cnt_pri;i++)pro[pri[i]].clear();
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            for(int j=0;j<yinzi[x].size();j++)
            {
                int cnt=0,tp=x,p=yinzi[x][j];
                while(tp%p==0)cnt++,tp/=p;
                pro[p].push_back(pi(cnt,i));
            }
        }
        for(int i=0;i<cnt_pri;i++)
            sort(pro[pri[i]].begin(),pro[pri[i]].end(),greater<pi>());
        int ans1=solve();
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int x;scanf("%d",&x);
            is[x]=1;
        }
        int ans2=solve();
        ans1=1LL*ans1*powmod(ans2,M-2)%M;
        printf("%d\n",ans1);
    }
}