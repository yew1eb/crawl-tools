/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3.cpp
*  Create Date: 2013-09-08 14:21:58
*  Descripton:  simulate 
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 100;
int a[MAXN][MAXN];
int n, sum, cnt;

void solve(int k, int l) {
	int tmp = -0xffffff, tt = 0;
	rep(i, l - 1) {
		int t = a[k][k + i] + a[k + i][k + l - 1] + a[k + l - i - 1][k + 0] + a[k + l - 1][k + l - i - 1];
		if (tmp <= t) {
			if (tmp == t)
				tt = min(tt, min(i, l - i - 1));
			else
				tt = min(i, l - i - 1);
			tmp = t;
		}
	}
	sum += tmp;
	cnt += tt;
}

int main() {
	while (scanf("%d", &n) && n) {
		rep(i, n) rep(j, n)
			scanf("%d", &a[i][j]);
		int l = n / 2;
		sum = a[l][l];
		cnt = 0;
		rep(i, l)
			solve(i, n - 2 * i);
		printf("%d %d\n", sum, cnt);
	}
	return 0;
}

