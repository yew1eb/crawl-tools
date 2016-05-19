/*0ms,260KB*/

#include <cstdio>

int main(void)
{
	int T = 0, n, p, q;
	while (~scanf("%d%d%d", &n, &p, &q))
		printf("Case %d: %.4f\n", ++T, (q + 1.0) / (p + 2));
	return 0;
}
