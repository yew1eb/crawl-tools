#include <stdio.h>
#include <string.h>

int t;
int n, m;
char map[10][10];
int judge;
int vis[20];
struct Block {
	char set[10][10];
	int num;
	int n, m;
} b[20];

int ju(int ii, int x, int y) {
	int i, j;
	for (i = x; i < x + b[ii].n; i ++)
		for (j = y; j < y + b[ii].m; j ++)
			if (map[i][j] != '0' && b[ii].set[i -x][j - y] != '0')
				return 0;
	return 1;
}
void dfs(int x, int y, int tt, int num) {
	int i, j, k;
	if (tt == t) {
		if (num == 16)
			judge = 1;
		return;
	}
	if (y > 4) {
		if (x < 4)
			dfs(x + 1, 1, tt, num);
		return;
	}
	for (i = 1; i <= t; i ++) {
		if (!vis[i] && ju(i, x, y)) {
			vis[i] = 1;
			for (j = x; j < x + b[i].n; j ++)
				for (k = y; k < y + b[i].m; k ++)
					if (b[i].set[j - x][k - y] != '0')
						map[j][k] = b[i].set[j - x][k - y] + i - 1;
			dfs(x, y + 1, tt + 1, num + b[i].num);
			if (judge) return;
			vis[i] = 0;
			for (j = x; j < x + b[i].n; j ++)
				for (k = y; k < y + b[i].m; k ++)
					if (b[i].set[j - x][k - y] != '0')
						map[j][k] = '0';
		}
	}
	dfs(x, y + 1, tt, num);
}
int main() {
	int i, j, k;
	int bo = 0;
	while (scanf("%d", &t) != EOF && t) {
		if (bo == 0) 
			bo = 1;
		else
			printf("\n");
		judge = 0;
		memset(b, 0, sizeof(b));
		memset(vis, 0, sizeof(vis));
		memset(map, '1', sizeof(map));
		for (i = 1; i <= 4; i ++)
			for (j = 1; j <= 4; j ++)
				map[i][j] = '0';
		for (i = 1; i <= t ; i ++) {
			scanf("%d%d%*c", &n, &m);
			b[i].n = n; b[i].m = m;
			for (j = 0; j < n; j ++) {
				gets(b[i].set[j]);
				int len = strlen(b[i].set[j]);
				for (k = 0; k < len; k ++)
					if (b[i].set[j][k] != '0')
						b[i].num ++;
			}
		}
		dfs(1, 1, 0, 0);
		if (judge) {
			for (i = 1; i <= 4; i ++) {
				for (j = 1; j <= 4; j ++)
					printf("%c", map[i][j]);
				printf("\n");
			}
		}
		else
			printf("No solution possible\n");
	}
	return 0;
}