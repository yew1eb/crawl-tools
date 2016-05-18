#include <stdio.h>
int main()
{
	int n, hi[51], i, sum, avg, step, count;
	count = 1;
	scanf("%d", &n);
	while (n) 
	{
		sum = 0;
		avg = 0;
		step = 0;
		for (i = 0; i < n; i++) 
		{
			scanf("%d", &hi[i]);
			sum += hi[i];
		}
		avg = sum/n;
		for (i = 0; i < n; i++) 
		{
			if (avg > hi[i]) 
				step += avg - hi[i];
		}
		printf("Set #%d\n", count++);
		printf("The minimum number of moves is %d.\n\n", step);
		scanf("%d", &n);
	}
	return 0;
}