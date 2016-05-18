#include "stdio.h"
#include <math.h>
#define MAXINT 65536
int main()
{
	bool prime[MAXINT];
	int i, l, j, n;
	//构造素数表
	for (i = 0; i < MAXINT; i++)
		prime[i] = 1;
	l = sqrt((double)MAXINT);
	for(i = 2; i <= l; i++)
		if(prime[i])
			for(j = 2; j*i < MAXINT; j++)
				prime[j*i] = 0;
	//构造素数表
    while(~scanf("%d",&n))
	{
		if(n == 0) break;
		l = n/2, j = 0;
		for (i = 2; i <= l; i++)
			if (prime[i] && prime[n-i])
				j++;
        printf("%d\n", j);
    }
    
    return 0;
}