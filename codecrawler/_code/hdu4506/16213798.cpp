#include <iostream>
using namespace std;

const __int64 tmp = 1000000007;
const int maxn = 10005;
__int64 n, t, k, a[maxn];

__int64 qpow(int a, int b)
{
    __int64 c, d;
    c = 1; d = a;
    while (b > 0)
    {
        if (b & 1)
        c *= d;
        c %= tmp;
        b = b >> 1;
        d = (d * d) % tmp;
    }
    return c % tmp;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d %I64d %I64d", &n, &t, &k);
        int i;
        __int64 multi = qpow(k,t);
        for (i=0; i<n; i++)
        {
            scanf("%I64d", &a[i]);
            a[i] = a[i] * multi % tmp;
        }
        t %= n;
        printf("%d", a[(n+0-t)%n]);
        for (i=1; i<n; i++)
        {
            printf(" %d", a[(n+i-t)%n]);
        }
        puts("");
    }
    return 0;
}

