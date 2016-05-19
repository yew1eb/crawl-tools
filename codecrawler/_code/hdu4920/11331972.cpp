#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M 810

int n, N;
int f[2200][2200];
int a[M][M], b[M][M], c[M][M];
int A[M][M], B[M][M];

int read() {
    char ch;
    bool ok = 0;
    int res = 0;
    for (;;) {
        ch = getchar();
        if (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ok = 1;
        else if (ok)
            return res % 3;
    }
}

int solve(int a, int b) {
    int i = 7, res = 0;
    while (i--) {
        res += (a % 3) * (b % 3);
        a /= 3;
        b /= 3;
    }
    return res % 3;
}

int main() {
    int i, j, k;
    for (i = 0; i < 2187; i++)
        for (j = 0; j < 2187; j++)
            f[i][j] = solve(i, j);
    while (~scanf("%d", &n)) {
        N = (n - 1) / 7 + 1;
        for (i = 0; i < n; i++) {
            int cnt = 0;
            int tmp = 0;
            for (j = 0; j < n; j++) {
                cnt++;
                a[i][j] = read();
                tmp = tmp * 3 + a[i][j];
                if (cnt == 7) {
                    A[i][j / 7] = tmp;
                    tmp = 0;
                    cnt = 0;
                }
            }
            if (cnt > 0)
                A[i][N - 1] = tmp;
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                b[i][j] = read();
                c[i][j] = 0;
            }
        for (j = 0; j < n; j++) {
            int cnt = 0;
            int tmp = 0;
            for (i = 0; i < n; i++) {
                cnt++;
                tmp = tmp * 3 + b[i][j];
                if (cnt == 7) {
                    B[i / 7][j] = tmp;
                    tmp = 0;
                    cnt = 0;
                }
            }
            if (cnt > 0)
                B[N - 1][j] = tmp;
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < N; k++)
                    c[i][j] += f[A[i][k]][B[k][j]];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                printf("%d", c[i][j] % 3);
                if (j == n - 1) {
                    putchar('\n');
                } else
                    putchar(' ');
            }
    }
    return 0;
}