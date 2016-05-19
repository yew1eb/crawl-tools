/*
我的做法是：设边长为r,CE=a,AG=x,正四面体的高为sqrt(6)/3 * r,体积可以求出为sqrt(2)/12 * r*r*r ,那么只要列个方程其中一个的体积等于总体积的一半就可以了,求ABEFHG这部分的体积为两个部

分组成，上面一个小正四面体，和下面一个棱台，棱台体积用公式为1/3 *(s1+s2+sqrt(s1*s2))*h(棱台高)，均可以用未知数表示出来，然后在化简得到这样一个
方程:x^2+(r-a)x+r^3/(2a)-2*r^2+a*r=0 这样只要解这个方程就可以了，还要注意的是，求出来的解必须要满足0=< x <=r,否则和无解一样输出Oh, my god!
*/ 

#include<stdio.h>
#include<math.h>
int main()
{
	double r,a,b,c,t;
	double x1,x2;
	while(scanf("%lf%lf",&r,&a)!=EOF)
	{
		t=-1.0;
		b=r-a;
		c=r*r*r/a/2-2*r*r+a*r;
		if(b*b-4*c<0)
		{
			printf("Oh, my god!/n");
			continue;
		}
		x1=(-b+sqrt(b*b-4*c))/2;
		x2=(-b-sqrt(b*b-4*c))/2;
		if(x1>=0&&x1<=r)
			t=x1;
		else if(x2>=0&&x2<=r)
			t=x2;
		if(t>=0&&t<=r)
		        printf("%.2lf/n",t);
		else
			printf("Oh, my god!/n");
	}
	return 0;
}