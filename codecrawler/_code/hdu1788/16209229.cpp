#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

typedef __int64 LL; //long long WA

const int MAXN = 110;

int n;
LL lcm, a;

LL gcd(LL a, LL b)
{
    return b == 0 ? a:gcd(b, a%b);
}

int read_case()
{
    scanf("%d%I64d", &n, &a);
    if(!n && !a) return 0;
    lcm = 1;
    for(int i = 1; i <= n; i++)
    {
        LL m;
        scanf("%I64d", &m);
        lcm = lcm / gcd(lcm, m) * m;
    }
    return 1;
}

void solve()
{
    LL ans = lcm-a;
    printf("%I64d\n", ans);
}

int main()
{
    while(read_case())
    {
        solve();
    }
    return 0;
}
