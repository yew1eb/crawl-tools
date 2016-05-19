#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 50005;
ll C[N], n, m, w[N];
struct pp {
    ll l;
    ll r;
}q[N];

bool cmp(pp a, pp b) {
    if (a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}

long long  getC(ll n) {
    if (n < 3)
        return 0;
    return n * (n - 1) * (n - 2) / 6;
}

int lowbit(int x) {
    return  x & (-x);
}

int Sum(int x) {
    long long ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x); 
    }
    return ret;
}

void Add(int x, int d) {
    while (x <= N) {
        C[x] += d;
        x += lowbit(x);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll sum = 0;
        memset(C, 0, sizeof(C));
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &w[i]);
        for (int i = 0; i < m; i++) {
            scanf("%lld%lld",&q[i].l, &q[i].r);
        }
        if (m < 3) {
            printf("0\n");
            continue;
        }
        ll MAX = 0;
        for (int i = 0; i < m; i++) {
            if (q[i].r > MAX)
                MAX = q[i].r;
        }
        sort(q, q + m, cmp);
        ll cur = 1;
        for (int i = 0; i < m; i++) {
            if (q[i].l > cur) {
                ll tmp = Sum(cur - 1);
                sum += getC(i - tmp) * w[cur];
                cur++;
                i--;
                continue;
            }else if (i == m - 1) {
                Add(q[i].r, 1);
                ll tmp = Sum(cur - 1);
                sum += getC(i + 1 - tmp) * w[cur];
                while (cur <= MAX) {
                    cur++;
                    ll tmp = Sum(cur - 1);
                    sum += getC(m - tmp) * w[cur];
                }
            }
            Add(q[i].r, 1);
        }
        ll k = __gcd(getC(m),sum);
        printf("%lld", sum/k);
        if(getC(m)/k != 1)
            printf("/%lld", getC(m)/k);
        puts("");
    }
    return 0;
}
