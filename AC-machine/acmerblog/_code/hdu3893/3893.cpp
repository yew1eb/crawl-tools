#include <stdio.h>
#include <memory.h>

const __int64 mod = 112233;

__int64 init_mtx[12][12] = {
    3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 0,
    1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 5
};
__int64 init_cunt[12] = {
    4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

__int64 mtx1[12][12], mtx2[12][12], mtx3[12][12];

void mul(__int64 mtxa[12][12], __int64 mtxb[12][12]) {
    int i, j, k;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            mtx3[i][j] = 0;
            for (k = 0; k < 12; k++)
                mtx3[i][j] += mtxa[i][k] * mtxb[k][j];
            mtx3[i][j] %= mod;
        }
    }
    memcpy(mtxa, mtx3, sizeof(mtx3));
}

void solve(int m) {
    int i, j;

    memset(mtx1, 0, sizeof(mtx1));
    for (i = 0; i < 12; i++)
        mtx1[i][i] = 1;
    memcpy(mtx2, init_mtx, sizeof(mtx2));
    
    while (m) {
        if (m & 1)
            mul(mtx1, mtx2);
        mul(mtx2, mtx2);
        m >>= 1;
    }

    long long ans = 0;
    for (i = 0; i < 11; i++)
        for (j = 0; j < 11; j++)
            ans += mtx1[i][j] * init_cunt[j];
    printf("%I64d\n", ans % mod);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n % 2 == 0) printf("0\n");
        else solve(n / 2);
    }
    return 0;
}