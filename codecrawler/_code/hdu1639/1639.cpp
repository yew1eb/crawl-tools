#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int move[8][2] = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
struct point
{
    int x,y;
};
int main()
{
    int m,n;
    point p0;
    char s[25][25];
    int map[25][25];
    while(scanf("%d%d%d%d",&m,&n,&p0.x,&p0.y)&&(m+n+p0.x+p0.y))
    {
        for(int i=1; i<=m; i++)
        scanf("%s",s[i]+1);
        memset(map,0,sizeof(map));
        for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        if(s[i][j]=='X')  map[i][j] = 1;
        queue<point>q;
        q.push(p0);
        map[p0.x][p0.y] = -1;
        int ans = 0;
        while(!q.empty())
        {
            point p = q.front();
            q.pop();
            for(int i=0; i<8; i++)
            {
                point tmp;
                tmp.x = p.x+move[i][0];
                tmp.y = p.y+move[i][1];
                if(map[tmp.x][tmp.y]==0&&i<4) ans++;
                else if(map[tmp.x][tmp.y]==1)
                {
                    map[tmp.x][tmp.y] = -1;
                    q.push(tmp);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}