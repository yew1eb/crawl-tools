/********************************************************************************
	剪个枝就过了～比赛的时候没什么人做，主要是因为位运算的威慑力太大了～
********************************************************************************/
#include <iostream>
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <bitset>
#include <cstdio>
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

#define lowbit(x) ( (x) & ( (x) ^ (x - 1) ) )

//typedef long long LL;
//typedef unsigned long long ULL;
typedef __int64 LL;
typedef unsigned __int64 ULL;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

typedef map<int, int>::iterator MI;
typedef vector<int>::iterator VI;
typedef list<LL>::iterator LI;
typedef set<int>::iterator SI;

const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffff;
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);

const int MAXN = 44;

int test, n, m;
LL ans, arr[MAXN];

bool check(int id, LL buf)
{
	for (int i = id + 1; i < n; ++i)
	{
		buf &= arr[i];
	}
	return buf < ans;
}
void dfs(int crt, int step, LL buf)
{
	ans = min(ans, buf);
	if (step >= m)
	{
		return ;
	}
	for (int nxt = crt + 1; nxt < n; ++nxt)
	{
		LL tmp = buf & arr[nxt];
		if (!check(nxt, tmp))
		{
			continue ;
		}
		dfs(nxt, step + 1, tmp);
	}
	return ;
}
void ace()
{
	int cas = 1;
	for (scanf("%d", &test); test--; ++cas)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d", arr + i);
		}
		sort(arr, arr + n);
		ans = INF_LL;
		for (int i = 0; i < n; ++i)
		{
			dfs(i, 1, arr[i]);
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return ;
}
int main()
{
	ace();
	return 0;
}