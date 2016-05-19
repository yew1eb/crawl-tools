#include <stdio.h>
#include <string.h>
#define MAXN 30
int c[MAXN + 5][MAXN + 5];

void init()
{
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (int i = 0; i <= MAXN; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) ;
    }
}
int main()
{
    int t, m, n;
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (m > n) {
            printf("0\n");
        } else
            printf("%d\n", c[n][m]);
    }
    return 0;
}
