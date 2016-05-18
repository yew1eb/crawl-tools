#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=300005;
struct edge
{
    int to,next,col;
}oee[maxn<<1],ee[maxn];
int oecnt,oe[maxn],ecnt,e[maxn];
long long val[maxn],val1[maxn],val2[maxn],cnt[maxn],val3[maxn];
void addedge(int u,int v,int c)
{
    oee[oecnt].to=v;oee[oecnt].col=c;oee[oecnt].next=oe[u];oe[u]=oecnt;oecnt++;
    oee[oecnt].to=u;oee[oecnt].col=c;oee[oecnt].next=oe[v];oe[v]=oecnt;oecnt++;
}
void addedge2(int u,int v,int c)
{
    ee[ecnt].to=v;ee[ecnt].col=c;ee[ecnt].next=e[u];e[u]=ecnt++;
}
bool cmp(const edge &a,const edge &b)
{
    return a.col<b.col;
}
void dfs2(int f,int u)
{
    int i,j,v,c;
    vector<edge> vec;vec.clear();
    for(i=oe[u];i!=-1;i=oee[i].next)
    {
        v=oee[i].to;c=oee[i].col;
        if(v==f)
            continue;
        dfs2(u,v);
        vec.push_back(oee[i]);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(i=0;i<vec.size();++i)
    {
        v=vec[i].to;c=vec[i].col;
        addedge2(u,v,c);
    }
}
void dfs(int f,int fc,int u)
{
    int v,c,i,j,vv,cc;
    for(i=e[u];i!=-1;i=ee[i].next)
    {
        v=ee[i].to;c=ee[i].col;
        if(v==f)
            continue;
        dfs(u,c,v);
//        val1[u]+=val2[v]+cnt[v]*val[u]+val[u]+val[v];
            val1[u]+=val2[v]+(cnt[v]+1)*val[u]+val[v];
        if(c!=fc)
        {
//            val2[u]+=val2[v]+cnt[v]*val[u]+val[u]+val[v];
            val2[u]+=val2[v]+(cnt[v]+1)*val[u]+val[v];
            cnt[u]+=1+cnt[v];
        }
    }
//    for(i=e[u];i!=-1;i=ee[i].next)
//    {
//        for(j=ee[i].next;j!=-1;j=ee[j].next)
//        {
//            v=ee[i].to;c=ee[i].col;
//            vv=ee[j].to;cc=ee[j].col;
//            if(v==f||vv==f)
//                continue;
//            if(c==cc)
//                continue;
////            val3[u]+=val2[v]*cnt[vv]+val2[vv]*cnt[v]+cnt[v]*cnt[vv]*val[u]+val[u]+val[v]+val[vv]+cnt[v]*(val[u]+val[vv])+val2[v]+cnt[vv]*(val[u]+val[v])+val2[vv];
//            val3[u]+=val2[v]*(1+cnt[vv])+val2[vv]*(1+cnt[v])+val[v]*(1+cnt[vv])+val[vv]*(1+cnt[v])+val[u]*(1+cnt[v]+cnt[vv]+cnt[v]*cnt[vv]);
//        }
//    }
    long long sval2=0,scnt=0,sn=0,sval=0,pc=-1,sval22=0,scntt=0,snn=0,svall=0;
    for(i=e[u];i!=-1;i=ee[i].next)
    {
        v=ee[i].to;c=ee[i].col;
        if(c==pc)
        {
            val3[u]+=sval2*(1+cnt[v])+val2[v]*(sn+scnt)+sval*(1+cnt[v])+val[v]*(sn+scnt)+val[u]*(sn+scnt+sn*cnt[v]+scnt*cnt[v]);
            sval22+=val2[v];scntt+=cnt[v];snn++;svall+=val[v];
        }
        else
        {
            sval2+=sval22;sval22=val2[v];
            scnt+=scntt;scntt=cnt[v];
            sn+=snn;snn=1;
            sval+=svall;svall=val[v];
            pc=c;
            val3[u]+=sval2*(1+cnt[v])+val2[v]*(sn+scnt)+sval*(1+cnt[v])+val[v]*(sn+scnt)+val[u]*(sn+scnt+sn*cnt[v]+scnt*cnt[v]);
        }
    }
//    cout<<u<<'\t'<<val1[u]<<'\t'<<val2[u]<<'\t'<<cnt[u]<<'\t'<<val3[u]<<endl;
}
int main()
{
    int n,i,j,u,v,c;
    long long ans;
    while(scanf("%d",&n)!=EOF)
    {
        ecnt=0;memset(e,-1,sizeof(e));
        oecnt=0;memset(oe,-1,sizeof(oe));
        memset(val1,0,sizeof(val1));
        memset(val2,0,sizeof(val2));
        memset(val3,0,sizeof(val3));
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;++i)
            scanf("%I64d",&val[i]);
        for(i=1;i<n;++i)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        dfs2(-1,1);
        dfs(-1,-1,1);
        ans=0;
        for(i=1;i<=n;++i)
        {
            ans+=val1[i]+val3[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
