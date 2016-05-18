#include<stdio.h>
#define NN 102
int main()
{
    int T, i, j, S, C;
    int f[NN][NN];
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &S, &C);
        for (i = 0; i < S; i++)
            scanf("%d", &f[0][i]);
        for (i = 1; i < S; i++)
            for (j = 0; i + j < S; j++)
                f[i][j] = f[i - 1][j + 1] - f[i - 1][j];
        for (i = 1; i <= C; i++)
            f[S - 1][i] = f[S - 1][0];
        for (i = S - 2; i >= 0; i--)
            for (j = S - i; j < C + S; j++)
                f[i][j] = f[i][j - 1] + f[i + 1][j - 1];
        for (i = S; i < S + C - 1; i++)
            printf("%d ", f[0][i]);
        printf("%d\n", f[0][i]);
    }
    return 0;
}