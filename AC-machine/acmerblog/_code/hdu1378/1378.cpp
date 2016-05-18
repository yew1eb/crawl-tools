#include <stdio.h>
#include <string.h>
const int INF = 1 << 30;
const int MAXN = 10005;
const int N = 105;
int min(int a, int b) {return a < b ? a : b;}
int i, j, n, len[MAXN], num, dp[MAXN][N], rec[MAXN][N];
char str[MAXN], word[MAXN][N];

void init() {
	num = 0;
	memset(dp, -1, sizeof(dp));
	memset(rec, -1, sizeof(rec));
	while (gets(str) && str[0] != '\0') {
		int lens = strlen(str);
		for (int i = 0; str[i];) {
			sscanf(str + i, "%s", word[num]);
			len[num] = strlen(word[num]);
			i += len[num ++];
			while(str[i] == ' ') i ++;
		}
	}
}

int DP(int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = INF;
	if (i == num) {
		if (j == 0) {
			return dp[i][j] = 0;
		}
		else {
			return dp[i][j];
		}
	}
	if (j == 0) {
		int ans = DP(i + 1, 0);
		if (dp[i][j] > 500 + ans) {
			dp[i][j] = 500 + ans;
			rec[i][j] = 0;
		}
	}
	if (j + len[i] == n) {
		int ans = DP(i + 1, 0);
		if (dp[i][j] > ans) {
			dp[i][j] = ans;
			rec[i][j] = 0;
		}
		return dp[i][j];
	}
	else {
		int x = j + len[i] + 1;
		for (int k = x; k < n; k ++) {
			if (k + len[i + 1] > n)
				break;
			int t = k - x;
			int ans = DP(i + 1, k);
			if (dp[i][j] > t * t  + ans) {
				dp[i][j] = t * t  + ans;
				rec[i][j] = k;
			}
		}
	}
	return dp[i][j];
}

void print(int i, int j) {
	if (rec[i][j] == -1)
		return;
	printf("%s", word[i]);
	if (rec[i][j] == 0)
		printf("\n");
	else {
		for (int k = 0; k < rec[i][j] - j - len[i]; k ++)
			printf(" ");
	}
	print(i + 1, rec[i][j]);
}

int main() {
	while (~scanf("%d%*c", &n) && n) {
		init();
		DP(0, 0);
		print(0, 0);
		printf("\n");
	}
	return 0;
}