#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

inline void scanf_(int &num)//æ è´æ°
{
    char in;
    while((in=getchar()) > '9' || in<'0') ;
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
    num*=10,num+=in-'0';
}

int n, v[2049], mi[15], m, cnt[15];
int dp[15][2049], mi2[100005], invv[100005];
bool istwo[2049];

void init() {
    int num;
    m = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
    scanf_(num);
    if (!istwo[num]) {
        m++;
        continue;
    }
    else cnt[v[num]]++;
    }
}

int inv(int n) {
    int ans = 1;
    int k = MOD - 2;
    while (k) {
    if (k&1) ans = (ll)ans * n % MOD;
    n = (ll)n * n % MOD;
    k >>= 1;
    }
    return ans;
}

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 12; i++) {
    for (int j = 0; j <= 2048; j += mi[i]) {
        if (dp[i - 1][j] == 0) continue;
        int C = 1, s = 0;
        int sum = j;
        for (int k = 0; k <= cnt[i]; k++) {
        int x = sum;
        if (x == 2048) {
            dp[i][x] = (ll)dp[i - 1][j] * (mi2[cnt[i]] - s) % MOD + dp[i][x];
            if (dp[i][x] < 0) dp[i][x] += MOD;
            if (dp[i][x] >= MOD) dp[i][x] -= MOD;
            break;
        }
        if (x % mi[i + 1])
            x = x - mi[i];
        dp[i][x] = (ll)dp[i - 1][j] * C % MOD + dp[i][x];
        if (dp[i][x] >= MOD) dp[i][x] -= MOD;
        s += C;
        if (s >= MOD) s -= MOD;
        C = (ll)C * (cnt[i] - k) % MOD * invv[k + 1] % MOD;
        sum += mi[i];
        }
    }
    }
    return (ll)dp[12][2048] * mi2[m] % MOD;
}

int main() {
    memset(istwo, false, sizeof(istwo));
    memset(v, -1, sizeof(v));
    mi[0] = 0; v[0] = 0;
    for (int i = 1, j = 1; i <= 2048; i *= 2, j++) {
    istwo[i] = true;
    v[i] = j;
    mi[j] = i;
    }
    mi[13] = 4096;
    for (int i = 1; i <= 2048; i++) {
    if (v[i] == -1)
        v[i] = v[i - 1];
    }
    mi2[0] = 1;
    for (int i = 1; i <= 100000; i++) {
    invv[i] = inv(i);
    mi2[i] = mi2[i - 1] * 2 % MOD;
    }
    int cas = 0;
    while (~scanf("%d", &n) && n) {
    init();
    printf("Case #%d: %d\n", ++cas, solve());
    }
    return 0;
}