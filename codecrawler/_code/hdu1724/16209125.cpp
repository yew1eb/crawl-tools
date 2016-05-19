#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,l,r;
double f(double x)
{
    double t=asin(x/a);
    return 0.5*a*b*(t+0.5*sin(2*t));
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>l>>r;
        printf("%.3lf\n",2*(f(r)-f(l)));
    }
    return 0;
}