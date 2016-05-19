#include <stdio.h>
#include <string.h>

int A[1000000];

int main()
{
    int n, m, i, ok;
    while (scanf("%d", &n) != EOF)
    {
        memset(A, 0, sizeof(A));
        for (i=0; i<n; i++)
        {
            scanf("%d", &m);
            A[m]++;
            if (A[m] == (n+1)/2)
                ok = m;
        }
        printf("%d\n", ok);
    }
    return 0;
}