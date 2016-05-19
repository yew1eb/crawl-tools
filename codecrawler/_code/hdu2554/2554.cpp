#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		if((3*n-1)%4==0 || n%4==0)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}