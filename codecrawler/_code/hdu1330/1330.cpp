#include <stdio.h>
int main()
{
	int i, n, flag = 1;
	double sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 1; i <= n; i++)
			sum += 1.0 / (2*i);
		if (flag)
		{
			printf("# Cards  Overhang\n");
			flag = 0;
		}
		printf("%5d     %.3f\n", n, sum);
	}
	return 0;
}