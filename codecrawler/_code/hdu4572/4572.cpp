#include <stdio.h>
#include <string.h>

int main () {
	int m, n;
	while (scanf("%d%d", &m, &n) == 2) {
		int t = m - n/2 + 1;
		int s = (t + m) * (n/2);
		printf("%d\n", s + t - 1);
	}
	return 0;
}
