/*
T
dist
ax bx
ay by
追及问题:(ay-ax)/2*m^2 + (by-bx)*m - dist = 0 判断是否有解
*/

#include <iostream>
#include <math.h>
using namespace std;

const double esp = 0.0000000000001;
bool isExistSolution;
double ans1,ans2;

void solve_equation(double a,double b,double c) //ax^2+bx+c=0
{
	if (fabs(a) < esp)
	{
		if (fabs(b) > 0)
		{
			isExistSolution = true;
			ans1 = ans2 = -c / b;		// 分母不能为0!!
		}
		else
			isExistSolution = false;
		return;
	}
	double deltar = b*b - 4.0*a*c;
	if (deltar < 0)
		isExistSolution = false;
	else
	{
		isExistSolution = true;
		deltar = sqrt(deltar)/(2.0*a);
		b = (-b)/(2.0*a);
		ans1 = b + deltar;
		ans2 = b - deltar;
	}
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("2.txt","r",stdin);
#endif

	int T;
	double dist, ax, bx, ay, by;
	cin >> T;
	while (T--)
	{
		cin >> dist >> ax >> bx >> ay >> by;
		solve_equation(0.5*(ay-ax),by-bx,-dist);
		if (!isExistSolution)
			puts("Good driver,Jiaoshou!");
		else
		{
			if (ans1 > 0)
				printf("Oh,God!Jiaoshou will be catched after %.3lf minutes.\n",ans1);
			else if (ans2 > 0)
				printf("Oh,God!Jiaoshou will be catched after %.3lf minutes.\n",ans2);
			else
				puts("Good driver,Jiaoshou!");
		}
	}
	return 0;
}