#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn = 5000005;
const int mod = 1000000007;

int dp[maxn], num[maxn];

void init() {
	dp[3] = 1;
	for (int i = 4; i < maxn; i++) {
		dp[i] = dp[i-1] + floor((i-1)/2.0) - ceil(i/3.0) + 1;
		if (!(i & 1)) 
			dp[i] -= i / 4;
		dp[i] %= mod;
		if (dp[i] < 0) dp[i] += mod;
	}
	
	num[1] = 1;
	for (int i = 2; i < maxn; i++) {
		num[i] = (num[i-1] << 1) % mod;
		for (int j = 2; i * j < maxn; j++) {
			dp[i * j] -= dp[i];
			if (dp[i * j] < 0)
				dp[i * j] += mod;
		}
	}
}

int main() {
	int n, t, cas = 1;
	init();
	while (scanf("%d", &n) != EOF) {
		ll ans = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i) continue;
			ans = (ans + (1ll*dp[i]*num[n/i])) % mod;
			if (i * i != n) 
				ans = (ans + (1ll*dp[n/i] * num[i])) % mod;
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}