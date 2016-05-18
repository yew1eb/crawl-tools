#include<stdio.h>
int main()
{
	int i,j,k,n,m,sum;
	while(scanf("%d%d",&m,&k),k||m)
	{
		sum=0;
		 n=m;
		 while(n>=k)
		 {
			 i=n/k;
			 j=n%k;
			 sum+=i;
			 n=i+j;
		 }
		 printf("%d\n",sum+m);
	}
	return 0;
}