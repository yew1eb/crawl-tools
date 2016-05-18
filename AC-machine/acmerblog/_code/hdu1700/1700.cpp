#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

typedef long long LL;
const int N=21;
const LL II=1000000007;

double x,y,r,r2;
double xx0,yy0,xx1,yy1;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%lf%lf",&x,&y);
        r2=(x*x+y*y);
        double a,b,c;
        a=r2;
        b=r2*y;
        c=r2*r2/4-x*x*r2;
        yy0=(-b-sqrt(b*b-4*a*c))/2/a;
        yy1=(-b+sqrt(b*b-4*a*c))/2/a;
        /*/这个地方求解x不能用x*x+y*y=r2来算，应为不知道正负号
        xx0=sqrt(r2-yy0*yy0);
        xx1=sqrt(r2-yy1*yy1);*/
        if(fabs(x-0)<1e-7)
        {
            xx0=-sqrt(r2-yy0*yy0);
            xx1=sqrt(r2-yy1*yy1);
        }
        else
        {
            xx0=(-r2/2-yy0*y)/x;
            xx1=(-r2/2-yy1*y)/x;
        }
        printf("%.3lf %.3lf %.3lf %.3lf\n",xx0,yy0,xx1,yy1);
    }

    return 0;
}