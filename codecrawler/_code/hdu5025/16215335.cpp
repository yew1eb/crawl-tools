#include <iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
const int maxn=105;
char map1[maxn][maxn];
int vis[maxn][maxn][55][10];
int stx,sty;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int ssx[6],ssy[6];
int n,m;
int ans=999999999;
int cnt;
struct node
{
    int x;
    int y;
    int snake;
    int key;
};
void bfs()
{
     node temp;
     temp.x=stx;
     temp.y=sty;
     temp.key=0;
     temp.snake=0;
     int sx,sy;
     queue<node>que;
     que.push(temp);
     while(!que.empty())
     {
         temp=que.front();
        // cout<<temp.x<<" "<<temp.y<<" "<<endl;
         que.pop();
         for(int i=0;i<4;i++)
         {
             sx=temp.x+dx[i];
             sy=temp.y+dy[i];
             if(sx<0||sx>=n||sy<0||sy>=n||map1[sx][sy]=='#'||vis[sx][sy][temp.snake][temp.key]>0)
                continue;
             if(map1[sx][sy]=='T'&&temp.key>=m)
             {
                 ans=min(ans,vis[temp.x][temp.y][temp.snake][temp.key]+1);
                 continue;
             }
             if(map1[sx][sy]-'1'>=0&&map1[sx][sy]-'1'<=9)
             {
                 if(temp.key==map1[sx][sy]-'1')
                 {
                     node temp1;
                     temp1.x=sx;
                     temp1.y=sy;
                     temp1.snake=temp.snake;
                     temp1.key=temp.key+1;
                     vis[sx][sy][temp1.snake][temp1.key]=vis[temp.x][temp.y][temp.snake][temp.key]+1;
                     que.push(temp1);
                 }
                 else
                 {
                    node temp1;
                    temp1.x=sx;
                    temp1.y=sy;
                    temp1.snake=temp.snake;
                    temp1.key=temp.key;
                    vis[sx][sy][temp.snake][temp.key]=vis[temp.x][temp.y][temp.snake][temp.key]+1;
                    que.push(temp1);
                 }
             }
             else
             {
                 if(map1[sx][sy]=='.'||map1[sx][sy]=='K'||map1[sx][sy]=='T')
                 {
                   node temp1;
                   temp1.x=sx;
                   temp1.y=sy;
                   temp1.snake=temp.snake;
                   temp1.key=temp.key;
                   vis[sx][sy][temp.snake][temp.key]=vis[temp.x][temp.y][temp.snake][temp.key]+1;
                   que.push(temp1);
                 }
                 else
                 {
                     for(int j=0;j<cnt;j++)
                     {
                         if(ssx[j]==sx&&ssy[j]==sy)
                         {
                            node temp1;
                            temp1.x=sx;
                            temp1.y=sy;
                            temp1.key=temp.key;
                            //cout<<"  sbsbsb  "<<j<<" "<<(temp.snake>>j)<<endl;
                            if((temp.snake>>j)&1)
                            {
                                temp1.snake=temp.snake;
                                vis[sx][sy][temp.snake][temp.key]=vis[temp.x][temp.y][temp.snake][temp.key]+1;
                            }
                            else
                            {
                                //  cout<<"hahah"<<endl;
                                temp1.snake=temp.snake+(1<<j);
                                vis[sx][sy][temp1.snake][temp.key]=vis[temp.x][temp.y][temp.snake][temp.key]+2;
                            }
                            que.push(temp1);
                            break;
                         }
                     }
                 }
             }
         }
     }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        memset(vis,0,sizeof(vis));
        ans=999999999;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",map1[i]);
            for(int j=0;j<n;j++)
            {
                if(map1[i][j]=='K')
                {
                    stx=i;
                    sty=j;
                }
                if(map1[i][j]=='S')
                {
                    ssx[cnt]=i;
                    ssy[cnt]=j;
                    cnt++;
                }
            }
        }
        bfs();
        if(ans==999999999)
            printf("impossible\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
