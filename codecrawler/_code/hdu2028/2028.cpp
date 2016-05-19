#include<stdio.h>
#include<stdlib.h>
int  LCM(int a,int b)
{
	int x;
	while (a%b)
	{
		x = b;
		b = a%b;
		a = x;
	}
	return b;
}
int main()
{
	int a[101], s = 1, n, i;
	while(scanf("%d", &n)!=EOF)
	{
		s = 1;
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(i=0;i<n;i++)
			s = s/LCM(s,a[i])*a[i];
		printf("%d\n", s);
	}
}