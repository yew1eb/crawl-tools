#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 75;
const int mod = 1e9 + 7;

struct Mat {
    int r, c, s[maxn][maxn];

    void init(int r, int c) {
        this->r = r;
        this->c = c;
        memset(s, 0, sizeof(s));
    }
};

Mat o, x, tmp;

void presolve(int k) {
    o.init(71, 1);
    for (int i = 1; i < 10; i++) o.s[i * 7 + i % 7][0]++;

    x.init(71, 71);
    for (int i = 0; i < 10; i++) {
        for (int ki = 0; ki < 7; ki++) {
            int u = i * 7 + ki;
            for (int j = 0; j < 10; j++) if (i + j != k) {
                int v = j * 7 + (ki * 10 + j) % 7;
                x.s[v][u]++;
            }
        }
    }
    for (int i = 0; i <= 10; i++) x.s[70][i*7] = 1;
}


void mul(const Mat& a, const Mat& b, Mat& c) {
    tmp.init(a.r, b.c);
    for (int i = 0; i < tmp.r; i++) {
        for (int j = 0; j < tmp.c; j++)
            for (int k = 0; k < a.c; k++)
                tmp.s[i][j] = (tmp.s[i][j] + 1LL * a.s[i][k] * b.s[k][j] % mod) % mod;
    }
    c = tmp;
}

int pow_mod(Mat ret, Mat x, int n) {

    while (n) {
        if (n&1) mul(x, ret, ret);
        mul(x, x, x);
        n >>= 1;
    }

    return ret.s[70][0];
}

int main () {
    int cas, l, r, k;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &l, &r, &k);
        presolve(k);
        int ans = (pow_mod(o, x, r) - pow_mod(o, x, l-1) + mod) % mod;
        printf("%d\n", ans);
    }
    return 0; 
}