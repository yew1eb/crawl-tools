#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps = 1e-12;
struct Node
{
    double x;
    double w;
}node[50010];
int n;
double calc(double xx)
{
    double res=0;
    for(int i=1;i<=n;i++)
    {
        double d=xx-node[i].x;
        if(d<0) d*=-1;
        res+=d*d*d*node[i].w;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    int count=1;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%lf%lf",&node[i].x,&node[i].w);
        double l=node[1].x;
        double r=node[n].x;
        double mid,midmid;
        double mid_area;
        double midmid_area;
        while(l+eps<r)
        {
            mid=(l+r)/2;
            midmid=(mid+r)/2;
            mid_area=calc(mid);
            midmid_area=calc(midmid);
            if(mid_area<midmid_area)
            r=midmid;
            else
            l=mid;
        }
        double g=calc(l);
        double h=calc(r);
        if(g<h)
        printf("Case #%d: %.0lf\n",count++,g);
        else
        printf("Case #%d: %.0lf\n",count++,h);
    }
    return 0;
}
