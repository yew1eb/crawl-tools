#include<stdio.h>
int main()
{
	int a,i,n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d/n",sum);
	}
}