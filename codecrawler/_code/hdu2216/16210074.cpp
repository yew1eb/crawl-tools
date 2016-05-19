#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
#include"queue"
using namespace std;
int n,m;
char map[22][22];
int vis[22][22][22][22];
int x1_s,x2_s,y1_s,y2_s;
struct node
{
    int x1,y1,x2,y2;
    int step;
};
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};
int BFS()
{
    int i,temp;
    queue<node>q;
    node now,next;
    memset(vis,0,sizeof(vis));
    now.x1=x1_s;
    now.y1=y1_s;
    now.x2=x2_s;
    now.y2=y2_s;
    now.step=0;
    q.push(now);
    vis[x1_s][y1_s][x2_s][y2_s]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x1==now.x2 && now.y1==now.y2)        return now.step;
        if(abs(now.x1-now.x2)==1 && now.y1==now.y2) return now.step;
        if(abs(now.y1-now.y2)==1 && now.x1==now.x2) return now.step;
        for(i=0;i<4;i++)
        {
            temp=i+2;
            temp%=4;
            next.x1=now.x1+dir[i][0];
            next.y1=now.y1+dir[i][1];
            next.x2=now.x2+dir[temp][0];
            next.y2=now.y2+dir[temp][1];
            
            if(next.x1<0 || next.x1>=n || next.y1<0 || next.y1>=m || map[next.x1][next.y1]=='X')  continue;
            if(next.x2<0 || next.x2>=n || next.y2<0 || next.y2>=m || map[next.x2][next.y2]=='X')  {next.x2=now.x2;next.y2=now.y2;}
            if(vis[next.x1][next.y1][next.x2][next.y2]) continue;
            
            vis[next.x1][next.y1][next.x2][next.y2]=1;
            next.step=now.step+1;
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    int i,l;
    int ans;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(l=0;map[i][l];l++)
            {
                if(map[i][l]=='Z')  {map[i][l]='.';x1_s=i;y1_s=l;}
                if(map[i][l]=='S')  {map[i][l]='.';x2_s=i;y2_s=l;}
            }
        }
        ans=BFS();
        if(ans==-1) printf("Bad Luck!\n");
        else        printf("%d\n",ans);
    }
    return 0;
}