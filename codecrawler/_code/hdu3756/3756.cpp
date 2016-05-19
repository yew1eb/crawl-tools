#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
#define N 10011
int n;
struct A
{
	double x,y,z;
	double r;
}E[N];
double cal(double R)
{
	int i;
	double temp,h=0;
	for(i=0;i<n;i++)					//没想到暴力能过，那么，有某有什么方法可以不用暴力的呢？
	{
		temp=E[i].z*R/(R-E[i].r);
		if(temp>h)	h=temp;
	}
	return h;
}
int main()
{
	int T;
	int i;
	double low,up,midl,midr,maxr,ansl,ansr;
	double temp1,temp2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		maxr=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&E[i].x,&E[i].y,&E[i].z);
			E[i].r=sqrt(E[i].x*E[i].x+E[i].y*E[i].y);
			if(E[i].r>maxr)	maxr=E[i].r;
		}
		low=maxr;up=3*maxr;
		while(up-low>1e-5)
		{
			midl=(up+2*low)/3;
			midr=(low+2*up)/3;
			temp1=cal(midl);
			temp2=cal(midr);
			ansl=temp1*midl*midl;
			ansr=temp2*midr*midr;
			if(ansl>ansr)	low=midl;
			else			up=midr;
		}
		printf("%.3lf %.3lf\n",temp1,up);
	}
	return 0;
}