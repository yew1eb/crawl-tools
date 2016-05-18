//BZOJ1067; WorstWeather Ever (SCOI2007); RMQ-ST
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#define N 100000
#define LOGN 18

int n, st[LOGN + 1][N + 1], q, x, y, d[N + 1], a[N + 1], ans, logn, Log[N + 1];

int query(int l, int r)
{
	if (l > r) return INT_MIN;
	int len = Log[r - l + 1];
	return std::max(st[len][l], st[len][r - (1 << len) + 1]);
}

void build()
{
	logn = Log[n];
	for (int i = 0; i <= n; ++i) st[0][i] = a[i];
	for (int i = 1; i <= logn; ++i)
		for (int j = 1; j <= n - (1 << i) + 1; ++j)
			st[i][j] = std::max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	
}
//lower_bound returns the first elements not less than x (>=)
inline int getpos(int x)
{ return std::lower_bound(d + 1, d + n + 1, x) - d; }

int main()
{
	for (int i = 1, j = 1, k = -1; i <= N; ++i)
		if (i == j) Log[i] = ++k, j <<= 1;
		else Log[i] = k;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", d + i, a + i);
	scanf("%d", &q);
	build();
	while (q--)
	{
		scanf("%d%d", &x, &y);
		int l = getpos(x), r = getpos(y), m;
		bool lx = l <= n && d[l] == x, rx = r <= n && d[r] == y;
		if (!rx) --r;
		if (lx)
			if (rx)
			{
				m = query(l + 1, r - 1);
				if (a[l] < a[r]) ans = 0;
				else
					if (m < a[r])
						if (r - l == y - x) ans = 1;
						else ans = -1;
					else ans = 0;
			}
			else
			{
				m = query(l + 1, r);
				if (m < a[l]) ans = -1;
				else ans = 0;
			}
		else
			if (rx)
			{
				m = query(l, r - 1);
				if (m < a[r]) ans = -1;
				else ans = 0;
			}
			else ans = -1;
		if (ans == 1) printf("true\n");
		else if (!ans) printf("false\n");
		else printf("maybe\n");
	}
	return 0;
}