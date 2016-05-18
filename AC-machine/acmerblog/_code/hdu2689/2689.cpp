#include<iostream>
using namespace std;
int c[1010],a[1010],n;
int lowbit(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int sum=0;
	while(x>0)
	{
		sum=sum+c[x];
		x-=lowbit(x);
	}
	return sum;
}
void inster(int x,int i)
{
	while(x<=n)
	{
		c[x]+=i;
		x+=lowbit(x);
	}
}
int main()
{
	int i,b,s;
	while(scanf("%d",&n)>0)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b);
			inster(b,1);      //求b前面小于等于b的数有多少个
			s+=i-sum(b);     //b前面大于b的数有多少个
		}
		printf("%d\n",s);
	}
	return 0;
}