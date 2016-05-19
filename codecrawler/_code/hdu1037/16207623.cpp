#include <stdio.h>

int main()
{
    int A[3], i, ok;
    while (scanf("%d%d%d", &A[0], &A[1], &A[2]) != EOF)
    {
        ok = 1;
        for (i=0; i<3; i++)
        {
            if (A[i] <= 168)
            {
                printf("CRASH %d\n", A[i]);
                ok = 0;
                break;
            }
        }
        if (ok)
            printf("NO CRASH\n");
    }
    return 0;
}