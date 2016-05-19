#include <cstdio>
#include <cstring>
#include <cmath>
int main()
{
    int t;
    int x, b;
    int cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&b);
        double p = 1-pow(1-1.0/x,b);
        double n = x*(x+1.0)/2;
        double ans = n*p;
        printf("Case #%d: %.3lf\n",++cas,ans);
    }
}