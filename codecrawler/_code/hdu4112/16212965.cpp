#include<stdio.h>
#include<math.h>

int main()
{
    __int64 n,m,k,ans1,ans2,t,T;
    scanf("%I64d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        ans1=n*m*k-1;
        ans2=(__int64)(ceil(log(n*1.0)/log(2.0))+ceil(log(m*1.0)/log(2.0))+ceil(log(k*1.0)/log(2.0)));
        printf("Case #%I64d: %I64d %I64d\n",t,ans1,ans2);
    }
    return 0;
}