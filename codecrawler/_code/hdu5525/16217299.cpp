#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7;
const int maxn = 100010;
bool is_prime[maxn];
int prime[maxn];
int len;

void init() {

    int i, j;
    len = 0;
    memset(is_prime, true, sizeof(is_prime));
    prime[len++] = 2;
    for(i = 4; i < maxn; i += 2) {
        is_prime[i] = false;
    }
    for(i = 3; i * i <= maxn; i += 2) {
        if(is_prime[i]) {
            prime[len++] = i;
            for(j = i * i; j < maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for( ; i < maxn; i += 2) {
        if(is_prime[i]) {
            prime[len++] = i;
        }
    }
    return ;
}

ll  num[maxn];
int a[maxn];
map< int, map<int, int> > mp;

void get_factor(int x) {
    int tx = x;
    for(int i = 0; i < len && prime[i] * prime[i] <= x; ++i) {
        if(x % prime[i] == 0) {
            int cnt = 0;
            while(x % prime[i] == 0) {
                x /= prime[i];
                cnt++;
            }
            mp[tx][prime[i]] = cnt;
        }
    }
    if(x > 1) mp[tx][x] = 1;
    return ;
}

void init2() {
    mp.clear();
    for(int i = 1; i <= 100000; ++i) {
        get_factor(i);
    }
    return ;
}

ll power_mod(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}

ll inv(ll a, ll n) {
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if(d != 1) {
        return -1;
    }
    return (x % n + n) % n;
}

int main() {

    //freopen("aa.in", "r", stdin);

    init();
    init2();
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        ll t = 1;
        for(int i = 2; i <= n; ++i) {
            for(map<int, int>::iterator it = mp[i].begin(); it != mp[i].end(); ++it) {
                num[it->first] += it->second * a[i];
            }
        }
        bool first = true;
        for(int i = 2; i <= n; ++i) {
            if(num[i] > 0) {
                t = t * (num[i] + 1);
                if(t % 2 == 0 && first) {
                    t /= 2;
                    first = false;
                }
                t %= (mod - 1);
            }
        }
        ll ans = 1;
        for(int i = 2; i <= n; ++i) {
            if(num[i] > 0) {
                ll tt = t;
                tt *= num[i];
                if(tt % 2 == 0 && first) {
                    tt /= 2;
                    tt %= (mod - 1);
                }
                ans = ans * power_mod(i, tt) % mod;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
