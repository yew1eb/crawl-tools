#include<iostream>
using namespace std;

int main()
{
	int n, p=1;
	scanf("%d", &n);
	while(n--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int t;
		if(a > b)
		{
			t=a;
			a=b;
			b=t;
		}
		if(b > c)
		{
			t=b;
			b=c;
			c=t;
		}
		if(a > b)
		{
		
			t=a;
			a=b;
			b=t;
		}
		printf("Case %d: ", p++);
		if(a*a+b*b == c*c)
			printf("Right triangle\n");
		else if(a*a+b*b > c*c)
			printf("Acute triangle\n");
		else
			printf("Obtuse triangle\n");
	}
	return 0;
}