/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2.cpp
*  Create Date: 2013-09-08 13:52:18
*  Descripton:  dfs 
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mc(a) memset(a, 0, sizeof(a))

const int MAXN = 1e5 + 1;
vector<int> v[MAXN];
int n, d, cnt;
bool vis[MAXN];

void dfs(int p, int e) {
	if (e > d) return;
	vis[p] = 1;
	cnt++;
	int len = v[p].size();
	rep(i, len)
		if (!vis[v[p][i]])
			dfs(v[p][i], e + 1);
}

int main() {
	int t, a, b;
	scanf("%d", &t);

	while (t--) {
		rep(i, n) v[i].clear();
		mc(vis);
		cnt = 0;
		scanf("%d%d", &n, &d);
		rep(i, n - 1) {
		   	scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0, 0);
		printf("%d\n", n - cnt);
	}
	return 0;
}
