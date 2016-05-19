#include <stdio.h>
#define N 30
__int64 c[N][N];///ç»åæ°
int main()
{
    int i,j,k;
    for(i = 0; i < N; ++i)
        c[i][0] = c[i][i] =1;
    for(i = 1; i < N; ++i)
        for(j = 1; j < i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    __int64 sum[N] = {0};
    int t;
    for(t = 1; t < N; ++t)
        for(i = 0; i <= t; ++i)
            for(j = 0;j<= t - i; ++j)
                sum[t] += c[t][i] * c[t-i][j];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        printf("%I64d\n",sum[i]);
    }
    return 0;
}
