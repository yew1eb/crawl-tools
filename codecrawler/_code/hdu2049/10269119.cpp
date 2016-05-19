#include <stdio.h>
#include <string.h>

int main()
{
    int T, i, j, n, m;
    long long c[30][30], f[30];
    memset(c, 0, sizeof c );
    for(i=0; i<=20; ++i)
    {
        c[i][0] = 1;
        for(j=1; j<=i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    f[1] = 0; f[2] = 1;
    for(i=3; i<=20; ++i)
        f[i] = (i-1) * (f[i-1] + f[i-2]);

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%I64d\n",c[n][n-m]*f[m]);
    }
    return 0;
}
