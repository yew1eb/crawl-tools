#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int m,n;
int z1,z2,s1,s2;
char map[25][25];
int vis[25][25][25][25];
int to[4][2] = {1,0,-1,0,0,-1,0,1};//Zçèµ°æ³
int to2[4][2] = {-1,0,1,0,0,1,0,-1};//Sèµ°ç¸åè·¯çº¿

struct node
{
    int x1,x2,y1,y2,step;
};

int check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || map[x][y] == 'X')
        return 1;
    return 0;
}

int judge(int x,int x1,int y,int y1)//ç¬¦åæ¡ä»¶çç¶åµ
{
    if(x == x1 && y == y1)
        return 1;
    if(x == x1+1 && y == y1)
        return 1;
    if(x == x1-1 && y == y1)
        return 1;
    if(x == x1 && y == y1-1)
        return 1;
    if(x == x1 && y == y1+1)
        return 1;
    return 0;
}

int bfs()
{
    int i;
    queue<node> Q;
    node a,next;
    memset(vis,0,sizeof(vis));
    a.x1 = z1;
    a.x2 = s1;
    a.y1 = z2;
    a.y2 = s2;
    a.step = 0;
    vis[z1][z2][s1][s2] = 1;//åç»´æ°ç»è®°å½è¡èµ°ç¶åµ
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(judge(a.x1,a.x2,a.y1,a.y2))
            return a.step;
        for(i = 0; i<4; i++)
        {
            next = a;
            next.x1 = a.x1+to[i][0];
            next.y1 = a.y1+to[i][1];
            next.x2 = a.x2+to2[i][0];
            next.y2 = a.y2+to2[i][1];
            if(check(next.x1,next.y1))
                continue;
            if(check(next.x2,next.y2))
            {
                next.x2 = a.x2;
                next.y2 = a.y2;
            }
            if(vis[next.x1][next.y1][next.x2][next.y2])
                continue;
            vis[next.x1][next.y1][next.x2][next.y2] = 1;
            next.step = a.step+1;
            Q.push(next);
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int i,j;
        for(i = 0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(j = 0; map[i][j]; j++)
            {
                if(map[i][j] == 'Z')
                {
                    map[i][j] == '.';//åå§ä½ç½®ç½®ä¸ºç©ºå°
                    z1 = i;
                    z2 = j;
                }
                else if(map[i][j] == 'S')
                {
                    map[i][j] == '.';
                    s1 = i;
                    s2 = j;
                }
            }
        }
        int ans;
        ans = bfs();
        if(ans)
            printf("%d\n",ans);
        else
            printf("Bad Luck!\n");
    }

    return 0;
}
