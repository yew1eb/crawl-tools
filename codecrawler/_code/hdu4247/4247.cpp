#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int op=1,a[4],sum;
	while(scanf("%d",&a[0])!=-1)
	{
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		qsort(a,4,sizeof(a[0]),cmp);
		sum=a[0]+a[1];
		printf("Case %d: %d\n",op++,sum);
	}
	return 0;
}