#include <stdio.h>
#include <math.h>

int main()
{
    long long n,gn,dig;

    while (scanf("%lld", &n) == 1)
    {
        if (n == 0)
            printf("%d\n", 0);
        else
        {
            /*gn = pow(2, n)+pow(-1, n+1);*/
            dig = ceil(n*log10(2));
            printf("%lld\n", dig);
        }
    }

    return 0;
}