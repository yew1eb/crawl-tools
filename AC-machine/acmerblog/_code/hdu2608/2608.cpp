#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,t,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
			sum=0;
			for(i=1;i<=n;i++)
			{
				
				if(2*i*i<=n)
					sum++;
				if(i*i<=n)
				sum++;
				else break;
			}
			printf("%d\n",sum%2);
	}
	return 0;
}