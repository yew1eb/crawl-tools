#include<stdio.h>

int main()
{
	int n;
	int sum;   

	while(scanf("%d",&n)!=EOF)  //eof notice
	{
		//一定要这么算
		if(n%2==0)
			sum=n/2*(1+n);
		else
			sum = (1+n)/2*n;
		printf("%d/n/n",sum); 
	}
	return 0;
}