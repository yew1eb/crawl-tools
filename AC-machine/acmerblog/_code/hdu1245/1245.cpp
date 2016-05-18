#include<iostream>
 #include<cstring>
 #include<cstdio>
 #include<queue>
 using namespace std;
 struct node
 {
     int x,y;
     int bx,by;
     int step;
     bool friend operator<(node a,node b)
     {
        return a.step>b.step;//这里开始定义的小于  交了n次都不对
     };
 };
 #define N 10
 int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
 int map[N][N];
 int mark[N][N][N][N];
 int sx,sy,bx,by,ex,ey;
 int n,m;
 void BFS()
 {
     memset(mark,0,sizeof(mark));
     node cur,next;
     priority_queue<node>q;
     int x,y,xx,yy,i;
     cur.x=sx;cur.y=sy;cur.bx=bx;cur.by=by;cur.step=0;
     q.push(cur);
     mark[sx][sy][bx][by]=1;
     while(!q.empty())
     {
         cur=q.top();
         q.pop();
         if(cur.bx==ex&&cur.by==ey)
         {
             printf("%d\n",cur.step);
             return ;
         }
         for(i=0;i<4;i++)
         {
             next.x=x=cur.x+dir[i][0];
             next.y=y=cur.y+dir[i][1];
             next.bx=xx=cur.bx;
             next.by=yy=cur.by;
             next.step=cur.step;
             if(x<0||x>=n||y<0||y>=m)//第一次用for循环写判断符合条件的WA了，改用continue可以很好的处理如果搬运工前面是箱子的问题
                 continue;
             if(map[x][y]==1||mark[x][y][xx][yy]==1)
                 continue;
             if(x==xx&&y==yy)
             {
                 next.bx=xx=xx+dir[i][0];
                 next.by=yy=yy+dir[i][1];
                 next.step++;
                 if(xx<0||xx>=n||yy<0||yy>=m)
                 continue;
                 if(map[xx][yy]==1||mark[x][y][xx][yy]==1)
                     continue;
 
             }
             q.push(next);
             mark[x][y][xx][yy]=1;
 
         }
     }
     printf("-1\n");
     return ;
 }
 int main()
 {
    //freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int  t;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,0,sizeof(map));
        scanf("%d%d",&n,&m);
        int i,j;
        for(i=0;i<n;i++)
        {
 
            for(j=0;j<m;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(map[i][j]==4)
                {
                   sx=i,sy=j;
                   
                }
                else if(map[i][j]==2)
                {
                    bx=i,by=j;
 
                }
                else if(map[i][j]==3)
                {
                    ex=i,ey=j;
                    
                }
            }
        }
        BFS();
    }
 
     return 0;
 }