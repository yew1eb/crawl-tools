#include <cstdio>
#include <cstring>
#include <cmath>

int main ()
{
    int T;
    scanf("%d",&T);
    double v1,v2,R,D;
    while (T--)
    {
        scanf("%lf%lf%lf%lf",&v1,&v2,&R,&D);
        double ans=R/v1*(asin(v1/v2));
        if (ans*v2>D)
            printf("Why give up treatment\n");
        else
            printf("Wake up to code\n");
    }
    return 0;
}
