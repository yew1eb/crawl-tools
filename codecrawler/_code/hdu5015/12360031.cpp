#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int p = 10000007;
int n, m;
long long a[21], f[21][21];

inline void af(int n){
    long long w[n + 1];
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            w[i] += a[j] * f[j][i], w[i] %= p;
    for (int i = 1; i <= n; i++) a[i] = w[i];
}

inline void ff(int n){
    long long w[n + 1][n + 1];
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= n; k++)
            if (f[i][k])
                for (int j = 1; j <= n; j++)
                    if (f[k][j]) w[i][j] += f[i][k] * f[k][j],
                                 w[i][j] %= p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = w[i][j];
}

int main(){
    for (;;)
    {
        if (scanf("%d%d", &n, &m) != 2) return 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        a[n + 1] = 233; a[n + 2] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) f[i][j] = 1;
        f[n + 1][n + 1] = 10; f[n + 2][n + 1] = 3;
        f[n + 2][n + 2] = 1;
        for (int i = 1; i <= n; i++) f[n + 1][i] = 1;
        for (; m; m >>= 1, ff(n + 2))
            if (m & 1) af(n + 2);
        printf("%d\n", a[n]);
    }
}