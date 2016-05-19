/**
hdu 4340 树形dp
题目大意：
          给定一棵树，为每一个点染色，有a和b两种颜色，染色的费用分别为a[i]和b[i]，如果与i点相邻的点被染上了
          a色那么染i点只需花费a[i]/2，b色同a。问把所有点全部染色需要的最小费用。
解题思路：dp[i][j][k](i:1~n;j;0~1;k:0~1)表示以i为根节点的树i点染j色并且该子树中有k个点全价染j色。
           x1为i点染a色时，它的儿子节点的最小花费（此时子树中与i连通的点均还是半价，还没有全价点）
           y1为i点染a色时，以它的儿子节点为根的子树中，从全部不全价的点到有一个全价点的改变所需最小费用
           x2,y2同理。
           状态转移方程： dp[u][0][0]=a[u]/2+x1; dp[u][0][1]=min(x1+a[u],x1+a[u]/2+y1);
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=105;

int head[maxn],ip;
int n,a[maxn],b[maxn],dp[maxn][2][2];

struct note
{
    int v,next;
}edge[maxn*4];

void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}

void addedge(int u,int v)
{
    edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}

void dfs(int u,int pre)
{
    int flag=0;
    int x1=0,x2=0,y1=0x3f3f3f3f,y2=0x3f3f3f3f;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==pre)continue;
        flag=1;
        dfs(v,u);
        x1+=min(dp[v][0][0],dp[v][1][1]);
        x2+=min(dp[v][1][0],dp[v][0][1]);
        y1=min(y1,dp[v][0][1]-min(dp[v][0][0],dp[v][1][1]));
        y2=min(y2,dp[v][1][1]-min(dp[v][1][0],dp[v][0][1]));
    }
    if(flag==0)
    {
        dp[u][0][0]=a[u]/2;
        dp[u][0][1]=a[u];
        dp[u][1][0]=b[u]/2;
        dp[u][1][1]=b[u];
    }
    else
    {
        dp[u][0][0]=a[u]/2+x1;
        dp[u][1][0]=b[u]/2+x2;
        dp[u][0][1]=min(x1+a[u],x1+a[u]/2+y1);
        dp[u][1][1]=min(x2+b[u],x2+b[u]/2+y2);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        init();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,-1);
        printf("%d\n",min(dp[1][1][1],dp[1][0][1]));
    }
    return 0;
}
