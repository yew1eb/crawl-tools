#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1e3 + 5;
const double exps = 1e-8;

LL dp[MX];

int main() {
    LL n;//FIN;
    while(~scanf("%I64d", &n)) {
        memset(dp, 0, sizeof(dp));
        int p = ceil(log2(1.0 * n)) + 1;

        LL ans = 1;
        for(int i = p; i >= 2; i--) {
            dp[i] = pow(1.0 * n, 1.0 / i) - 1 + exps;
            for(int j = 2 * i; j <= p; j += i) {
                dp[i] -= dp[j];
            }
            ans += dp[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
