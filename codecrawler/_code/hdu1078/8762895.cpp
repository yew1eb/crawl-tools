/*
ÌâÒâ£º
¸øÄã¸ön*nµÄÍ¼£¬ÀÏÊóÒ»´Î×îÔ¶×ßk²½£¬ÀÏÊóÆð³õÔÚ£¨0,0£©£¬
Ã¿´ÎÍµ³ÔµÄ¶«Î÷±ØÐë±ÈÖ®Ç°Íµ³ÔµÄÒª´ó¡£
*/
#include <stdio.h>
#include <string.h>
#define MAXN 105
#define INF 0x7ffffff

int map[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y)
{
    int i, j, xx, yy, max = 0, sum;
    if (dp[x][y] > 0) return dp[x][y];
    for (j = 1; j <= k; j++)
        for (i = 0; i < 4; i++) {
            xx = x + dx[i] * j;
            yy = y + dy[i] * j;
            if (xx < 0 || xx >= n || yy < 0 || yy >= n || map[x][y] >= map[xx][yy]) continue;
            sum = dfs(xx, yy);
            max = max > sum ? max : sum;
        }
    return dp[x][y] = max + map[x][y];
}

int main()
{
    int i, j;
    while (scanf("%d%d", &n, &k)) {
        if (n == -1 && k == -1)
            break;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        memset(dp, 0, sizeof(dp));
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
