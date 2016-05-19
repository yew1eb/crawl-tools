#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double C(int m, int n)
{
	double ans =1.0;
	for(int i=1; i<=n; i++)
	{
		if(i<=m) ans/=1.0*i;
		else if(i>=n-m) ans*=i;
	}
	return ans;
}
int main()
{
	
	int h1,h2,a1,a2;
	while(cin>>h1>>h2>>a1>>a2)
	{
		double ans = 0.0;
	
		int a = h1/a2+!!(h1%a2);
		int b = h2/a1+!!(h2%a1);
		double w1, w2;
		ans = pow(0.5,b);
		double tmp=0.0;
		for(int i=1; i<a; i++)
		{
			tmp += log10((b-1+i)*1.0)-log10(1.0*i);
			ans +=  pow(10,tmp+(b+i)*log10(0.5));
		}
		printf("%.4lf\n", 100.0*ans);
	}
	return 0;
}