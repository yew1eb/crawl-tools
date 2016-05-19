#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int ncase;
    __int64 n, ans;
    long double t;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%I64d", &n);
        t = n * log10(n+0.0);
        t -= (__int64)t;
        ans = pow((long double)10, t);
        printf("%I64d\n", ans);
    }
    return 0;
}