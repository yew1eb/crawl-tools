#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double a, b, c, d, e, EPS = 1e-8;
int sign(double x)
{
	return x < -EPS ? -1 : (x > EPS ? 1 : 0);
}
bool top(double x)
{
    double co = x / a;
    double si = sqrt(1 - co * co);
    double h = co * b + sqrt(a * a - x * x);
    return sign(h - d) <= 0;
}
bool right(double x)
{
    double co = x / a;
    double si = sqrt(1 - co * co);
    double r = b * si + x;
    return sign(r - e) <= 0;
}

bool check()
{
	double l = 0, r = a;
    if (sign(a - e) > 0) return false;
	for (int i = 0; i < 200; ++i)
	{
		double mid = (l + r) / 2;
       // cout << mid << endl;
        if (!top(mid)) r = mid;
        else if (!right(mid)) l = mid;
        else return true;
	}
	return false;
}
int main()
{
	while (cin >> a >> b >> c >> d >> e)
	{
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (d > e) swap(d, e);
       // cout << a << " "<<b << " " <<d << " " << e << endl;
		puts(check() ? "YES" : "NO");	 
	}
	return 0;
}