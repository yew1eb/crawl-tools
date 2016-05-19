#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define eps 1e-8
typedef __int64 ll;

using namespace std;

#define INF 0x3f3f3f3f
#define N 105

struct stud{
  int x,y,step;
  int va;
};

queue<stud>q;

int n,m;
int step[4][2]={1,0,-1,0,0,1,0,-1};
int vis[1<<4][N][N];
int sx,sy;
char c[N][N];

char get(char c)
{
    if(c=='R') return 'A';
    if(c=='r') return 'a';
    if(c=='B') return 'B';
    if(c=='b') return 'b';
    if(c=='Y') return 'C';
    if(c=='y') return 'c';
    if(c=='G') return 'D';
    if(c=='g') return 'd';
    if(c=='#') return '#';
    if(c=='*') return '*';
    if(c=='.') return '.';
    return 'X';
}

inline bool judge(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}

void bfs()
{
    int i,j;
    stud cur,next;
    while(!q.empty()) q.pop();
    cur.x=sx;
    cur.y=sy;
    cur.step=0;
    cur.va=0;
    memset(vis,0,sizeof(vis));
    vis[0][sx][sy]=1;
    q.push(cur);
    while(!q.empty())
    {
       cur=q.front();
       q.pop();
       if(c[cur.x][cur.y]=='X')
       {
           printf("Escape possible in %d steps.\n",cur.step);
           return ;
       }
       for(i=0;i<4;i++)
       {
           int xx=cur.x+step[i][0];
           int yy=cur.y+step[i][1];
           if(!judge(xx,yy)) continue;
           if(c[xx][yy]=='#') continue;
           if(vis[cur.va][xx][yy]) continue;
           if(c[xx][yy]>='A'&&c[xx][yy]<='D'&&!(cur.va&(1<<(c[xx][yy]-'A')))) continue;
           next.x=xx;
           next.y=yy;
           next.step=cur.step+1;
           next.va=cur.va;
           if(c[xx][yy]>='a'&&c[xx][yy]<='d')
            next.va|=1<<(c[xx][yy]-'a');
            vis[next.va][xx][yy]=1;
            q.push(next);
       }
    }
   printf("The poor student is trapped!\n");
}
int main()
{
   int i,j;
   while(scanf("%d%d",&n,&m),n+m)
   {
      for(i=0;i<n;i++)
        scanf("%s",c[i]);
      for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          if(c[i][j]=='*')
      {
          sx=i;
          sy=j;
      }
      else
          c[i][j]=get(c[i][j]);

//      for(i=0;i<n;i++)
//         printf("%s\n",c[i]);
      bfs();
   }
  return 0;
}
