/*
cosA=(b²+c²-a²)/(2bc)
cosB=(a²+c²-b²)/(2ac)
cosC=(a²+b²-c²)/(2ab)

V=1/6*abc(sin^2α+sin^2β+sin^2γ+2cosαcosβcosγ-2)^(1/2);
*/
#include<iostream>
#include<cmath>
using namespace std;
double S(double a, double  b, double c)
{
	double P=(a+b+c)*1.0/2.0;
	return sqrt(P*(P-a)*(P-b)*(P-c));
}
int main()
{
	double a,b,c,_a,_b,_c;
	while(cin>>a>>b>>c>>_c>>_b>>_a)
	{
		double sina = _a/(2.0*_a*b*c/(4.0*S(_a,b,c)));
		double sinb = _b/(2.0*a*_b*c/(4.0*S(a,_b,c)));
		double sinc = _c/(2.0*a*b*_c/(4.0*S(a,b,_c)));
		double cosa = (b*b+c*c-_a*_a)*1.0/(2*b*c);
		double cosb = (a*a+c*c-_b*_b)*1.0/(2*a*c);
		double cosc = (a*a+b*b-_c*_c)*1.0/(2*a*b);
		double V = 1.0/6.0*a*b*c*sqrt(pow(sina,2)+pow(sinb,2)+pow(sinc,2)+2.0*cosa*cosb*cosc-2.0);
		printf("%.4lf\n",V);
	}
	return 0;
}