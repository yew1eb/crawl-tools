#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
}aa[51];
int n;
double dis(point a,point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            scanf("%lf%lf",&aa[i].x,&aa[i].y);
        double ans = 0;
        for(int i = 0; i < n - 2; i++)
        {
            for(int j = i + 1; j < n - 1; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    double a = dis(aa[i],aa[j]);
                    double b = dis(aa[j],aa[k]);
                    double c = dis(aa[k],aa[i]);
                    double p = (a + b + c) / 2;
                    ans = max(ans,sqrt(p * (p - a) * (p - b) * (p - c)));//æµ·ä¼¦å¬å¼
                }
            }
        }
        printf("%.1f\n",ans);
    }
    return 0;
}