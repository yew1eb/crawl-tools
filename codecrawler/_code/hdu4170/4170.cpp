#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define eps 1e-8
int n;
double sx,sy,v;
struct node
{
    double x,y;
   double vx,vy;
} a[10],pa[10];
int p[10];
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void solve(int g)
{
    double mmin=-1,ans,gx,gy;
    do
    {
        gx=sx;
        gy=sy;
        ans=0;
        for(int i=0;i<n;i++)
        a[i]=pa[