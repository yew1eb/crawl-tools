#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1011;

int a[maxn], b[maxn], n, t;

int main() {
	while (cin >> n >> t) {
		int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0; i < n; i++)
			if (a[i] + b[n-i-1] > t)
				ans += a[i] + b[n-i-1] - t;
		printf("%d\n", ans);
	}
	return 0;
}