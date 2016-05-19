#include <stdio.h>

int main()
{
    __int64 a[21];
    int i, n;
    a[2]= 1; a[3] = 2;
    for(i=4; i<=20; i++) a[i] =(i-1)*(a[i-1]+a[i-2]);
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",a[n]);
    }
    return 0;
}
