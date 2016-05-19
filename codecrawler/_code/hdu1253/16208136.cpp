#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int map[55][55][55];
int vis[55][55][55];
int d[55][55][55];
int xx[6]={0,0,0,0,-1,1};
int yy[6]={0,0,1,-1,0,0};
int zz[6]={1,-1,0,0,0,0};
void bfs()
{
  queue<int> q;
  vis[1][1][1]=1;
  d[1][1][1]=0;
  int s=1*10000+100+1;
  q.push(s);
  while(!q.empty())
  {
      s=q.front();
      q.pop();
      int i;
      int x,y,z;
      int tz=s%100;
      s=s/100;
      int ty=s%100;
      s=s/100;
      int tx=s;
      for(i=0;i<6;i++)
      {
          x=tx+xx[i];
          y=ty+yy[i];
          z=tz+zz[i];
          if(vis[x][y][z]==1||map[x][y][z]==1||map[x][y][z]==-1)
                continue;
          vis[x][y][z]=1;
          d[x][y][z]=d[tx][ty][tz]+1;
          q.push(x*10000+y*100+z);
      }
  }
}
int main()
{
    int k;
    scanf("%d",&k);
    int cas=1;
    for(cas=1;cas<=k;cas++)
    {
        int a,b,c,t;
        scanf("%d%d%d%d",&a,&b,&c,&t);
        int i,j,l;
        memset(map,-1,sizeof(map));
        memset(vis,0,sizeof(vis));
        memset(d,-1,sizeof(d));
        for(i=1;i<=a;i++)
            for(j=1;j<=b;j++)
                for(l=1;l<=c;l++)
                    scanf("%d",&map[i][j][l]);
        bfs();
        if(d[a][b][c]<=t&&d[a][b][c]!=-1)
            printf("%d\n",d[a][b][c]);
        else
            printf("-1\n");
    }
    return 0;
}
