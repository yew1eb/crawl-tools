#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int main() {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c)!=EOF) {
		double x = (double)(b + c) / (a + b + 2 * c);
		printf("%.6lf\n", (1 - x) * b - c * x);
	}	
	return 0;
}