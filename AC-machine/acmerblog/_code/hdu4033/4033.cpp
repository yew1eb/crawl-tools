#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const double PI=acos(0.0)*2;
int n;
double b[105];
double angle(double a,double b,double c)
{
	return acos((a*a+b*b-c*c)/2/a/b);
}
int OK(double mid)
{
	double ans=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]+b[(i+1)%n]<=mid)
			return -1;
		if(fabs(b[i]-b[(i+1)%n])>=mid)
			return 0;
		ans+=angle(b[i],b[(i+1)%n],mid);
	}
	if(fabs(ans-2*PI)<0.000001)return 1;
	else
		if(ans-2*PI>0)return -1;
		else
			return 0;
}
int main()
{
	int T,t,flag;
	scanf("%d",&T);
	for( t=1;t<=T;t++)
	{
		flag=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&b[i]);
		}
		double r=20000,l=0,mid;
		printf("Case %d: ",t);
		while(r-l>0.000001)
		{
			mid=(l+r)/2;
			int kk=OK(mid);
			if(kk==1)
			{
				printf("%.3f\n",mid);
				flag=1;
				break;
			}
			else
				if(kk==0)
				   l=mid;
				else
					r=mid;
		}
		if(flag==0)printf("impossible\n");
	}
	return 0;
}
