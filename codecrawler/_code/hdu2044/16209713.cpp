#include <stdio.h>

__int64 A[51];

int main()
{
    int n, a, b;
    int i;
    A[1] = 1;
    A[2] = 2;
    for (i=3; i<51; i++)
        A[i] = A[i-1] + A[i-2];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        printf("%I64d\n", A[b - a]);
    }
    return 0;
}