//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define LL int
#define MP make_pair
#define xx first
#define yy second
#define INF 1200000000000000000ll
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1|1
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100100;

const int N = 1 << 19;
const int P = 998244353;
const int G = 3;
const int NUM = 20;

LL  wn[NUM];

LL quick_mod(LL a, LL b, LL mod)
{
    LL ans = 1; a %= mod;
    while(b)
    {
        if(b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}

void GetWn()
{
    for(int i=0; i<NUM; i++)
    {
        int t = 1 << i;
        wn[i] = quick_mod(G, (P - 1) / t, P);
    }
}

void Rader(LL a[], int len)
{
    int j = len >> 1;
    for(int i = 1; i < len - 1; i ++)
    {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void NTT(LL a[], int len, int on)
{
    Rader(a, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1)
    {
        id++;
        for(int j = 0; j < len; j += h)
        {
            LL w = 1;
            for(int k = j; k < j + h / 2; k++)
            {
                LL u = a[k];
                LL t = 1ll * w * (a[k + h / 2]) % P;
                a[k] = (u + t) % P;
                a[k + h / 2] = (u - t + P) % P;
                w = 1ll * w * wn[id] % P;
            }
        }
    }
    if(on == -1)
    {
        for(int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        LL Inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            a[i] = 1ll * a[i] * Inv % P;
    }
}

void Conv(LL a[], LL b[], int n)
{
    NTT(a, n, 1);
    NTT(b, n, 1);
    for(int i = 0; i < n; i++)
        a[i] = 1ll * a[i] * b[i] % P;
    NTT(a, n, -1);
}

LL dp[maxn];
LL fac[maxn], Invfac[maxn];
LL a[N], b[N];

void divide(int l, int r)
{
    if(l == r) return ;
    int len = 1, m = (l + r) >> 1;
    divide(l, m);
    while(len <= (r - l + 1)) len <<= 1;
    for(int i = 0;i < len; i++) {
        a[i] = b[i] = 0;
        b[i] = 1ll*i*i%P;
    }
    for(int i = l;i <= m; i++) {
        a[i-l+1] = 1ll*dp[i]*Invfac[i]%P;
    }
    Conv(a, b, len);
    for(int i = m + 1; i <= r; i ++)
        dp[i] = (dp[i] + 1ll * fac[i - 1] * a[i - l + 1] % P) % P;
    divide(m + 1, r);
}

void init()
{
    GetWn();
    fac[0] = Invfac[0] = 1;
    for(int i = 1; i <= 100000; i ++)
    {
        fac[i] = 1ll * fac[i - 1] * i % P;
        Invfac[i] = quick_mod(fac[i], P - 2, P);
    }
    CLR(dp, 0);
    dp[0] = 1;
    divide(0, 100000);
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n) != EOF) printf("%d\n", dp[n]);
}
