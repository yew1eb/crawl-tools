#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<string>
#define inf 0x7fffffff
#define maxn 60
using namespace std;
char maze[maxn][maxn];
int vis[maxn][maxn][maxn];
int n,a,b,c;
struct node
{
    int x,y,z;
};

int bfs()
{
    queue<node> q;
    while(!q.empty())
    q.pop();
    memset(vis,0,sizeof(vis));
    node s;
    s.x=a,s.y=b,s.z=c;
    vis[a][b][c]=1;
    q.push(s);
    node cur,next;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==cur.y&&cur.y==cur.z)
        return vis[cur.x][cur.y][cur.z]-1;
        for(int i=1;i<=n;i++)
        {
            if(maze[cur.x][cur.y]==maze[cur.z][i]&&!vis[cur.x][cur.y][i])
            {
                vis[cur.x][cur.y][i]=vis[cur.x][cur.y][cur.z]+1;
                next.x=cur.x,next.y=cur.y,next.z=i;
                q.push(next);
            }
            if(maze[cur.z][cur.x]==maze[cur.y][i]&&!vis[cur.x][i][cur.z])
            {
                vis[cur.x][i][cur.z]=vis[cur.x][cur.y][cur.z]+1;
                next.x=cur.x,next.y=i,next.z=cur.z;
                q.push(next);
            }
            if(maze[cur.y][cur.z]==maze[cur.x][i]&&!vis[i][cur.y][cur.z])
            {
                vis[i][cur.x][cur.y]=vis[cur.x][cur.y][cur.z]+1;
                next.x=i,next.y=cur.y,next.z=cur.z;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%d%d%d",&a,&b,&c);
        getchar();
        int i,j;
        char ch;
        for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
        {
            scanf("%c%c",&maze[i][j],&ch);
        }
        }
        int ans=bfs();
        if(ans!=-1)
        printf("%d\n",ans);
        else
        printf("impossible\n");
    }
    return 0;
}