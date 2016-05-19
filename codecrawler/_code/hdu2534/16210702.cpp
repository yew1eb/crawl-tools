#include<cstdio>
__int64 gcd(__int64 a, __int64 b)
{
    if (b == 0) return a;
    gcd(b, a%b);
}

int main(void)
{
    __int64 a;
    __int64 b;
    while (scanf("%I64d%I64d", &a, &b), (a||b))
    {
        if (gcd(a, b) == 1)
        {
            printf("%I64d\n", a*b-a-b);
        }
        else
        {
            printf("Inf\n");
        }
    }
    return 0;
}