/*
类似于网络流24题中的一道（求最长上升子序列的最多个数）：
构图方案：
首先求出LIS；
然后拆点 建边Edge(i,i+n,1) 因为没个点只能用一次，所以边的容量为1
然后对于每个dp[i]==1的建边Edge(s,i,1)
dp[i]==k的建边Edge(i+n,t,1);
dp[i]==dp[j]+1 建边Edge(j+n,i,1);
然后sap 求最大流就OK了
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define M 10100
int gap[M],dis[M],pre[M],cur[M],dp[M];
int NE,NV,sink,source;
int head[M],p[M],k,n;
struct Node
{
    int c,pos,next;
} E[999999];
#define FF(i,NV) for(int i=0;i<NV;i++)
int sap(int s,int t)
{
    //memset(pre,-1,sizeof(pre));
    memset(dis,0,sizeof(int)*(NV+1));
    memset(gap,0,sizeof(int)*(NV+1));
    FF(i,NV) cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug = 1<<29;
    gap[0] = NV;
    while(dis[s] < NV)
    {
loop:
        for(int &i = cur[u]; i != -1; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && dis[u] == dis[v] + 1)
            {
                aug=min(aug,E[i].c);
                pre[v] = u;
                u = v;
                if(v == t)
                {
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u,u = pre[u])
                    {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug = 1<<29;
                }

                goto loop;
            }
        }

        int mindis = NV;
        for(int i = head[u]; i != -1 ; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && mindis > dis[v])
            {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if( (--gap[dis[u]]) == 0)break;
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}
void addEdge(int u,int v,int c )
{
    E[NE].c = c;
    E[NE].pos = v;
    E[NE].next = head[u];
    head[u] = NE++;
    E[NE].c = 0;
    E[NE].pos = u;
    E[NE].next = head[v];
    head[v] = NE++;
}
int LIS()
{
    int i,j,ans=0;
    dp[1]=1;
    for(i=2;i<=n;++i)
    {
        dp[i]=1;
         for(j=1;j<i;++j)
         {
             if(p[j]<p[i]&&dp[j]>=dp[i])dp[i]=dp[j]+1;
         }
         ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        NE=source=0;
        sink=n<<1|1;
        NV=sink+1;
        memset(head,-1,sizeof(head));
       // memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
        }
        k=LIS();
        for(i=1;i<=n;i++)
        {
            addEdge(i,i+n,1);
            if(dp[i]==1)
            addEdge(source,i,1);
            if(dp[i]==k)
            addEdge(i+n,sink,1);
            for(j=i+1;j<=n;++j)
               if(dp[j]==dp[i]+1)addEdge(i+n,j,n);
        }
        printf("%d\n%d\n",k,sap(source,sink));
    }
    return 0;
}
/*
4
3 6 2 5
*/
