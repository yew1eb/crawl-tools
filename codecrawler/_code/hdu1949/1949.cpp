#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 105;
struct state {
	int r, l, num;
}s[N * N];
int n, m, ans, begin, end, sum, f[N];

int getfather(int x) {
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

bool cmp(const state& a, const state& b) {
	return a.num > b.num;
}

void init() {
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].num);
	scanf("%d%d%d", &begin, &end, &sum);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	sort(s, s + m, cmp);
}

int kruskal() {
	for (int i = 0; i < m; i++) {
		int p = getfather(s[i].l), q = getfather(s[i].r);
		if (p != q) {
			f[p] = q;
			if (getfather(begin) == getfather(end))
				return s[i].num;
		}
	}
	return 0;
}

int solve() {
	if (sum % ans)
		return sum / (ans - 1) + 1;
	else
		return sum / (ans - 1);
}

int main () {
	int cas = 1;
	while (scanf("%d%d", &n, &m), n || m ) {
		init();
		ans = kruskal();
		printf("Scenario #%d\n", cas++);
		printf("Minimum Number of Trips = %d\n\n", solve());
	}
	return 0;
}