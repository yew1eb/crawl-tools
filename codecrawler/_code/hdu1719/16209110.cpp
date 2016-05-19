#include <stdio.h>

int main()
{
    __int64 n;
    while(~scanf("%I64d",&n))
    {
        if(!n)
        {
            printf("NO!\n");
            continue;
        }
        n++;
        while(n%2==0)
            n/=2;
        while(n%3 == 0)
            n/=3;
        if(n==1)
            printf("YES!\n");
        else
            printf("NO!\n");
    }

    return 0;
}
