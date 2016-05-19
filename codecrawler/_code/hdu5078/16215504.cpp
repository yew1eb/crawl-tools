#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
double a[10000];
double b[10000];
int ti[10000];
double dis(int i,int j)
{
    return sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double ans=0;

        for(int i=0;i<n;i++)
        {
            scanf("%d%lf%lf",&ti[i],&a[i],&b[i]);
        }
        for(int i=1;i<n;i++)
        {
            ans=max(ans,(dis(i-1,i)/(ti[i]-ti[i-1])));
        }
        printf("%.10f\n",ans);
    }
    return 0;
}
