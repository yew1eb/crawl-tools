/*
hdu 1724 Ellipse simpson积分

求椭圆的部分面积
simpson积分法 http://zh.wikipedia.org/zh-tw/%E8%BE%9B%E6%99%AE%E6%A3%AE%E7%A7%AF%E5%88%86%E6%B3%95
*/
#include<stdio.h>
#include<math.h>
const double eps=1e-8;
inline double jue(double a)
{
	return a>0?a:-a;
}
int dbcmp(double a)
{
	if(a>eps)return 1;
	if(a<(-eps)) return -1;
	return 0;
}
template<typename T>
inline T sqr(T d){return d*d;}
double a,b;
inline double func(double x)
{
	return 2*b*sqrt(1-sqr(x)/sqr(a));
}
double simpson(double l,double r)
{
	return (func(l)+func(r)+4*func((l+r)/2))/6*(r-l);
}
double work(double l,double r)
{
	double mid=(l+r)/2;
	double ans=simpson(l,r);
	if(dbcmp(ans-simpson(l,mid)-simpson(mid,r))==0)
	{
		return ans;
	}else
	{
		return work(l,mid)+work(mid,r);
	}
}
int main()
{
	int n;
	double l,r;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
		double ret=work(l,r);
		printf("%.3f\n",ret);
	}
	return 0;
}