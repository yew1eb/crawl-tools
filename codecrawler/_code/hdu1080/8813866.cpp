
#include<stdio.h>
int map[5][5] = {
    5, -1, -2, -1, -3,
    -1, 5, -3, -2, -4,
    -2, -3, 5, -2, -2,
    -1, -2, -2, 5, -1,
    -3, -4, -2, -1, -1111111
};
int change(int a[], char t[])
{
    int i;
    for (i = 0; t[i] != '\0'; i++)
        switch (t[i]) {
        case 'A': a[i] = 0; break;
        case 'C': a[i] = 1; break;
        case 'G': a[i] = 2; break;
        case 'T': a[i] = 3; break;
        }
    return 1;
}
int dp[111][111];
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int i, j, m, n, k, t, a1[111], a2[111];
    char t1[111], t2[111];
    scanf("%d", &k);
    while (k--) {
        scanf("%d %s", &m, t1);
        scanf("%d %s", &n, t2);
        change(a1 + 1, t1);
        change(a2 + 1, t2);
        dp[0][0] = 0;
        for (i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + map[a1[i]][4];
        for (i = 1; i <= n; i++)
            dp[0][i] = dp[0][i - 1] + map[4][a2[i]];
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                dp[i][j] = max(max(dp[i - 1][j - 1] + map[a1[i]][a2[j]], dp[i - 1][j] + map[a1[i]][4]), dp[i][j - 1] + map[4][a2[j]]);
        printf("%d\n", dp[m][n]);

    }

}
