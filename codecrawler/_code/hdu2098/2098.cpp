#include <stdio.h>
#include <math.h>

int IsPrime(int n)
{
    int i;
    for (i=2; i<=sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, i, cnt;
    while (scanf("%d", &n) && n)
    {
        cnt = 0;
        for (i=3; i<n/2; i+=2)
        {//因为是不同的两个素数，那必定一个比n/2大，一个比n/2小
            if (IsPrime(i) && IsPrime(n-i))
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}