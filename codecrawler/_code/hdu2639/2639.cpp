#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b)	((a)>(b)?(a):(b))
const int maxn = 1005;
int main()
{
	int T;
	scanf("%d", &T);
	int dp[maxn][33], val[maxn], vol[maxn], A[33], B[33];
	while (T--)
	{
		int n, v, k;
		scanf("%d %d %d", &n, &v, &k);
		int i, j, kk;
		for (i=0; i<n; i++) scanf("%d", &val[i]);
		for (i=0; i<n; i++) scanf("%d", &vol[i]);
		memset(dp, 0, sizeof(dp));

		int a, b, c;
		for (i=0; i<n; i++)
			for (j=v; j>=vol[i]; j--)
			{
				for (kk=1; kk<=k; kk++)
				{
					A[kk] = dp[j-vol[i]][kk] + val[i];
					B[kk] = dp[j][kk];
				}
				A[kk] = -1, B[kk] = -1;
				a = b = c = 1;
				while (c<=k && (A[a] != -1 || B[b] != -1))
				{
					if (A[a] > B[b])
						dp[j][c] = A[a++];
					else
						dp[j][c] = B[b++];
					if (dp[j][c] != dp[j][c-1])
						c++;
				}
			}

		printf("%d\n", dp[v][k]);
	}
	return 0;
}