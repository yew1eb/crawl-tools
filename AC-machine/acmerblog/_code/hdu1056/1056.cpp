#include<stdio.h>
double s,n;
int c;
main()
{
	while(scanf("%lf",&n)==1&&n>0)
	{
		for(c=1,s=0.5;s<n;c++)
			s+=(1.0/(c+2));
		printf("%d card(s)\n",c);
	}
}