#include"stdio.h"
void main()
{
	int a,b,x0,y0;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&x0,&y0);
		if(x0*x0/(a*a)+y0*y0/(b*b)<1)printf("In ellipse\n");
		else printf("%d\n",a*a*b*b);
	}
}