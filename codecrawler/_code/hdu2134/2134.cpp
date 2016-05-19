#include"stdio.h"
#include"math.h"
#define pi 3.1415926
int main()
{
	int r;
	double a,b,s;
	while(scanf("%d",&r)!=EOF)
	{
		if(r==0)break;
		s=pi;
		s=s/3;
		a=r*sqrt(s/pi);
		b=r*sqrt((s*2)/pi);
		printf("%.3f %.3f\n",a,b);
	}
	return 0;
}