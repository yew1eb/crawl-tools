#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck(x) cout<<"["<<x<<"]"
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;

const int MX = 100 + 5;
const int mod = 1e9 + 7;

int na[MX], nb[MX], nx[MX];
LL l, r, g, t, dp[MX][2][2];

LL S(LL a, LL b, LL x) {
    memset(dp, 0, sizeof(dp));
    for(int i = 63; i >= 0; i--) {
        na[i] = a >> i & 1;
        nb[i] = b >> i & 1;
        nx[i] = x >> i & 1;
    }

    dp[63][1][1] = 1;
    for(int i = 62; i >= 0; i--) {
        if(na[i] ^ nb[i] == nx[i]) {
            dp[i][1][1] += dp[i + 1][1][1];
        }

        dp[i][1][0] += dp[i + 1][1][0];
        if(nb[i] && na[i] == nx[i]) dp[i][1][0] += dp[i + 1][1][1];

        dp[i][0][1] += dp[i + 1][0][1];
        if(na[i] && nb[i] == nx[i]) dp[i][0][1] += dp[i + 1][1][1];

        dp[i][0][0] += dp[i + 1][0][0] * 2;
        if(na[i]) dp[i][0][0] += dp[i + 1][1][0];
        if(nb[i]) dp[i][0][0] += dp[i + 1][0][1];
        if(na[i] && nb[i] && !nx[i]) dp[i][0][0] += dp[i + 1][1][1];
    }
    return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
}

LL solve() {
    LL ret = (r - l + 1) * 2, x = g ^ t;
    ret -= S(r, r, x) - S(l - 1, r, x) * 2 + S(l - 1, l - 1, x);
    return ret % mod;
}

int main() {
    int T; //FIN;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d%I64d%I64d%I64d", &l, &r, &g, &t);
        printf("%I64d\n", solve());
    }
    return 0;
}
