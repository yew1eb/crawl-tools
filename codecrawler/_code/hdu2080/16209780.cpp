#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define PI 3.141592653
int main()
{
    double x1,y1,x2,y2,a1,a2,a3;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        a1=atan2(y1,x1);
        a2=atan2(y2,x2);
        a3=fabs(a1-a2);
        printf("%.2lf\n",a3*180/PI);
    }
    return 0;
}
