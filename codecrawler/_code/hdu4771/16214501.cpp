#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#define inf 2100000000
using namespace std;
char map[110][110];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int po[5][2];
int mp[5][5];
int dist[110][110];
int n,m,k;
void getin()
{
    int i,j;
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(map[i][j]=='@')
                {
                    po[0][0]=i;
                    po[0][1]=j;
                    map[i][j]='.';
                    return;
                }
            }
        }
}
bool check(int x,int y)
{
    if(x<1||y<1||x>n||y>m||map[x][y]=='#'||dist[x][y]!=inf)
    return false;
    return true;
}
void bfs(int now)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        dist[i][j]=inf;
    }
      queue<int> q;
      int x=po[now][0],y=po[now][1];
      dist[x][y]=0;
      q.push(x);
      q.push(y);
      while(!q.empty())
      {
          x=q.front();q.pop();
          y=q.front();q.pop();
          for(i=0;i<4;i++)
          {
              int xx=x+dir[i][0],yy=y+dir[i][1];
              if(check(xx,yy))
              {
                  dist[xx][yy]=dist[x][y]+1;
                  q.push(xx);
                  q.push(yy);
              }
          }
      }
      for(i=0;i<=k;i++)
      {
          mp[now][i]=dist[po[i][0]][po[i][1]];
      }
}
int vis[5];
int tmp,ans;
void dfs(int now,int num)
{
    if(num==k)
    {
        ans=min(ans,tmp);
        return;
    }
    for(int i=1;i<=k;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            tmp+=mp[now][i];
            dfs(i,num+1);
            vis[i]=0;
            tmp-=mp[now][i];
        }
    }
}
int main()
{
   // freopen("dd.txt","r",stdin);
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        int i,j;
        for(i=1;i<=n;i++)
        scanf("%s",map[i]+1);
        scanf("%d",&k);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=k;i++)
        scanf("%d%d",&po[i][0],&po[i][1]);
        getin();
        for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        mp[i][j]=inf;
        for(i=0;i<=k;i++)
        {
            bfs(i);
        }
        int tru=1;
        for(i=0;i<=k;i++)
        {
            if(mp[0][i]==inf)
            {
                tru=0;
                break;
            }
        }
        ans=inf;
        if(!tru)
        printf("%d\n",-1);
        else
        {
            tmp=0;
            for(i=1;i<=k;i++)
            {
                tmp+=mp[0][i];
                vis[i]=1;
                dfs(i,1);
                vis[i]=0;
                tmp-=mp[0][i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}