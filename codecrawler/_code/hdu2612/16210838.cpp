#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 0x7fffffff
int n,m;
char map[250][250];
int visit1[250][250];
int visit2[250][250];
int ans1[250][250];
int ans2[250][250];
struct cam
{
    int x,y;
}list[80000];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int go(int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m&&map[x][y]!='#')
    return 1;
    return 0;
}
void bfs(int x,int y,int visit[250][250],int ans[250][250])
{
    int i,head,tail;
    int xx,yy;
    memset(visit,0,sizeof(visit));
    memset(ans,0,sizeof(ans));
    visit[x][y]=1;
    ans[x][y]=0;
    list[0].x=x;
    list[0].y=y;
    head=0;
    tail=1;
    while(head<tail)
    {
         x=list[head].x;
         y=list[head].y;
         for(i=0;i<4;i++)
         {
             xx=x+dir[i][0];
             yy=y+dir[i][1];
             if(go(xx,yy)&&!visit[xx][yy])
             {
                 list[tail].x=xx;
                 list[tail].y=yy;
                 ans[xx][yy]=ans[x][y]+1;
                 visit[xx][yy]=1;
                 tail++;
             }
         }
         head++;
    }
}
int main()
{
    int i,j;
    int x1,y1,x2,y2;
    int min;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='Y')
            {
                x1=i;
                y1=j;
            }
            else if(map[i][j]=='M')
            {
                x2=i;
                y2=j;
            }
        }
        memset(visit1,0,sizeof(visit1));
         memset(ans1,0,sizeof(ans1));
        bfs(x1,y1,visit1,ans1);
        memset(visit2,0,sizeof(visit2));
         memset(ans2,0,sizeof(ans2));
        bfs(x2,y2,visit2,ans2);
        min=max;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='@'&&visit1[i][j]&&visit2[i][j])
            if(min>ans1[i][j]+ans2[i][j])
            min=ans1[i][j]+ans2[i][j];
        }
        printf("%d\n",min*11);
    }
    return 0;
}
