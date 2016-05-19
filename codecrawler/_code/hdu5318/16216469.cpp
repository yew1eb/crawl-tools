#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 55;
const int mod = 1e9+7;

int N, M, A[maxn];

struct Mat {
    int s[maxn][maxn];
    Mat () {
        memset(s, 0, sizeof(s));
    }
    Mat operator * (const Mat& b) {
        Mat ret;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    ret.s[i][j] = (ret.s[i][j] + 1LL * s[i][k] * b.s[k][j] % mod) % mod;
            }
        }
        return ret;
    }
};

void init () {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    sort(A, A + N);
    N = unique(A, A + N) - A;
}

bool judge (int a, int b) {
    char p[15], q[15];
    sprintf(p, "%d", a);
    sprintf(q, "%d", b);

    int pp = strlen(p), qq = strlen(q);
    for (int i = 0; i < pp; i++) {
        int k = 0;
        while (i + k < pp && k < qq && p[i+k] == q[k])
            k++;
        if (i + k == pp && k > 1)
            return true;
    }
    return false;
}

Mat solve () {
    Mat ret;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (judge(A[i], A[j]))
                ret.s[i][j] = 1;
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", ret.s[i][j]);
        printf("\n");
    }
    */
    return ret;
}

Mat pow_mat(Mat x, int n) {
    Mat ret;
    for (int i = 0; i < N; i++)
        ret.s[i][i] = 1;
    while (n) {
        if (n&1)
            ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();

        if (N == 0 || M == 0) {
            printf("0\n");
            continue;
        }

        Mat x = solve();
        Mat ret = pow_mat(x, M-1);

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = (ans + ret.s[i][j]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
