#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
double a[10005];
int n,m;

int check(double mid)
{
    int i;
    int sum = 0;
    for(i = 0; i<n; i++)
    {
        sum+=int(a[i]/mid);
        if(sum>=m)
            return 1;
    }
    return 0;
}

int cmp(double a,double b)
{
    return a>b;
}

int main()
{
    int t,i,j;
    double l,r,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        m++;
        for(i = 0; i<n; i++)
        {
            scanf("%lf",&a[i]);
            a[i] = a[i]*a[i]*pi;
        }
        sort(a,a+n,cmp);
        l = 0;
        r = a[0];
        if(m<n)
            n = m;
        while(r-l>1e-5)
        {
            mid = (r+l)/2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.4lf\n",l);
    }

    return 0;
}
