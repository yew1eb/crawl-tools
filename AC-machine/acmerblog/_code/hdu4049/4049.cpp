/*******************************************************************************
    去年北京赛区网络赛水题，状态压缩DP，一开始TLE，然后发现是没初始化，应该用空间换时间来着，
接着WA，搞了半天没搞明白。。。最后发现发现一个小小的纰漏～～～
    解法就是建立状态dp[M][1 << N]，用第一个状态表示第i个城市，第二个状态表示决定在这个城市
里游玩的人的状态，用二进制表示～然后就是很裸很裸的状态压缩DP了～
*******************************************************************************/
#include <iostream>
#include <functional>
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define LOWBIT(x) ( (x) & ( (x) ^ ( (x) - 1 ) ) )
#define CLR(x, k) memset((x), (k), sizeof(x))
#define CPY(t, s) memcpy((t), (s), sizeof(s))
#define SC(t, s) static_cast<t>(s)
#define LEN(s) static_cast<int>( strlen((s)) )
#define SZ(s) static_cast<int>( (s).size() )

typedef double LF;
typedef __int64 LL;		//VC
typedef unsigned __int64 ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VF;
typedef vector<string> VS;

template <typename T>
T sqa(const T & x)
{
	return x * x;
}
template <typename T>
T gcd(T a, T b)
{
	if (!a || !b)
	{
		return max(a, b);
	}
	T t;
	while (t = a % b)
	{
		a = b;
		b = t;
	}
	return b;
};

const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffffLL;		//15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);

#define  ONLINE_JUDGE

const int MAXN = 12;
const int MAXM = 12;
const int MAXS = (1 << MAXN);

int n, m, cost[MAXM], inter[MAXN][MAXM], bonus[MAXN][MAXN];
int dp[2][MAXS], maze[MAXM][MAXS];
bool hs[MAXN];
VI G[MAXS];

int valueCount(int city, int status)
{
	int res = 0, bit = 0;
	CLR(hs, false);
	for (int ind = 0; ind < n; ++ind)
	{
		if (status & (1 << ind))
		{
			hs[ind] = true;
			++bit;
		}
	}
	res -= bit * cost[city];
	for (int i = 0; i < n; ++i)
	{
		if (hs[i])
		{
			res += inter[i][city];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (!hs[i])
		{
			continue ;
		}
		for (int j = i + 1; j < n; ++j)
		{
			if (hs[j])
			{
				res += bonus[i][j];
			}
		}
	}
	return res;
}
bool inline containsJudge(const int & lhs, const int & rhs)
{
	return (lhs & rhs) == lhs;
}
void init()
{
	int buf = (1 << n);
	for (int city = 0; city < m; ++city)
	{
		for (int ind = 0; ind < buf; ++ind)
		{
			maze[city][ind] = valueCount(city, ind);
		}
	}
	for (int i = 0; i < buf; ++i)
	{
		G[i].clear();
		for (int j = i + 1; j < buf; ++j)
		{
			if (containsJudge(i, j))
			{
				G[i].push_back(j);
			}
		}
	}
	return ;
}
int solve()
{
	CLR(dp[0], -INF_INT);
	CLR(dp[1], 0);
	int res = 0, buf = (1 << n);
	for (int ind = 0, k = 0; ind < m; ++ind, k ^= 1)
	{
		for (int crt = 0; crt < buf; ++crt)
		{
			dp[k][crt] = dp[k ^ 1][crt] + maze[ind][crt];
			res = max(res, dp[k][crt]);						//TMD相当无语了。。。
			for (VI::iterator it = G[crt].begin(); it != G[crt].end(); ++it)
			{
				int nxt = *it;
				dp[k][crt] = max(dp[k][crt], dp[k ^ 1][nxt] + maze[ind][crt]);
				res = max(res, dp[k][crt]);
			}
		}
	}
	return res;
}
void ace()
{
	int ans;
	while (cin >> n >> m, n || m)
	{
		for (int i = 0; i < m; ++i)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> inter[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> bonus[i][j];
			}
		}
		init();
		ans = solve();
		if (0 >= ans)
		{
			puts("STAY HOME");
			continue ;
		}
		cout << ans << endl;
	}
	return ;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ace();
	return 0;
}
/*******************************************************************************
Test Data...

2 1
10
15
5
0 5
5 0
3 2
30 50
24 48
40 70
35 20
0 4 1
4 0 5
1 5 0
2 2
100 100
50 50
50 50
0 20
20 0
0 0
*******************************************************************************/
