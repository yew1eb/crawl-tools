#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

char map[20][20][20];
int vis[20][20][20];
int n;
int sx,sy,sz;
int ex,ey,ez;
int tx[] = {1,-1,0,0,0,0};
int ty[] = {0,0,1,-1,0,0};
int tz[] = {0,0,0,0,1,-1};

struct node
{
    int x,y,z,step;
};

int check(int x,int y,int z)
{
    if(x<0 || y<0 || z<0 || x>=n || y>=n || z>=n || vis[x][y][z] )
    return 0;
    return 1;
}

int bfs(int x,int y,int z)
{
    int i;
    queue<node> Q;
    node a,next;
    a.x = x;
    a.y = y;
    a.z = z;
    a.step = 0;
    vis[x][y][z] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.x == ex && a.y == ey && a.z == ez)
        return a.step;
        for(i = 0;i<6;i++)
        {
            next = a;
            next.x+=tx[i];
            next.y+=ty[i];
            next.z+=tz[i];
            if(check(next.x,next.y,next.z))
            {
                next.step++;
                vis[next.x][next.y][next.z] = 1;
                Q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    char s[10];
    int i,j,k;
    while(~scanf("%s%d",s,&n))
    {
        for(i = 0;i<n;i++)
        for(j = 0;j<n;j++)
        scanf("%s",map[i][j]);
        scanf("%d%d%d%d%d%d",&sx,&sy,&sz,&ex,&ey,&ez);
        scanf("%s",s);
        int ans = bfs(sx,sy,sz);
        if(ans>=0)
        printf("%d %d\n",n,ans);
        else
        printf("NO ROUTE\n");
    }

    return 0;
}
