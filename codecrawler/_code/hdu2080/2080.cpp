#include<stdio.h>
#include<math.h>
#define PI 3.141592654
#define esp 1e-10
int main()
{
	int t;
	double x1,x2,y1,y2,a,b,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a=sqrt(x1*x1+y1*y1);
		b=sqrt(x2*x2+y2*y2);
		m=(x1*x2+y1*y2)/(a*b);
		printf("%.2f\n",acos(m)*180/PI);
	}
	return 0;
}