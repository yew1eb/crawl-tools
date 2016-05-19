#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define BUG printf("here!\n")
using namespace std;
char map[30][30];
int vis[30][30];
struct node
{
    int x,y,d;
};
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int n,m;
int judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return 0;
    if(map[x][y]=='*')
        return 0;
    if(vis[x][y])
        return 0;
    return 1;
}
int bfs(int sx,int sy)
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node temp;
    temp.x=sx,temp.y=sy,temp.d=0;
    vis[sx][sy]=1;
    q.push(temp);
    while(!q.empty())
    {
        node cur=q.front();
        q.pop();
        if(map[cur.x][cur.y]=='T')
            return cur.d;
        int i;
        for(i=0;i<4;i++)
        {
            int nx=cur.x+xx[i];
            int ny=cur.y+yy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(vis[nx][ny]||map[nx][ny]=='*')
                continue;
            else if(map[nx][ny]=='.'||map[nx][ny]=='T')
            {
                node next;
                next.x=nx;
                next.y=ny;
                next.d=cur.d+1;
                vis[nx][ny]=1;
                q.push(next);
            }
            else
            {
                if(i==0||i==2)
                {
                    if(map[nx][ny]=='-'&&cur.d%2==0)
                    {
                        nx=nx+xx[i];
                        ny=ny+yy[i];
                        if(judge(nx,ny))
                        {
                            node next;
                            next.x=nx;
                            next.y=ny;
                            next.d=cur.d+1;
                            vis[nx][ny]=1;
                            q.push(next);
                        }
                    }
                    else if(map[nx][ny]=='|'&&cur.d%2==1)
                    {
                        nx=nx+xx[i];
                        ny=ny+yy[i];
                        if(judge(nx,ny))
                        {
                            node next;
                            next.x=nx;
                            next.y=ny;
                            next.d=cur.d+1;
                            vis[nx][ny]=1;
                            q.push(next);
                        }
                    }
                    else  //ç­ä¸ä¸åé
                    {
                        node next;
                        next.x=cur.x;
                        next.y=cur.y;
                        next.d=cur.d+1;
                        q.push(next);
                    }
                }
                else
                {
                    if(map[nx][ny]=='-'&&cur.d%2==1)
                    {
                        nx=nx+xx[i];
                        ny=ny+yy[i];
                        if(judge(nx,ny))
                        {
                            node next;
                            next.x=nx;
                            next.y=ny;
                            next.d=cur.d+1;
                            vis[nx][ny]=1;
                            q.push(next);
                        }
                    }
                    else if(map[nx][ny]=='|'&&cur.d%2==0)
                    {
                        nx=nx+xx[i];
                        ny=ny+yy[i];
                        if(judge(nx,ny))
                        {
                            node next;
                            next.x=nx;
                            next.y=ny;
                            next.d=cur.d+1;
                            vis[nx][ny]=1;
                            q.push(next);
                        }
                    }
                    else
                    {
                        node next;
                        next.x=cur.x;
                        next.y=cur.y;
                        next.d=cur.d+1;
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int sx,sy;
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            int j;
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='S')
                    sx=i,sy=j;
            }
        }
        int res=bfs(sx,sy);
        printf("%d\n",res);
    }
    return 0;
}
