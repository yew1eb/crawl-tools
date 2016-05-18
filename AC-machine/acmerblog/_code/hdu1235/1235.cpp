#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int num[10005];
	int flag;
	int i;
	while(cin>>n&&n)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>=0)
			{
				flag=0;
			}
		}
		
		if(flag)
		{
			printf("0 %d %d\n",num[0],num[n-1]);
			continue;
		}
		else
		{
			int sum=num[0];
			int max=num[0];
			int temp=0;
			int start=0,end=0;
			for(i=1;i<n;i++)
			{
				if(sum<0)
				{
					sum=0;
					temp=i;
				}
				sum+=num[i];
				if(max<sum)
				{
					max=sum;
					start=temp;
					end=i;
				}
				
			}
			printf("%d %d %d\n",max,num[start],num[end]);
		}
	}
	return 0;
}