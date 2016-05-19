#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
#define MOD 200907

__int64 quickmod(__int64 a,__int64 b,__int64 n)
{
    __int64 ret=1;
    for (; b; b>>=1,a=(__int64)(((__int64)a)*a%n))
        if (b&1)
            ret=(__int64)(((__int64)ret)*a%n);
    return ret;
}


int main()
{
    double a,b,c;
    int T;
    int k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%d",&a,&b,&c,&k);
        if(a+c==2*b)
        {
            __int64 a1=(__int64 )a;
            __int64 d=(__int64 )(b-a);
            int ans=(a1%MOD+((k-1)%MOD)*(d%MOD))%MOD;
            printf("%d\n",ans);
        }
        else
        {
            __int64 a1=(__int64)a;
            __int64 t1=(__int64)(a1%MOD);
            double q1=(b/a);
            __int64 q2=(__int64)q1;
            __int64 q=(__int64)(q2%MOD);
            __int64 tmp=quickmod(q,k-1,MOD);
            int ans=(t1*tmp)%MOD;


            printf("%d\n",ans);
        }
    }
    return 0;
}
