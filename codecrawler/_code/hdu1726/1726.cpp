#include<stdio.h>
#include<string.h>
#define oo 100000000
#define M 105
int map[M][M];
char str[M];

bool judge(int x, int y) {
    int i, k = (y – x + 1) / 2;
    for (i = 0; i < k; i++)
        if (str[x + i] != str[y - i])return false;
    return true;
}

int main() {
    int f[M], n, i, j;
    while (scanf("%s", str) != EOF) {
        n = strlen(str);
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++) {
                if (judge(i, j))map[i][j] = 1;
                else map[i][j] = 0;
            }
        f[0] = 0;
        for (i = 1; i < n; i++) {
            f[i] = oo;
            if (map[0][i])f[i] = 0;
            else {
                for (j = 0; j < i; j++)
                    if (map[j + 1][i] && f[j] + 1 < f[i])
                        f[i] = f[j] + 1;
            }
        }
        printf("%d\n", f[n - 1]);
    }
    return 0;
}