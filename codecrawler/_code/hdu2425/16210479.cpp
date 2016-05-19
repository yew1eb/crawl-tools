#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int map[25][25];//1-Tï¼2-.,3-#,-1-@
int vis[25][25];
int v[5];
int x1,x2,y1,y2,ans;
int to[4][2] = {1,0,-1,0,0,1,0,-1};

struct node
{
    int x,y,step;
     friend bool operator<(node n1,node n2)
    {
        return n2.step<n1.step;
    }

};

int check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || map[x][y]<0|| vis[x][y])
        return 1;
    return 0;
}

int bfs()
{
    int i;
    priority_queue<node> Q;
    node a,next;
    memset(vis,0,sizeof(vis));
    a.x = x1;
    a.y = y1;
    a.step = 0;
    vis[a.x][a.y] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.top();
        Q.pop();
        if(a.x == x2 && a.y == y2)
        return a.step;
        for(i = 0; i<4; i++)
        {
            next = a;
            next.x +=to[i][0];
            next.y +=to[i][1];
            if(check(next.x,next.y))
                continue;
            next.step+=v[map[next.x][next.y]];
            vis[next.x][next.y] = 1;
            Q.push(next);
        }
    }
    return -1;
}

int main()
{
    int i,j,cas = 1;
    char s[100];
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d%d%d",&v[3],&v[2],&v[1]);
        for(i = 0; i<n; i++)
        {
            scanf("%s",s);
            for(j = 0; s[j]; j++)
            {
                if(s[j]=='T') map[i][j] = 1;
                else if(s[j] == '.') map[i][j] = 2;
                else if(s[j] == '#') map[i][j] = 3;
                else if(s[j] == '@') map[i][j] = -1;
            }
        }
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans = bfs();
        printf("Case %d: %d\n",cas++,ans);
    }

    return 0;
}
