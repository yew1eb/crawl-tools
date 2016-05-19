#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define NMAX 2002
#define CMAX 5002
#define MMAX 1002
int C,N,K,M;
int to[MMAX<<1],next[MMAX<<1],head[NMAX],edge;
int dp[NMAX][2],hav[NMAX];
bool vis[NMAX];
struct node
{
    int x,belong;
} city[CMAX];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
void init()
{
    memset(hav,0,sizeof(hav));
    memset(head,-1,sizeof(head));
    edge=0;
}
inline void add(int u,int v)
{
    to[edge]=v,next[edge]=head[u],head[u]=edge++;
    to[edge]=u,next[edge]=head[v],head[v]=edge++;
}
void dfs(int now)
{
    vis[now]=true;
    dp[now][0]=0;
    dp[now][1]=1;
    for(int i=head[now],v; ~i; i=next[i])
    {
        v=to[i];
        if(!vis[v]&&hav[v])
        {
            dfs(v);
            dp[now][0]+=max(dp[v][0],dp[v][1]);
            dp[now][1]+=dp[v][0];
        }
    }
}
bool ok()
{
    memset(vis,0,sizeof(vis));
    int res=0;
    for(int i=1; i<=N; i++)
    {
        if(hav[i]&&!vis[i])
        {
            dfs(i);
            res+=max(dp[i][0],dp[i][1]);
        }
    }
    return res>=K;
}
int main()
{
    int T,u,v;
    scanf("%d",&T);
    for(int ca=1; ca<=T; ca++)
    {
        init();
        scanf("%d%d%d%d",&C,&N,&K,&M);
        for(int i=0; i<C; i++)
            scanf("%d%d",&city[i].x,&city[i].belong);
        sort(city,city+C,cmp);
        for(int i=0; i<M; i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        int l,r,ans=-1;
        l=r=0;
        int cNum=1;
        hav[city[0].belong]=1;
        while(l<C&&r<C)
        {
            bool flag=false;
            if(cNum>=K)
            {
                if(ok())
                {
                    flag=true;
                    if(ans==-1)
                        ans=city[r].x-city[l].x;
                    else
                        ans=min(ans,city[r].x-city[l].x);
                }
            }
            if(flag)
            {
                --hav[city[l].belong];
                if(hav[city[l].belong]==0)
                    --cNum;
                ++l;
            }
            else
            {
                ++r;
                if(hav[city[r].belong]==0)
                    ++cNum;
                ++hav[city[r].belong];
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}