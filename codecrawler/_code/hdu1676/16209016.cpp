//250MS    4900K
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define M 1007
using namespace std;
int n,m,cap,s,e,num;
int val[M],dp[M][M],head[M];
struct node
{
    int u,cost,res;//uä»£è¡¨èç¹ï¼costä»£è¡¨å½åèç¹çè±è´¹ï¼resä»£è¡¨æ­¤èç¹å©ä½çæ²¹
    bool operator < (const node a)const
    {
        return cost>a.cost;
    }
};
struct E
{
    int v,to,dist;
} edg[M*20];
vector<int>G[M];
void addedge(int u,int v,int dist)
{
    edg[num].v=v;
    edg[num].dist=dist;
    edg[num].to=head[u];
    head[u]=num++;
}
void init()
{
    num=0;
    memset(head,-1,sizeof(head));
    memset(val,0,sizeof(val));
    for(int i=0; i<n; i++)
        G[i].clear();
}
void bfs()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<=cap; j++)
            dp[i][j]=0;
    priority_queue<node> q;
    q.push((node){s,0,0});
    while(!q.empty())
    {
        node x=q.top();
        q.pop();
        int u=x.u,cost=x.cost,res=x.res;
        if(u==e)
        {
            printf("%d\n",cost);
            return ;
        }
        if(res<cap&&(dp[u][res+1]==0||dp[u][res+1]>cost+val[u]))//å¦æå¤å 1åä½æ²¹ï¼è½å¤è±è´¹æ´å°
        {
            dp[u][res+1]=cost+val[u];
            q.push((node){u,dp[u][res+1],res+1});
        }
        for(int i=head[u]; i!=-1; i=edg[i].to)//æ´æ°ä¸æ­¤èç¹ç¸é»çèç¹
        {
            int v=edg[i].v,dist=edg[i].dist;
            if(res<dist)continue;//å½åæ²¹éä¸å¤å°è¾¾ä¸ä¸ä¸ªèç¹
            if(dp[v][res-dist]==0||dp[v][res-dist]>cost)//è½å¤è¾¾å°ä¸ä¸ä¸ªèç¹ï¼èä¸è±è´¹æ´å°
            {
                dp[v][res-dist]=cost;
                q.push((node){v,cost,res-dist});
            }
        }
    }
    printf("impossible\n");
    return ;
}
int main()
{
    while( scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0; i<n; i++)
            scanf("%d",&val[i]);
        int a,b,c;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&cap,&s,&e);
            bfs();
        }
    }
    return 0;
}
