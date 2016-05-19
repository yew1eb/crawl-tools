#include<stdio.h>

int Gcd(int m, int n)
{
    return m == 0 ? n : Gcd(n % m, m);
}

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        printf("%d\n", m + n - Gcd(m, n));
    }
    return 0;
}