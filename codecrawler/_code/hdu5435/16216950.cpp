#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int maxd = 16;
const int mod = 1e9 + 7;

ll dp[maxn][maxd + 5];
char a[maxn], b[maxn];

int get(char* s) {
    int n = strlen(s), ret = 0;
    for (int i = 0; i < n; i++)
        ret ^= (s[i]-'0');
    return ret;
}

ll solve (char* s) {
    int n = strlen(s), pre = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        if (i) {
            for (int x = 0; x < maxd; x++) {
                for (int y = 0; y < 10; y++) {
                    int v = x^y;
                    dp[i][v] = (dp[i][v] + dp[i-1][x]) % mod;
                }
            }
        }

        for (int x = 0; x < s[i]-'0'; x++) {
            int v = pre^x;
            dp[i][v] = (dp[i][v] + 1) % mod;
        }
        pre ^= s[i]-'0';
    }

    ll ret = 0;
    for (int i = 0; i < maxd; i++)
        ret = (ret + dp[n-1][i] * i) % mod;
    return ret;
}

int main () {

    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%s%s", a, b);
        ll l = solve(a);
        ll r = solve(b);
        ll ans = ((r - l + mod) % mod + get(b)) % mod;
        printf("Case #%d: %d\n", kcas, (int)ans);
    }
    return 0;
}
