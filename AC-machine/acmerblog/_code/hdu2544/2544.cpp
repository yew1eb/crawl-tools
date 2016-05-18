/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        hdu2544.cpp
*  Create Date: 2013-11-28 15:37:26
*  Descripton:  min path, floyd
*/

#include <cstdio>
#include <cstring>

const int MAXN = 110;
const int INF = 0x3c3c3c3c - 1;

int nn, en;	// num of node and edge
int map[MAXN][MAXN];

int min(int a, int b) {
	return a < b ? a : b;
}

int floyd() {
	for (int k = 1; k <= nn; k++)
		for (int i = 1; i <= nn; i++)
			for (int j = 1; j <= nn; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main() {
	int s, e, t;
	while (~scanf("%d%d", &nn, &en) && (nn || en)) {
		// init
		for (int i = 1; i <= nn; i++)
			for (int j = 1; j <= nn; j++)
				map[i][j] = INF;
		// input
		for (int i = 0; i < en; i++) {
			scanf("%d%d%d", &s, &e, &t);
			if (t < map[s][e])
				map[s][e] = map[e][s] = t;
		}
		floyd();
		printf("%d\n", map[1][nn]);
	}
	return 0;
}