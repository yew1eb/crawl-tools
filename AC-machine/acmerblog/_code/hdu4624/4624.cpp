#pragma warning(disable:4996)
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<list>
#include<time.h>
#include<bitset>
using namespace std;

#define ll long long
#define maxn 55

ll dp[maxn][2][maxn*(maxn + 1) / 2];
double E[maxn];

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(E, 0, sizeof(E));
	dp[0][0][0] = 1;
	for (int i = 0; i <= 50; ++i){
		for (int j = 0; j <= (i + 1)*i / 2; ++j){
			if (dp[i][0][j]) {
				for (int k = i + 1; k <= 50; ++k){
					dp[k][1][j + (k - i)*(k - i - 1) / 2] += dp[i][0][j];
				}
			}
			if (dp[i][1][j]){
				for (int k = i + 1; k <= 50; ++k){
					dp[k][0][j + (k - i)*(k - i-1) / 2] += dp[i][1][j];
				}
			}
		}
	}

	for (int i = 1; i <= 50; ++i){
		for (int k = 0; k <= i; ++k){
			for (int j = 0; j <= (k + 1)*k / 2; ++j){
				if (dp[k][0][j]){
					long double p = (j + (i - k + 1)*(i - k) / 2 + .0) / ((i + 1)*i / 2);
					if (p == 1.0) { continue; }
					E[i] -= dp[k][0][j] / (1 - p);
				}
				if (dp[k][1][j]){
					long double p = (j + (i - k + 1)*(i - k) / 2 + .0) / ((i + 1)*i / 2);
					if (p == 1.0) { continue; }
					E[i] += dp[k][1][j] / (1 - p);
				}
			}
		}
	}
	int xx;
	cin >> xx;
}

