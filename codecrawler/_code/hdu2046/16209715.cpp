#include <stdio.h>

__int64 A[51][30], B[51];

int main()
{
    int n, i, j;
    for (i=0; i<=50; i++)
        A[i][0] = 1;
    for (i=2; i<=50; i++)
    {
        for (j=1; j<i/2+1; j++)
            A[i][j] = A[i-2][j-1] + A[i-1][j];
    }
    for (i=1; i<=50; i++)
    {
        for (j=0; j<30; j++)
            B[i] += A[i][j];
    }
    while (scanf("%d", &n) != EOF)
        printf("%I64d\n", B[n]);
    return 0;
}
