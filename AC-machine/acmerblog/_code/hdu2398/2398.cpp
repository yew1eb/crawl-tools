/*
hdu	2398 Savings Account - 数学
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x,y,a,l;
	int ret;
	while(cin>>x>>l>>y)
	{
		l=1+l/100;
		a=log(y/x)/log(l);//l^a=y/x
		ret=ceil(a);//向上取整  floor是向下
		cout<<ret<<endl;
	}
	return 0;
}