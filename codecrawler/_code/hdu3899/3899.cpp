#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
//内存挂
const int maxn=100002;
int n,m,cnt[maxn],tn[maxn];///每个点的人数
__int64 dis[maxn];///最后要求结果
struct node
{
    __int64 dis;
    int v;
}tmp;
vector<node>p[maxn<<1];
void dfs(int u,int fa,__int64 len)
{
    int i,j,v;
    int sum=p[u].size();
    dis[1]+=len*cnt[u];
    tn[u]=cnt[u];
    for(i=0;i<sum;i++)
    {
        int v=p[u][i].v;
        if(v==fa)continue;
        dfs(v,u,len+p[u][i].dis);
        tn[u]+=tn[v];
    }
}
void dfs1(int u,int fa)
{
    int size=p[u].size();
    for(int i=0;i<size;i++)
    {
        int v=p[u][i].v;
        __int64 w=p[u][i].dis;
        if(v==fa) continue;
        dis[v]=dis[u]+(tn[1]-2*tn[v])*w;
         ///对于一条边，求出这条边上面所以边的长度和和下面所有边的长度和，然后就可以进行转移了
        dfs1(v,u);
    }
}
int main()
{
    int u,v,i,j;
    __int64 w;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
          scanf("%d",&cnt[i]);
          dis[i]=0;
          p[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d %I64d",&u,&v,&w);
            tmp.v=v,tmp.dis=w;
            p[u].push_back(tmp);
            tmp.v=u,tmp.dis=w;
            p[v].push_back(tmp);
        }
        dfs(1,-1,0);
        __int64 ans=dis[1];
        dfs1(1,0);
        for(i=2;i<=n;i++)
        {
            if(ans>dis[i]) ans=dis[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
3
1
1
2
1 2 2
2 3 1
4
100
1
1
1
1 2 1
2 3 1
2 4 1
*/
