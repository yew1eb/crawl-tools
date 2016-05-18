#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 20
const int inf=10000;
int n1,n2,n,m,f;
char g[N][N];
int x[N],y[N];
int dir[4][2]={0,1,0,-1,-1,0,1,0};
int dis[N][N],dist[N][N];
int dp[1<<15][N];
void inti()  //读入数据，把特殊点标号
{
    n1=0;
    int i,j;
    for(i=0; i<n; i++)
    {
        scanf("%s",g[i]);
        for(j=0; j<m; j++)
        {
            if(g[i][j]=='F')
            {
                f=n1;
                x[n1]=i;
                y[n1++]=j;
            }
            else if(g[i][j]=='Y')
            {
                x[n1]=i;
                y[n1++]=j;
            }
        }
    }
    n2=n1;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(g[i][j]=='G')
            {
                x[n2]=i;
                y[n2++]=j;
            }
}
void bfs(int x,int y,int dis[][20]) //求一个特殊点到其他各个点最短路
{
    int i,j,u,v;
    queue<int>q1,q2;
    q1.push(x);
    q2.push(y);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        dis[i][j]=inf;
    dis[x][y]=0;
    while(!q1.empty())
    {
        x=q1.front();
        y=q2.front();
        q1.pop();
        q2.pop();
        for(i=0;i<4;i++)
        {
            u=x+dir[i][0];
            v=y+dir[i][1];
            if(u<0||u>=n||v<0||v>=m||g[u][v]=='D')
                continue;
            if(dis[u][v]>dis[x][y]+1)
            {
                dis[u][v]=dis[x][y]+1;
                q1.push(u);
                q2.push(v);
            }
        }
    }
}
bool findd(int t)
{
    int i,j,k,lim=1<<n2,tmp=(1<<n1)-1;
    for(i=0;i<lim;i++)
        for(j=0;j<n2;j++)
        dp[i][j]=-inf;
    dp[1<<f][f]=t;
    for(i=1<<f;i<lim;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(dp[i][j]<0)
                continue;
            if((i&tmp)==tmp) //不一定要相等，包含目标状态就行
                return true;
            for(k=0;k<n2;k++)
            {
                int p=1<<k;
                if(i&p)
                    continue;
                dp[i|p][k]=max(dp[i|p][k],dp[i][j]-dis[j][k]);
                if(dp[i|p][k]>=0&&k>=n1)
                    dp[i|p][k]=t;
            }
        }
    }
    return false;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        inti();
        for(i=0; i<n2; i++)
        {
            bfs(x[i],y[i],dist);
            for(j=0; j<n2; j++)  //记录标号后的点相互之间距离
            {
                dis[i][j]=dist[x[j]][y[j]]; 
            }  //i到j的距离等于i点到各个点的最短路
        }
        
        int l=0,r=300,flag=0;
        while(l<=r)       //二分枚举各个可能的能量值
        {
            int mid=(l+r)/2;
            if(findd(mid))
            {
                flag=1;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(!flag)
            l=-1;
        printf("%d\n",l);
    }
    return 0;
}
