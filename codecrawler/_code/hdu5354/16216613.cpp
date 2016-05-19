#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
const int Maxn=100020;
int rep[Maxn];
int n,m;
vector<pi>ee[Maxn<<2];
int f[Maxn],sz[Maxn],val[Maxn];
bool in(int a,int L,int R)
{
    return a>=L&&a<=R;
}
void process(int l,int r,int x,vector<pi>&tp);
pi find(int x)
{
    int ret=x;
    int w=0;
    for(;f[ret]!=ret;ret=f[ret])w^=val[ret];
    w^=val[ret];
    return pi(ret,w);
}
void solve(int l,int r,int x)
{
    if(l==r){rep[l]=1;return;}
    int mid=(l+r)>>1;
    ee[x<<1].clear();ee[x<<1|1].clear();
    vector<pi>tp[2];
    for(int i=0;i<ee[x].size();i++)
    {
        int a=ee[x][i].first,b=ee[x][i].second;
        if(in(a,l,mid)||in(b,l,mid))ee[x<<1].push_back(ee[x][i]);
        else tp[0].push_back(ee[x][i]);
        if(in(a,mid+1,r)||in(b,mid+1,r))ee[x<<1|1].push_back(ee[x][i]);
        else tp[1].push_back(ee[x][i]);
    }
    process(l,mid,x<<1,tp[0]);
    process(mid+1,r,x<<1|1,tp[1]);    
}
void process(int l,int r,int x,vector<pi>&tp)
{
    vector<pi>res;
    bool flag=0;
    for(int i=0;i<tp.size();i++)
    {
        int u=tp[i].first,v=tp[i].second;
        pi fu=find(u),fv=find(v);
        if(fu.first==fv.first)
        {
            if(!(fu.second^fv.second))
            {
                flag=1;
                break;
            }
        }
        else
        {
            int t1=sz[fu.first]>sz[fv.first]?fu.first:fv.first;
            int t2=fu.first+fv.first-t1;
        int t3=fu.second^fv.second;
            f[t2]=t1;
            sz[t1]+=sz[t2];
            res.push_back(pi(t2,t3));
            val[t2]^=t3;
        }
    }
    if(flag)
    {
        for(int i=l;i<=r;i++)rep[i]=0;
    }
    else    solve(l,r,x);
    for(int i=res.size()-1;i>=0;i--)
    {
        int u=res[i].first;
        sz[f[u]]-=sz[u];
        val[u]^=res[i].second;
        f[u]=u;
    }
}
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)f[i]=i,sz[i]=1,val[i]=1;
        ee[1].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            if(u>v)swap(u,v);
            ee[1].push_back(pi(u,v));
        }
        solve(1,n,1);
        for(int i=1;i<=n;i++)putchar(rep[i]+'0');puts("");
    }
}