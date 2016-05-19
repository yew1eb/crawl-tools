#include <stdio.h>

int main()
{
    __int64 a[505];
    int i;
    int k;
    a[1] = 1;
    for(i = 2;i<=500;i++)
    {
        a[i] = a[i-1]+i*(i+1)/2;
        k = i-1;
        while(k>0)
        {
            a[i]+=k;
            k-=2;
        }
    }
    while(~scanf("%d",&k))
    {
        printf("%I64d\n",a[k]);
    }

    return 0;
}
