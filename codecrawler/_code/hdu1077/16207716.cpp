#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const static double  eps = 1e-6;

struct Point
{
    double x,y;
};
double distancess(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
Point look_center(Point a,Point b)
{
    Point aa,bb,mid;
    aa.x = b.x-a.x;
    aa.y = b.y-a.y;
    mid.x = (a.x+b.x)/2.0;
    mid.y = (a.y+b.y)/2.0;
    double dist = distancess(a,mid);
    double c = sqrt(1.0-dist);
    if(fabs(aa.y)<eps)
    {
        bb.x = mid.x;
        bb.y = mid.y+c;
    }

    else
    {
        double ang = atan(-aa.x/aa.y);
        bb.x = mid.x + c*cos(ang);
        bb.y = mid.y + c*sin(ang);
    }
    return bb;
}
int main()
{
    int test;
    Point p[305],a,b,c;
    int n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i=0; i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);

        int ans = 1;
        int temp = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1;j<n;j++)
            {

                if(distancess(p[i],p[j])>4) continue;
                a = look_center(p[i],p[j]);
                temp = 0;
                for(int k=0;k<n;k++)
                {
                    if(distancess(a,p[k])<=1.000001) temp++;
                }
                if(ans<temp) ans = temp;
            }
            printf("%d\n",ans);
    }
    return 0;

}
