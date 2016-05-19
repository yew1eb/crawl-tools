#include <stdio.h>

int main()
{
    __int64 a,b,cas=1,i,j;
    while(~scanf("%I64d%I64d",&a,&b),a+b)
    {
        i=2;
        while(i<=b)
        {
            if(a%i)
            {
                j=a/i+1;
                if(j<=i)
                {
                    a=j*b;
                    break;
                }
                a=i*j;
            }
            else
            {
                j=a/i;
                if(j<=i)
                {
                    a=j*b;
                    break;
                }
            }
            i++;
        }
        printf("Case #%I64d: %I64d\n",cas++,a);
    }
    return 0;
}
