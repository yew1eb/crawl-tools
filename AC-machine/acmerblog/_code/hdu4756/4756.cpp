#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
#define INF 2000000000
#define N 1005
double sum;
double dis[N][N];
double dp[N][N];
bool vis[N][N];
bool flag[N];
double lowcost[N];
int pre[N];
struct node
{
    int x,y;
};
vector<int> tree[N];
int n,m,num;
struct point{double x,y;}p[1005];
inline double g_dis(point &A,point &B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
void prim()
{
    sum=0;
    int i,j;
    memset(flag,false,sizeof(flag));
    for(i=1;i<=n;i++)
    {
        lowcost[i]=dis[1][i];
        pre[i]=1;
    }
    flag[1]=true;
    for(i=1;i<n;i++)
    {
        double mins=INF;
        int v;
        for(j=1;j<=n;j++)
        {
            if(flag[j] == false && lowcost[j] < mins)
            {
                mins=lowcost[j];
                v=j;
            }
        }
        sum+=mins;
        vis[pre[v]][v] = vis[v][pre[v]] = true;
        tree[v].push_back(pre[v]);
        tree[pre[v]].push_back(v);
        flag[v] = true;
        for(j=1;j<=n;j++)
        {
            if(flag[j] == false && lowcost[j] > dis[v][j])
            {
                lowcost[j] = dis[v][j];
                pre[j] = v;
            }
        }
    }
}
double dfs(int root,int now,int fa=-1)
{
    double ret = INF;
    for(int i = 0;i<tree[now].size();i++)
    {
        int to=tree[now][i];
        if(to!=fa){
        double tmp = dfs(root,to,now);
        ret=min(tmp,ret);
        dp[now][to] = dp[to][now] = min(tmp,dp[now][to]);
        }
    }
    if(root!=fa)
        ret=min(ret,dis[root][now]);
    return ret;
}
int main()
{
    int cas,k;
    double x,y;
    int i,j;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        {
            tree[i].clear();
            scanf("%lf%lf",&x,&y);
            p[i].x=x;p[i].y=y;
            tree[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                vis[i][j]=false;
                if(i==j) dis[i][j]=0;
                else dis[i][j]=g_dis(p[i],p[j]);
                dp[i][j]=INF;
            }
        }
        prim();
        double ans=sum;
        for(i=1;i<=n;i++) dfs(i,i);
        for(i=2;i<=n;i++)
        {
            for(j=2;j<i;j++)
            {
                if(vis[i][j])
                {
                    ans=max(ans,sum-dis[i][j]+dp[i][j]);
                }
            }
        }
        printf("%.2lf\n",ans*k);
    }
    return 0;
}
