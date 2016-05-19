#include <cstdlib>    
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const int N = 2500+10;
vector<int> v[N];
int dis[N];
int maxv;
int e;
int par[N];
int p[N];
int n;
void dfs(int cur, int h, int pa)
{
	par[cur] = pa;
	if (dis[cur] < h) dis[cur] = h;
	if (maxv <= h) maxv = h, e = cur;
	for (int i = 0; i < v[cur].size(); i++)
	{
		if (pa == v[cur][i] || v[cur][i] < 0) continue;
		dfs(v[cur][i], h + 1, cur);
	}
}

int getans(int x, int y, int& tx, int& ty)
{
	int ret = 0;
	tx = x;
	ty = y;
	MEM(dis, 0);
	maxv = 0;
	e = x;
	dfs(e, 0, -1);
	dfs(e, 0, -1);
	dfs(e, 0, -1);
	int minv1 = N;
	for (int i = 1; i <= n; i++) if (dis[i] < minv1 && dis[i] > 0) minv1 = dis[i], tx = i;
	int ans1 = maxv;
	MEM(dis, 0);
	maxv = 0;
	e = y;
	dfs(e, 0, -1);
	dfs(e, 0, -1);
	dfs(e, 0, -1);
	int minv2 = N;
	for (int i = 1; i <= n; i++) if (dis[i] < minv2 && dis[i] > 0) minv2 = dis[i], ty = i;
	int ans2 = maxv;
	ret = max(ans1, ans2);
	ret = max(ret, (ans1 + 1) / 2 + (ans2 + 1) / 2 + 1);
	return ret;
}
int main()
{

	//freopen("input.txt", "r", stdin);
	int x, y;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		MEM(par, -1);
		MEM(dis, 0);
		maxv = 0;
		e = 1;
		dfs(1, 0, -1);
		dfs(e, 0, -1);
		memcpy(p, par, sizeof(p));
		int ans = maxv;
		int a1, a2, a3, a4;
		int u = e;
		while (p[u] != -1)
		{
			int u1 = u;
			int u2 = p[u];
			int k1;
			int k2;
			int u3;
			int u4;
			for (int i = 0; i < v[u1].size(); i++) if (v[u1][i] == u2) v[u1][i] = -u2, k1 = i;
			for (int i = 0; i < v[u2].size(); i++) if (v[u2][i] == u1) v[u2][i] = -u1, k2 = i;
			int tmp = getans(u1, u2, u3, u4);
			if (ans > tmp)
			{
				ans = tmp;
				a1 = u1;
				a2 = u2;
				a3 = u3;
				a4 = u4;
			}
			v[u1][k1] = -v[u1][k1];
			v[u2][k2] = -v[u2][k2];
			u = p[u];
		}
		if (a1 > a2) swap(a1, a2);
		if (a3 > a4) swap(a3, a4);
		printf("%d\n%d %d\n%d %d\n", ans, a1, a2, a3, a4);
	}
	return 0;
}