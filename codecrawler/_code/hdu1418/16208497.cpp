#include<stdio.h>
int main()
{
    __int64 m, n;
    while(~scanf("%I64d%I64d",&n,&m) && (n+m))
    {
        printf("%I64d\n",n+m-2);
    }
    return 0;
}