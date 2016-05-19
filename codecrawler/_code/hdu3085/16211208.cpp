#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 1000;
char map[maxn][maxn];
int cas, n, m;
int mx, my, gx, gy;
int step;
int zz[5][2];
int f[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

struct node
{
    int x, y;
};

bool Dis(int x, int y)
{
    int d1 = abs(x - zz[0][0]) + abs(y - zz[0][1]);
    int d2 = abs(x - zz[1][0]) + abs(y - zz[1][1]);
    if(d1 <= 2*step || d2 <= 2*step)    return false;
    return true;
}

queue<node>q[3];
bool bfs(int num, int k, char s, char e)
{
    q[2] = q[num];
    for(int t = 0;t<k;t++)
    {
        while(!q[2].empty())
        {
            node b = q[2].front();
            q[2].pop();
            q[num].pop();
            node c;
            if(!Dis(b.x, b.y))    continue;
            for(int i = 0;i<4;i++)
            {
                int nx = b.x + f[i][0];
                int ny = b.y + f[i][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'X')    continue;
                if(!Dis(nx, ny) || map[nx][ny] == s)    continue;
                if(map[nx][ny] == e)    return true;
                map[nx][ny] = s;
                c.x = nx, c.y = ny;
                q[num].push(c);
            }            
        }
        q[2] = q[num];
    }
    return false;
}

void BFS()
{
    step = 0;
    for(int i = 0;i<3;i++)
    {
        while(!q[i].empty())
            q[i].pop();
    }
    node a;
    a.x = mx, a.y = my;
    q[0].push(a);
    a.x = gx, a.y = gy;
    q[1].push(a);
    while(!q[0].empty() && !q[1].empty())
    {
        step++;
        if(bfs(0, 3, 'M', 'G') || bfs(1, 1, 'G', 'M'))
        {
            printf("%d\n", step);
            return;
        }
    }
    printf("-1\n");
    return;
}

int main()
{
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &n, &m);
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%s", map[i]);
            for(int j = 0;j<m;j++)
            {
                if(map[i][j] == 'M')
                mx = i, my = j;
                if(map[i][j] == 'G')
                gx = i, gy = j;
                if(map[i][j] == 'Z')
                {                    
                    zz[cnt][0] = i;
                    zz[cnt][1] = j;
                    cnt++;
                }
            }
        }
        BFS();
    }
    return 0;
}