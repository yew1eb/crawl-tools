#include<iostream>
using namespace std;
#define M 987654321
int n,m;

__int64 deal(int m,int n)
{
	int i,j;
	__int64 ans=1;

	if(m==1)
		return 1;
	if(n>=m)
	{
		if(m==2)
		{
			for(i=1;i<=n;i++)
				ans=ans*m%M;
		}
		else//return A(m,m)+m
		{
			for(i=1;i<=m;i++)
				ans=(ans*i)%M;
			ans+=m;
		}
		return ans;
	}
	else if(n<m)
	{
		for(i=1;i<=n;i++)
			ans=ans*m%M;
		return ans;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==-1&&m==-1))
	{
		printf("%I64d/n",deal(m,n));
	}
}