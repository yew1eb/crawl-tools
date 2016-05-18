#include"stdio.h"
int main()
{
	double y,q,f,g,e;
	int t,i;
	scanf("%d",&t);
	i=1;
	while(t--)
	{
		scanf("%lf %lf %lf %lf %lf",&y,&q,&e,&f,&g);
		printf("%.1lf\n",y*(1+e/100*q/365)*(1+g/100));
		printf("%.1lf\n",y*(1+f/100*(q+365)/365));
	}
	return 0;
}