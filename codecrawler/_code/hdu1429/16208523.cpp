#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define BUG printf("here!\n")
using namespace std;
struct node
{
    int x,y,key;
};
char map[25][25];
int vis[25][25][1025];
int n,m,t;
int xx[4]={0,1,-1,0};
int yy[4]={1,0,0,-1};
int res;
int BFS(int sx,int sy)
{
    int x,y,key;
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node temp;
    temp.x=sx;
    temp.y=sy;
    temp.key=0;
    q.push(temp);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        sx=temp.x;
        sy=temp.y;
        key=temp.key;
        if(vis[sx][sy][key]>t)
            return -1;
        int i;
        for(i=0;i<4;i++)
        {
            x=sx+xx[i];
            y=sy+yy[i];
            if(x<0||x>=n||y<0||y>=m)
                continue;
            if(map[x][y]=='^')
                return vis[sx][sy][key]+1;
            if(map[x][y]=='*'||vis[x][y][key])
                continue;
            if(map[x][y]=='.'||map[x][y]=='@')
            {
                vis[x][y][key]=vis[sx][sy][key]+1;
                temp.x=x;
                temp.y=y;
                temp.key=key;
                q.push(temp);
            }
            if(map[x][y]>='a'&&map[x][y]<='j')
            {
                int key1=(key|(1<<(map[x][y]-'a')));
                vis[x][y][key1]=vis[sx][sy][key]+1;
                temp.x=x;
                temp.y=y;
                temp.key=key1;
                q.push(temp);
            }
            if(map[x][y]>='A'&&map[x][y]<='J')
            {
                if(key&(1<<(map[x][y]-'A')))
                {
                    vis[x][y][key]=vis[sx][sy][key]+1;
                    temp.x=x;
                    temp.y=y;
                    temp.key=key;
                    q.push(temp);
                }
            }

        }
    }
    return -1;
}
int main()
{

    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        int i;
        memset(vis,0,sizeof(vis));
        int sx,sy;
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            int j;
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        res=BFS(sx,sy);
        if(res<t)
            printf("%d\n",res);
        else
            printf("-1\n");
    }
    return 0;
}
