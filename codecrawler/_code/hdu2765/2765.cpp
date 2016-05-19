#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (1100)
typedef long long LL;

int dp[MAXN];

int DFS(int n)
{
	if (dp[n]) return dp[n];
	if (n == 0) return dp[n] = 1;
	if (n == 1) return dp[n] = 1;
	int res = 0;
	if (n % 2 == 0) res += DFS(n / 2);
	Rep(i, 1, n + 1) if ((n - i) % 2 == 0)
		res += DFS((n - i) / 2);
	return dp[n] = res;
}

int main()
{
	int T, n, Cas = 1;
	Rep(i, 1, 1001) DFS(i);
	scanf("%d", &T);
	while (T--) scanf("%d", &n), printf("%d %d\n", Cas++, dp[n]);
	return 0;
}