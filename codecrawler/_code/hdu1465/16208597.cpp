#include <stdio.h>
int main()
{
    int n,i;
    __int64 a[21];
    a[1]=0;
    a[2]=1;
    for(i=3;i<21;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    while( scanf("%d",&n) != EOF)
    printf("%I64d\n",a[n]);
    return 0;
}