#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define inf (0x7f7f7f7f)
const int maxn = 12;

int c, n, m, t;
char map[2][maxn][maxn];
bool vis[2][maxn][maxn];
struct node
{
    int x, y, z;
    int step;
};
queue<node> q;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool judge(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

bool bfs()
{
    bool flag = false;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();

        if (map[now.z][now.x][now.y] == 'P')
        {
            if (now.step >= 0)
                return true;
            else
                break;
        }

        node next;
        for (int i=0; i<4; i++)
        {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.z = now.z;
            next.step = now.step - 1;

            if (!judge(next.x,next.y)) continue;

            if (map[now.z][next.x][next.y] == '#')
                next.z ^= 1;
            
            if (map[next.z][next.x][next.y] != '*' && next.step >= 0 && !vis[next.z][next.x][next.y])
            {
                vis[next.z][next.x][next.y] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
//    freopen("2102.in", "r", stdin);
//    freopen("2102.out", "w", stdout);

    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d %d", &n, &m, &t);
        memset(vis, false, sizeof(vis));
        while (!q.empty()) q.pop();

        int i, j, k;
        for (i=0; i<2; i++)
            for (j=0; j<n; j++)
                scanf("%s", map[i][j]);
        node s;

        for (i=0; i<2; i++)
            for (j=0; j<n; j++)
                for (k=0; k<m; k++)
                {
                    if (map[i][j][k] == 'S')
                        s.x = j, s.y = k, s.z = i, s.step = t;
                    else if (map[i][j][k] == '#' && map[1^i][j][k] == '#')
                    {
                        map[i][j][k] = '*';
                        map[1^i][j][k] = '*';
                    }
                    else if (map[i][j][k] == '#' && map[1^i][j][k] == '*')
                        map[i][j][k] = '*';
                }
        vis[s.z][s.x][s.y] = true;
        q.push(s);
        if (bfs())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
