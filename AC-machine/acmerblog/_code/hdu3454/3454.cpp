/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 |Author: WiYR
 |Created Time.: 2014-2-16 15:13:56
 |File Name: O.cpp
 |Description: 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
typedef long long ll;
const double eps=1e-7;
const int inf=0x7FFFFFFF;
#define rep(i,n) for(int i=0;i<n;i++)
#define mset(a,i) memset(a,i,sizeof(a))

using namespace std;
int vis[2][1 << 20];
int p[25];
int a[25], ans[25];
int m, n;
int add(int x, int val) {
	val |= p[x];
	for(int i = 2; i + x <= 20; i ++)if(val & p[i]){
		val |= p[i + x];
	}
	return val;
}
bool dfs(int val, int step) {
	if(vis[step][val] != -1)
		return vis[step][val];
	int tmp;
	rep(i, n)if(! (val & p[a[i]])) {
		tmp = add(a[i], val);
		bool ret = dfs(tmp, step ^ 1);
		if(step && !ret) {
			vis[1][val] = 0;
			vis[0][val] = 1;
			return false;
		}
		if(!step && ret) {
			vis[0][val] = 1;
			vis[1][val] = 0;
			return true;
		}
	}
	vis[1][val] = 1;
	vis[0][val] = 0;
	return step == 1;
}
int main() {
	int T, cas = 0, val;
	p[1] = 1;
	for(int i = 2; i <= 21; i ++)
		p[i] = p[i - 1] << 1;
	mset(vis, -1);
	vis[1][p[21] - 1] = 1;
	vis[0][p[21] - 1] = 0;

	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n);
		val = p[21] - 1;
		rep(i, n) {
			scanf("%d", &a[i]);
			val ^= p[a[i]];
		}
		m = 0;
		int tmp;
		rep(i, n) {
			tmp = add(a[i], val);
			if(dfs(tmp, 1))
				ans[m ++] = a[i];
//			printf("%d ", vis[0][p[21] - 1]);
		}
		printf("Scenario #%d:\n", ++ cas);
		if(m) {
			printf("The winning moves are:");
			sort(ans, ans + m);
			rep(i, m) {
				printf(" %d", ans[i]);
			}
			puts(".\n");
		} else {
			puts("There is no winning move.\n");
		}
	}
	return 0;
}