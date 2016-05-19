#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define B(x) (1<<(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int oo = 0x3f3f3f3f;
const ll OO = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define lson rt<<1
#define rson rt<<1|1
void cmax(int& a, int b){ if (b>a)a = b; }
void cmin(int& a, int b){ if (b<a)a = b; }
void cmax(ll& a, ll b){ if (b>a)a = b; }
void cmin(ll& a, ll b){ if (b<a)a = b; }
void cmax(double& a, double b){ if (a - b < eps) a = b; }
void cmin(double& a, double b){ if (b - a < eps) a = b; }
void add(int& a, int b, int mod){ a = (a + b) % mod; }
void add(ll& a, ll b, ll mod){ a = (a + b) % mod; }
//const int MOD = 1e9 + 7;
const int maxn = 100005;
ll mod;
ll f[maxn], inv[maxn];

ll quick_pow(ll a, ll k){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans*a) % mod;
        a = (a*a) % mod;
        k >>= 1;
    }
    return ans;
}

ll lucas(ll n, ll m){
    if (n<m) return 0;
    return f[n] * inv[m] % mod * inv[n - m] % mod;
}

ll C(ll n, ll m){
    if (!m) return 1;
    return lucas(n % mod, m % mod) * C(n / mod, m / mod) % mod;
}

int main(){
    int T, x1, x2, y1, y2, p;
    while (scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &p) != EOF){
        mod = p;
        f[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++){
            f[i] = f[i - 1] * i%p;
            inv[i] = inv[i - 1] * quick_pow(i, mod - 2) % mod;
        }
        ll ans = 0;
        for (int i = y1; i <= y2; i++){
            ans += ((C(x2 + 1, i + 1) - C(x1, i + 1)) % mod + mod) % mod;
            ans %= mod;
        }
        ans = (ans%mod + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}