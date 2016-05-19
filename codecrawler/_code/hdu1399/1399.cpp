#include <iostream>
using namespace std;

int flag,n;
int MAX;
int judge1(int n)
{
	flag=0;
	int i;
	for(i=0;;i++)
	{
		if(i*i*i==n)
		{
			flag=1;
			return i;
		}
		else if(i*i*i>n)
			return i;
	}
}

int judge2(int n)
{
	flag=0;
	int i;
	for(i=0;;i++)
	{
		if(i*(i+1)*(i+2)/6==n)
		{
			flag=1;
			return i;
		}
		else if(i*(i+1)*(i+2)/6>n)
			return i;
	}
}

void judge(int x,int y)
{
	int i,j;
	flag=0;
	MAX=-1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			int x=i*i*i+j*(j+1)*(j+2)/6;
			if(x==n)
			{
				flag=1;
				return;
			}
			else if(x<n)
			{
				if(MAX<x)
					MAX=x;
			}
		}
	}
}
int main()
{
	int s1,s2;
	while(scanf("%d",&n),n)
	{
		s1=judge1(n);
		if(flag)
		{
			printf("%d/n",n);
			continue;
		}
		s2=judge2(n);
		if(flag)
		{
			printf("%d/n",n);
			continue;
		}
		judge(s1,s2);
		if(flag)
		{
			printf("%d/n",n);
			continue;
		}
		printf("%d/n",MAX);
	}
	return 0;
}