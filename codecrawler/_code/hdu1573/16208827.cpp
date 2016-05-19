#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

typedef __int64 LL;

const int MAXN = 110;

LL n;

int m;

LL lcm;

LL A[MAXN], R[MAXN];

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a%b);
}

void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if(!b) { d = a; x = 1; y = 0;}
    else { ex_gcd(b, a%b, d, y, x); y -= x*(a/b);}
}

void read_case()
{
    lcm = 1;
    scanf("%I64d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%I64d", &A[i]);
        lcm = lcm / gcd(lcm, A[i]) * A[i];
    }
    for(int i = 1; i <= m; i++) scanf("%I64d", &R[i]);
}

void solve()
{
    read_case();
    LL a, b, c, d, x, y;
    for(int i = 2; i <= m; i++)
    {
        a = A[1], b = A[i], c = R[i]-R[1];
        ex_gcd(a, b, d, x, y);
        if(c % d) { printf("0\n"); return ;}
        x *= c / d;
        LL b1 = b / d;
        x = (x%b1 + b1) % b1;
        R[1] = A[1]*x + R[1];
        A[1] = A[1] / d * A[i];
    }
    LL ans = 0;
    if(R[1] <= n) ans = 1 + (n-R[1]) / lcm;
    if(ans && R[1] == 0) ans--; //ç¹å¤ç»æä¸ºR[1]ä¸º0æ¶ï¼åºè¯¥æ¯x-1. 
    printf("%I64d\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        solve();
    }
    return 0;
}
