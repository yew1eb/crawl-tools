#include <stdio.h>
__int64 f[51];
int main()
{
    int n, i;
    f[1] = 1; f[2] = 2;
    for(i=3;i<=50; i++) f[i] = f[i-1] + f[i-2];
    while(~scanf("%d",&n))
        printf("%I64d\n",f[n]);
    return 0;
}
