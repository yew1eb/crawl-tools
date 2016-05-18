#include<stdio.h>
int main()
{
	int n,t,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		p=0;
		while(n%2==0) //奇数除以2余数为1
		{
			p++; //记录次数
			n/=2;
		}
		printf("%d %d\n",n,p);
	}
	return 0;
}