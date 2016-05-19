#include <stdio.h>
#include <math.h>
__int64 f[51];

int main()
{
    int n, a, b, i;
    f[0] = 1; f[1] = 1;
    for(i=2;i<=50; i++) f[i] = f[i-1] + f[i-2];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        printf("%I64d\n",f[b-a]);
    }
    return 0;
}
