#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e6;
const int maxm = 6;

int price[maxm] = {100, 50, 10, 5, 2, 1};

int dp[maxn + 100];

void run_dp() {
    fill(dp, dp + maxn, (1 << 30));
    dp[0] = 0;
    for(int i = 1; i <= maxn; i++) {
        for(int j = 0; j < maxm; j++) {
            if(i >= price[j]) dp[i] = min(dp[i], dp[i - price[j]] + 1);
        }
    }
}

void debug() {
    for(int i = 0; i < 100; i++) cout << i << " " << dp[i] << endl;
}

int main() {
    int n;
    run_dp();
    //debug();
    while(~scanf("%d", &n), n) {
        int ans = 0, tmp;
        for(int i = 0; i < n; i++) scanf("%d", &tmp), ans += dp[tmp];
        printf("%d\n", ans);
    }
    return 0;
}
