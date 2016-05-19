#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

double calv(double a,double b,double c,double l,double m,double n)
{
    return sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12;
}

int main()
{
    double a,b,c,l,m,n;
    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&l,&n,&m) != EOF)
    {
        printf("%.4lf\n",calv(a,b,c,l,m,n));
    }
    return 0;
}