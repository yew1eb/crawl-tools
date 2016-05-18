/*187ms,8044KB*/

#include<cstdio>
#include<cstring>
const int maxn = 1000000;

int hash[2 * maxn + 5];

int main()
{
	int a, b, c, d, i, j;
	long long ans;
	while (~scanf("%d%d%d%d", &a, &b, &c, &d))
	{
		if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0)
		{
			puts("0");
			continue;
		}
		memset(hash, 0, sizeof(hash));
		for (i = 1; i <= 100; ++i)
			for (j = 1; j <= 100; ++j)
				++hash[a * i * i + b * j * j + maxn];
		ans = 0L;
		for (i = 1; i <= 100; ++i)
			for (j = 1; j <= 100; ++j)
				ans += hash[-c * i * i - d * j * j + maxn];
		printf("%I64d\n", ans << 4);
	}
}