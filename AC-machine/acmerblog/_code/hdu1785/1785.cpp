#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 120
using namespace std;

struct node
{
    double x,y,k;
}s[maxn];
bool cmp(node a,node b)
{
     return a.k<b.k;
}
int main()
{
    int n,i;
    while(scanf("%d",&n)&&n>=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&s[i].x,&s[i].y);
            double z = sqrt(pow(s[i].x,2) + pow(s[i].y,2)) ;
            s[i].k = acos(s[i].x/z) ;
        }
        sort(s,s+n,cmp);
        for(i=0;i<n;i++)
            printf("%.1lf %.1lf%c",s[i].x,s[i].y,i==n-1?'\n':' ');
    }
    return 0;
}