#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime> // possible need;
#include <cstdlib> // possible need;
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long type;
type mul_mod (type a, type b, type mod) {
    type ret = 0;
    while (b) {
        if (b&1)
            ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}

type pow_mod (type a, type n, type mod) {
    type ans = 1;
    while (n) {
        if (n&1)
            ans = mul_mod(ans, a, mod);
        a = mul_mod(a, a, mod);
        n >>= 1;
    }
    return ans;
}

bool miller_rabin(type n) {
    if (n < 2)
        return false;

    srand(time(0));
    for (int i = 0; i < 20; i++)
        if (pow_mod(rand() % (n-1) + 1, n-1, n) != 1)
            return false;
    return true;
}

typedef long long ll;
const int maxn = 1e6;

bool vis[maxn+5];
int np, pri[maxn+5];

void prime_table (int n) {
    np = 0;
    memset(vis, 0, sizeof(vis));

    for (int i = 3; i <= n; i += 2) {
        if (vis[i])
            continue;
        pri[np++] = i;
        for (int j = i * 2; j <= n; j += i)
            vis[j] = 1;
    }
}

bool judge (ll M) {
    if (M % 2 == 0)
        M /= 2;

    for (int i = 0; i < np; i++) {
        ll tmp = M;
        while (tmp % pri[i] == 0)
            tmp /= pri[i];
        if (tmp == 1)
            return true;
    }

    if (M <= 1000000LL)
        return false;

    if (miller_rabin(M))
        return true;

    ll x = sqrt(M+0.0);
    while (x * x < M)
        x++;

    if (x * x != M)
        return false;

    if (miller_rabin(x))
        return true;
    return false;
}

int main () {
    ll M;
    prime_table(maxn);

    //srand(time(0));
    while (scanf("%I64d", &M) == 1 && M != -1) {
        if (M == 1 || M == 2 || M == 4 || judge(M))
            printf("%I64d\n", M-1);
        else
            printf("1\n");
    }
    return 0;
}