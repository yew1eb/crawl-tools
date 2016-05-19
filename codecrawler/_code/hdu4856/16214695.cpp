#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=1<<29;
const int maxn=40;
const int maxm=(1<<15)+1000;
struct Tunnel
{
    int x1;
    int y1;
    int x2;
    int y2;
    int id;
}t[maxn];
struct Node
{
    int x;
    int y;
    int ans;
    Node(){}
    Node(int sx,int sy,int sans)
    {
        x=sx;
        y=sy;
        ans=sans;
    }
};
int n,m,des,vis[maxn][maxn],dis[maxn][maxn];
int movex[4]={1,-1,0,0},movey[4]={0,0,1,-1};
int e,st,dp[maxn][maxm];
char map[maxn][maxn];
queue<Node> q;
bool isborder(int x,int y)
{
    if(x<1||x>n||y<1||y>n)
        return true;
    return false;
}
void Build()
{
    for(int i=0;i<m;i++)
    {
        memset(vis,-1,sizeof(vis));
        int sx=t[i].x2,sy=t[i].y2;
        q.push(Node(sx,sy,0));
        vis[sx][sy]=0;
        while(!q.empty())
        {
            Node u=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                int itx=u.x+movex[j];
                int ity=u.y+movey[j];
                if(isborder(itx,ity)||map[itx][ity]=='#'||vis[itx][ity]!=-1)
                    continue;
                vis[itx][ity]=u.ans+1;
                q.push(Node(itx,ity,u.ans+1));
            }
        }
        for(int j=0;j<m;j++)
        {
            if(i!=j&&vis[t[j].x1][t[j].y1]!=-1)
                dis[i][j]=vis[t[j].x1][t[j].y1];
            else
                dis[i][j]=inf;
        }
    }
}
void solve()
{
    des=1<<m;
    for(int i=0;i<des;i++)
        for(int j=0;j<m;j++)
            dp[j][i]=inf;
    for(int i=0;i<m;i++)
        dp[i][1<<i]=0;
    for(int i=0;i<des;i++)
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
                continue;
            for(int k=0;k<m;k++)
                dp[j][i|(1<<j)]=min(dp[j][i|(1<<j)],dp[k][i]+dis[k][j]);
        }
    int ans=inf;
    for(int i=0;i<m;i++)
        ans=min(ans,dp[i][des-1]);
    if(ans>=inf)
        printf("-1\n");
    else
        printf("%d\n",ans);

}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",map[i]+1);
        for(int i=0;i<m;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&t[i].x1,&t[i].y1,&t[i].x2,&t[i].y2);
            t[i].id=i;
        }
        Build();
        solve();
    }
    return 0;
}

