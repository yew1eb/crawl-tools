#include<stdio.h>

int a[6],pri,n;

__int64 getf(int x,int i)
{
	int j;
	__int64 sum=0;
	for(j=0;j<i;j++)
	{
		sum=(sum+a[j])*x;
	}
	return sum+a[j];
}

void solve()
{
	int i,j,k;
	int pri2=pri*pri;
	for(i=0;i<pri;i++)
	{
		if((getf(i,n))%pri==0)
		{
			for(j=i;j<pri2;j+=pri)
			{
				if(getf(j,n)%pri2==0)
				{
					printf("%d\n",j);
					return ;
				}
			}
		}
	}
	printf("No solution!\n");
}
int main()
{
	int i,j,k,t,no;
	__int64 temp;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&pri);
		printf("Case #%d: ",k);
		solve();
	}
	return 0;
}