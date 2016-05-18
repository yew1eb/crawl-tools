#include <stdio.h>

int main()
{
    int a, b, i, j;
    long long sum, pro;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        sum = 0,pro = 1;
        if ( (a == 0) && (b==0) )
            break;
        for (i = a; i <= b; i++)
        {
            for (j = 1; j <= i; j++)
            {
                pro *= j;
            }
            sum += pro;
            pro = 1;
        }
        printf("%lld\n", sum);
    }

    return 0;
}