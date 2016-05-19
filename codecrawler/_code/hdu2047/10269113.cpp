#include <stdio.h>
#include <string.h>

int main()
{
    long long f[50][2];
    int i, n;
    f[1][0] = 1; f[1][1] = 2;
    for(i=2; i<=40; ++i)
    {
        f[i][0] = f[i-1][1];
        f[i][1] = 2*(f[i-1][0] + f[i-1][1]);
    }
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",f[n][0] + f[n][1]);
    }
    return 0;
}
