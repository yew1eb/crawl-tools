#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<fstream>

using namespace std;
class node
{
    public:
        int x;
        int y;
        int step;
        int people_x;
        int people_y;
        friend bool operator <(node a,node b)
        {
              return a.step>b.step;
        }
}cur,next;
priority_queue<node>q;
int d[4][2]={1,0,-1,0,0,1,0,-1};
int visit[10][10][10][10];
int visit2[10][10];
int map[10][10];
bool flag;
int m,n;
int start1_x,start1_y;
int start2_x,start2_y;
int end_x,end_y;

void  init()
{
        memset(visit,0,sizeof(visit));
        memset(map,1,sizeof(map));
        memset(visit2,0,sizeof(visit2));
        flag=0;

}
int flag1=0;
int cur_x,cur_y;
bool dfs(int x,int  y,int cur_x, int cur_y ,int people_x,int people_y)
{
        visit2[x][y]=1;

        if(x==people_x&&y==people_y) {flag1=1;return true;}
        if(flag1==0)
        for(int i=0;i<4;i++)
        {
             int xx=x+d[i][0];
             int yy=y+d[i][1];
             if(xx>m||xx<1||yy>n||yy<1||map[xx][yy]==1||visit2[xx][yy]||(xx==cur_x&&yy==cur_y)) continue;
              
             dfs(xx,yy,cur_x,cur_y,people_x,people_y);
             if(flag1) return true;
        }
        return false;
       
}
void bfs()
{
       while(!q.empty())
       {
               cur=q.top();
               q.pop();
               if(cur.x==end_x&&cur.y==end_y)
               {
                       cout<<cur.step<<endl;
                       flag=1;
                       break;
               }
               for(int i=0;i<4;i++)
               {
                      memset(visit2,0,sizeof(visit2));
                      flag1=0;
                      int  x=cur.x+d[i][0];
                      int  y=cur.y+d[i][1];
                  
                      if(x>m||x<1||y>n||y<1||map[x][y]==1) continue;
                       next.x=x;next.y=y;
                       next.people_x=cur.x;
                       next.people_y=cur.y;
                       next.step=cur.step+1;
                      if(i==0)
                        if(map[cur.x-1][cur.y]!=1&&dfs(cur.x-1,cur.y,cur.x,cur.y,cur.people_x,cur.people_y)&&visit[x][y][cur.x-1][cur.y]==0)
                              {
                                     visit[x][y][cur.x-1][cur.y]=1;
                                     q.push(next);
                              }
                      if(i==1)
                        if(map[cur.x+1][cur.y]!=1&&dfs(cur.x+1,cur.y,cur.x,cur.y,cur.people_x,cur.people_y)&&visit[x][y][cur.x+1][cur.y]==0)
                              {
                                     visit[x][y][cur.x+1][cur.y]=1;
                                     q.push(next);
                              }
                      if(i==2)
                        if(map[cur.x][cur.y-1]!=1&&dfs(cur.x,cur.y-1,cur.x,cur.y,cur.people_x,cur.people_y)&&visit[x][y][cur.x][cur.y-1]==0)
                                {
                                        visit[x][y][cur.x][cur.y-1]=1;
                                        q.push(next);
                                }
                      if(i==3)
                        if(map[cur.x][cur.y+1]!=1&&dfs(cur.x,cur.y+1,cur.x,cur.y,cur.people_x,cur.people_y)&&visit[x][y][cur.x][cur.y+1]==0)
                               {
                                       visit[x][y][cur.x][cur.y+1]=1;
                                       q.push(next);
                               }

               }
       }
}
int main()
{
       int t;
       cin>>t;
       while(t--)
       {
               init();
               while(!q.empty()) q.pop();
             scanf("%d%d",&m,&n);

             for(int i=1;i<=m;i++)
                     for(int j=1;j<=n;j++)
                     {
                             scanf("%d",&map[i][j]);
                             if(map[i][j]==2)
                             {
                                     start1_x=i;
                                     start1_y=j;
                             }
                             if(map[i][j]==3)
                             {
                                     end_x=i;
                                     end_y=j;
                             }
                             if(map[i][j]==4)
                             {
                                     start2_x=i;
                                     start2_y=j;
                             }
                     }
             cur.x=start1_x;
             cur.y=start1_y;
             cur.step=0;
             cur.people_x=start2_x;
             cur.people_y=start2_y;

             q.push(cur);
             bfs();
             if(flag==0) cout<<"-1"<<endl;
       } 
   return 0;
}