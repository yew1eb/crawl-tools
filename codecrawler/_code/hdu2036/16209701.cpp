#include<iostream>
using namespace std;
struct point
{
    double x,y;
} P[101];

double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}

double area(int n)
{
    double tmp=0;
    
    for(int i=0;i<n;i++)
    {
        tmp+=cross(P[i],P[i+1]);
    }
    return tmp/2.00;
}

int main()
{
    int i,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        P[n].x=P[0].x;P[n].y=P[0].y;
    //    for(i=0;i<n;i++)
    //        printf("P%d\t%.1lf %.1lf\n",i+1,P[i].x,P[i].y);
        printf("%.1lf\n",area(n));
    }
    return 0;
}
