#include<stdio.h>
#include<queue>
#include<string.h>
#define inf 0x3fffffff
using namespace std;
char map[30][30];
int n,m,sx,sy,ex,ey;
int cost[4],vis[30][30];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct op
{
    int x,y,w;
};
int judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||map[x][y]=='@')
        return 0;
    return 1;
}
void bfs()
{
    queue<op>Q;
    op cur,next;
    vis[sx][sy]=0;//å¿è®°åå§åèµ·ç¹çå¼ï¼æ¾äºå¥½ä¹ææ¾åºæ¥ 
    cur.w=0;cur.x=sx;cur.y=sy;       
    Q.push(cur);
    while(!Q.empty())
    {
        cur=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(judge(next.x,next.y))
            {
                if(map[next.x][next.y]=='#')
                    next.w=cur.w+cost[0];
                else if(map[next.x][next.y]=='.')
                    next.w=cur.w+cost[1];
                else if(map[next.x][next.y]=='T')
                    next.w=cur.w+cost[2];
                if(next.w<vis[next.x][next.y])
                {Q.push(next);vis[next.x][next.y]=next.w;}
                
            }
            
        }
    }
}
int main()
{
    int i,j,k,op=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vis[i][j]=inf;
            for(i=0;i<3;i++)
                scanf("%d",&cost[i]);
            for(i=0;i<n;i++)
                scanf("%s",map[i]);
            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            bfs();
            if(vis[ex][ey]<inf)
                k=vis[ex][ey];
            else     k=-1;
            printf("Case %d: ",op++);
            printf("%d\n",k);
    }
    return 0;
}