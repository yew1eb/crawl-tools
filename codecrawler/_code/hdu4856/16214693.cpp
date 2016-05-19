#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAXN 55
#define LL long long
#define INF 0x3f7f7f7f
const double eps = 1e-10;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int dis[MAXN*MAXN][MAXN*MAXN];
int v[MAXN];
int n,m,num;
struct node
{
    node(int x=0,int y=0,int s=0):x(x),y(y),s(s){}
    friend bool operator==(node a,node b)
    {
        if(a.x==b.x&&a.y==b.y)return true;
        return false;
    }
    int x,y,s;
};
struct node tx;
struct edge
{
    node st,en;
}E[MAXN*MAXN*10];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int bfs(node st,node en)
{
    queue<node>q;
    st.s=0;
    q.push(st);
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        tx=q.front();
        if(tx.x==en.x&&tx.y==en.y)
        {
            return tx.s;
        }
        q.pop();
        for(int i=0;i<=3;i++)
        {
            int xx=tx.x+dir[i][1];
            int yy=tx.y+dir[i][0];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&maze[xx][yy]!='#'&&!vis[xx][yy])
            {
                vis[xx][yy]=1;
                q.push(node(xx,yy,tx.s+1));
            }
        }
    }
    return INF;
}
int dp[16][1<<16];
void solve()
{

    int i,j,k;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==j)
                dis[i][j]=0;
            else dis[i][j]=bfs(E[i].en,E[j].st);
          //  cout<<dis[i][j]<<" ";
        }
       // cout<<endl;
    }
    for(i=0;i<=15;i++)
        for(j=0;j<(1<<15);j++)
        {
            dp[i][j]=INF;
            if(j==0)
                dp[i][j]=0;
        }
    for(i=1;i<=m;i++)
        dp[i][1<<(i-1)]=0;

    for(i=1;i<(1<<m);i++)//åæä¸¾ç¶æ
    {
        for(k=1;k<=m;k++)//ä»¥åªä¸ªç¹ç»æ
        {
            if((1<<(k-1))&i)//è¿ä¸ªç¹å¯¹åºä½å¿é¡»ä¸º1
            for(j=1;j<=m;j++)//æä¸¾ä¸ä¸ä¸ªç¹j
            {
                if(((1<<(j-1))&i)==0&&j!=k)//jç¹å¿é¡»æ²¡èµ°è¿èä¸ä¸è½ç­äºk
                {
                    dp[j][(1<<(j-1))|i]=min(dp[j][(1<<(j-1))|i],dp[k][i]+dis[k][j]);
                }
            }
        }
    }
    int ans=INF;
    for(i=1;i<=m;i++)
    {
        //cout<<"\\"<<dp[i][(1<<m)-1]<<endl;
        ans=min(ans,dp[i][(1<<m)-1]);
    }
    if(ans==INF)
        printf("-1\n");
    else printf("%d\n",ans);
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",maze[i]+1);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&E[i].st.x,&E[i].st.y,&E[i].en.x,&E[i].en.y);
        }
        solve();
    }
    return 0;
}
