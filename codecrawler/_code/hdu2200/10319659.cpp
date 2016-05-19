#include <iostream>
#include <cstdio>
using namespace std;
double f(double x)
{
    double s=1;
    for(int i=2;i<=x;i++)
        s*=i;
    return s;
}
int main()
{
    int n;
    while((scanf("%d",&n))>0)
    {
        double s=0;
        for(int i=2;i<=n;i++)
            s+=f(n)/(f(i)*f(n-i))*(i-1);
        printf("%.lf\n",s);
    }
    return 0;
}