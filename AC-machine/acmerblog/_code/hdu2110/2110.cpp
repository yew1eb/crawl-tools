/*
	Author: ACb0y
	Date: 2010-9-16
	Type: generation function
	ProblemId: hdu 2110 Crisis of HDU
	Result: AC
*/
#include <iostream>
using namespace std;

int n;
int p[110];
int m[110];
int c1[4100];
int c2[4100];

int main() {
	int i, j, k;
#ifndef ONLINE_JUDGE
	freopen("2110.txt", "r", stdin);
#endif
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &m[i]);
			sum += p[i] * m[i];
		}
		
		if (sum % 3) {
			printf("sorry/n"); 
			continue;
		}
		sum /= 3;
		memset(c2, 0, sizeof(c2));
		memset(c1, 0, sizeof(c1));
		c1[0] = 1;
		int flag = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j <= sum; j++) {
				if (c1[j]) {
					for (k = 0; k <= m[i] && j + k * p[i] <= sum; k++) {
						c2[j + k * p[i]] += c1[j];
					}
				}
			}
			memcpy(c1, c2, sizeof(c1));
			memset(c2, 0, sizeof(c2));
			if (c1[sum]) flag = 1;
			for (j = 0; j <= sum; j++) {
				if (c1[j] >= 10000) {
					c1[j] %= 10000;
				}
			}
		}
		if (flag) {
			printf("%d/n", c1[sum]);
		} else {
			printf("sorry/n");
		}
		
	}
	return 0;
}