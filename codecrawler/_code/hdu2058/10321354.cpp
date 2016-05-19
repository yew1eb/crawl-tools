#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    __int64 n, m, k, a;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        if(n==0 && m==0) break;
        for(k=(int)sqrt(2*m); k >0; k--)
        {
            a = m/k - (k-1)/2;
            if( (2*a-1+k)*k == 2*m && a +k-1 <=n)
            {
                printf("[%I64d,%I64d]\n",a, k+a-1);
            }
        }
        printf("\n");
    }
    return 0;
}
