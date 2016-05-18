#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<string>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
const int inf=1<<29;
const int M=50200;
const double eps=1e-8;
struct point
{
    double x,y;
}po[5],p,g;
int n;

int main()
{
    int T;
    while(scanf("%d",&T)==1)
    {
        if(!T) break;
        while(T--)
        {
            for(int i=0;i<3;i++)
                scanf("%lf%lf",&po[i].x,&po[i].y);
            double tp,area=0,tpx=0,tpy=0;
            p.x=po[0].x;
            p.y=po[0].y;
            for(int i=1;i<=3;i++)
            {
                g.x=po[(i==3)?0:i].x;
                g.y=po[(i==3)?0:i].y;
                tp=(p.x*g.y-p.y*g.x);
                area+=tp/2;
                tpx=tpx+(p.x+g.x)*tp;
                tpy=tpy+(p.y+g.y)*tp;
                p.x=g.x;
                p.y=g.y;
            }
            g.x=tpx/(6*area);
            g.y=tpy/(6*area);
            printf("%.1lf %.1lf\n",g.x,g.y);
        }
    }
    return 0;
}