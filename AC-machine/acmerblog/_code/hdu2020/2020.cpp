/**
 * Author: Gneveek
 * Data: 2011-10-9
 * Descripition:  hdu - 2020
 */ 
#include <stdio.h>
#include <stdlib.h>

struct a{
	int x;
	int y;
};

int int_cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	//freopen("C:\\in.txt","r",stdin);
	struct a data[105];
	int n,i;
	while(scanf("%d",&n), n != 0)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d",&data[i].x);
			if(data[i].x < 0)
			{
				data[i].y = 1;
				data[i].x = -data[i].x;
			}				
			else
				data[i].y = 0;
		}
		qsort(data,n,2*sizeof(int),int_cmp);
		
		for(i=0; i<n; i++)
		{
			if(data[i].y == 1)
			{
				if(i == n-1)
					printf("-%d",data[i].x);
				else
					printf("-%d ",data[i].x);
			}				
			else
			{
				if(i == n-1)
					printf("%d",data[i].x);
				else
					printf("%d ",data[i].x);
			}
				
		}
		putchar('\n');
	}
	return 0;
}