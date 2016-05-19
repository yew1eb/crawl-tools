#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

struct Point
{
    double x;
    double y;
};
Point p[100000];

double cross(Point O,Point A,Point B)
{
    return (A.x - O.x) *  (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n;
    double vol;
    while(scanf(" %d",&n)!=EOF && n>=3)
    {
        p[0].x = p[0].y = 0;
        for(int i=1;i<=n;i++)
        {
            scanf(" %lf %lf",&p[i].x,&p[i].y);
        }
        scanf(" %lf",&vol);
        p[n+1].x = p[1].x;
        p[n+1].y = p[1].y;
        double area = 0;
        for(int i=1;i<=n;i++)
        {
            area += cross(p[0],p[i],p[i+1]);
        }
        area = -area;
        area /=2;
        double len;
        len = vol/area;
        printf("BAR LENGTH: %.2lf\n",len);
    }
}