#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define MAXN 10
#define MAXD 40
#define INF 0x3f3f3f3f
int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
int N, M, g[MAXN][MAXN], ix[MAXD], iy[MAXD], dis[MAXN][MAXN];
int list[1010];
inline int inedge(int x, int y)
{
    return x == 1 || x == N || y == 1 || y == N;    
}
int bfs(int sx, int sy)
{
    int i, x, y, nx, ny, d[MAXN][MAXN];
    memset(d, -1, sizeof(d));
    std::queue <int> q;
    d[sx][sy] = 0, q.push(sx * 10 + sy);
    while(!q.empty())
    {
        x = q.front() / 10, y = q.front() % 10, q.pop();
        if(inedge(x, y)) return d[x][y];
        for(i = 0; i < 4; i ++)
        {
            nx = x + dx[i], ny = y + dy[i];
            if(g[nx][ny] && d[nx][ny] == -1)
                d[nx][ny] = d[x][y] + 1, q.push(nx * 10 + ny);    
        }    
    }
    return 0;
}
void init()
{
    int i, j;
    char b[MAXD];
    for(i = 1; i <= N; i ++)
    {
        scanf("%s", b + 1);
        for(j = 1; j <= N; j ++) g[i][j] = 1 - (b[j] - '0');    
    }
    M = 0;
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= N; j ++)
        {
            if(g[i][j])
            {
                if(inedge(i, j)) dis[i][j] = 0;
                else
                {
                    dis[i][j] = bfs(i, j);
                    ix[M] = i, iy[M] = j, ++ M;
                }
            }
            else dis[i][j] = INF;
        }
}
int Max(int *x, int *y)
{
    int i, ans = 0;
    for(i = 0; i < M; i ++) ans = std::max(ans, dis[x[i]][y[i]]);
    return ans;    
}
int dfs(int d, int *ix, int *iy)
{
    if(Max(ix, iy) > d) return 0;
    if(d == 0) return 1;
    int i, j, x[MAXD], y[MAXD], nx, ny;
    for(i = 0; i < 4; i ++)
    {
        list[d] = i;
        for(j = 0; j < M; j ++)
        {
            nx = ix[j] + dx[i], ny = iy[j] + dy[i];
            if(inedge(ix[j], iy[j]) || g[nx][ny] == 0)
                x[j] = ix[j], y[j] = iy[j];
            else
                x[j] = nx, y[j] = ny;
        }
        if(dfs(d - 1, x, y)) return 1;
     }
     return 0;
}
void solve()
{
    int i, dep;
    if(M == 0) return ;
    for(dep = 1; !dfs(dep, ix, iy); dep ++);
    for(i = dep; i > 0; i --)
    {
        if(list[i] == 0) puts("east");
        else if(list[i] == 1) puts("north");
        else if(list[i] == 2) puts("south");
        else puts("west");
    }
}
int main()
{
    int t = 0;
    while(scanf("%d", &N) == 1)
    {
        init();
        if(t ++) printf("\n");
        solve();    
    }
    return 0;    
}