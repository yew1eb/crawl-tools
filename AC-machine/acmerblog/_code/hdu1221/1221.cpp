#include"stdio.h"
#include"string.h"
#include"math.h"
struct node
{
	double x,y;
}aa[5];
int main()
{
	int T;
	int n,t;
	double x,y,r;
	double x1,x2,y1,y2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&x,&y,&r);
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		aa[0].x=x;aa[0].y=y;
		if(x1>x2){t=x1;x1=x2;x2=t;}
		if(y1>y2){t=y1;y1=y2;y2=t;}
		double t1,t2;
		int f1,f2,f3,f4;
		f1=f2=f3=f4=0;
		if((r*r-(x1-x)*(x1-x))>=0)
		{
			t1=sqrt((r*r-(x1-x)*(x1-x)))+y;
			t2=-sqrt((r*r-(x1-x)*(x1-x)))+y;
			if(t1>=y1&&t1<=y2||t2>=y1&&t2<=y2)f1=1;
		}
		if((r*r-(x2-x)*(x2-x))>=0)
		{
			t1=sqrt((r*r-(x2-x)*(x2-x)))+y;
			t2=-sqrt(r*r-(x2-x)*(x2-x))+y;
			if(t1>=y1&&t1<=y2||t2>=y1&&t2<=y2)f2=1;
		}
		if((r*r-(y1-y)*(y1-y))>=0)
		{
			t1=sqrt(r*r-(y1-y)*(y1-y))+x;
			t2=-sqrt(r*r-(y1-y)*(y1-y))+x;
			if(t1>=x1&&t1<=x2||t2>=x1&&t2<=x2)f3=1;
		}
		if((r*r-(y2-y)*(y2-y))>=0)
		{
			t1=sqrt(r*r-(y2-y)*(y2-y))+x;
			t2=-sqrt(r*r-(y2-y)*(y2-y))+x;
			if(t1>=x1&&t1<=x2||t2>=x1&&t2<=x2)f4=1;
		}
		if(f1||f2||f3||f4)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}