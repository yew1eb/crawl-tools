#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for(int i = 0; i < n; i ++)
using namespace std;
const int N = 400100;
bool isp[N];
vector<int> p;
vector<LL> hav;

void get_P()
{
    CLR(isp, true);p.clear();
    for(int i = 2; i < N; i ++)
    {
        if(isp[i])
        {
            p.push_back(i);
            if(i < 1111) for(int j = i * i; j < N; j += i)
            {
                isp[j] = false;
            }
        }
    }
}

LL Euler_phi(LL n)
{
    LL ret = n;
    for(int i = 0; (LL)p[i] * p[i] <= n; i ++) if(n % (LL)p[i] == 0)
    {
        ret = ret / p[i] * (p[i] - 1);
        while(n % p[i] == 0) n /= p[i];
    }
    if(n > 1) ret = ret / n * (n - 1);
    return ret;
}

LL Mul(LL a, LL b, LL mod)
{
    LL ret = 0;
    while(b)
    {
        if(b & 1)
            ret = (ret + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return ret;
}

LL Pow(LL a, LL b, LL mod)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = Mul(ret, a, mod);
        a = Mul(a, a, mod);
        b >>= 1;
    }
    return ret;
}

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

void get_hav(LL n)
{
    hav.clear();
    for(int i = 0; i < p.size() && n > 1; i ++)
    {
        while(n % (LL)p[i] == 0)
        {
            n /= p[i];
            hav.push_back(p[i]);
        }
    }
    if(n > 1) hav.push_back(n);
}

int main()
{
    int cas = 1;
    LL L, ans, m, x;get_P();
    while(scanf("%I64d", &L), L)
    {
        m = 9 * L / gcd(L, 8LL);
        if(gcd(m, 10LL) != 1)
        {
            printf("Case %d: 0\n", cas ++);
            continue;
        }
        x = Euler_phi(m);
        get_hav(x);
        for(int i = 0; i < hav.size(); i ++)
        {
            if(Pow(10LL, x / hav[i], m) == 1)
                x /= hav[i];
        }
        printf("Case %d: %I64d\n", cas ++, x);
    }
}
