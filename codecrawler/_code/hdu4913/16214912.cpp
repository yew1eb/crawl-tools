#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100007
#define mod 1000000007
typedef long long ll;
#define lc (d<<1)
#define rc (d<<1|1)
#define mid (l+r>>1)

struct Tr{
    int cnt, lz;
    ll sum;
}tr[N<<4];

struct Po{
    int x, y;
    bool operator<(const Po a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
}po[N];

ll cal(ll a, int b) {
    ll x = 1;
    while (b) {
        if (b&1) x = x*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return x;
}

int b[N];

void Push(int d) {
    tr[d].sum = tr[lc].sum+tr[rc].sum;
    if (tr[d].sum >= mod) tr[d].sum -= mod;
    tr[d].cnt = tr[lc].cnt+tr[rc].cnt;
}

void lazy(int d) {
    if (tr[d].lz) {
        ll tm = cal(2, tr[d].lz);
        tr[lc].sum = tr[lc].sum*tm%mod, tr[rc].sum = tr[rc].sum*tm%mod;
        tr[lc].lz += tr[d].lz, tr[rc].lz += tr[d].lz;
        tr[d].lz = 0;
    }
}

void build(int d, int l, int r) {
    tr[d].lz = 0;
    if (l == r) {
        tr[d].sum = 0, tr[d].cnt = 0;
        return;
    }
    build(lc, l, mid);
    build(rc, mid+1, r);
    Push(d);
}

int C(int d, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (l == L && r == R) {
        return tr[d].cnt;
    }
    lazy(d);
    if (R <=  mid) return C(lc, l, mid, L, R);
    else if (L > mid) return C(rc, mid+1, r, L, R);
    else return C(lc, l, mid, L, mid)+C(rc, mid+1, r, mid+1, R);
}

ll S(int d, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (l == L && r == R) {
        return tr[d].sum;
    }
    lazy(d);
    if (R <= mid) return S(lc, l, mid, L, R);
    else if (L > mid) return S(rc, mid+1, r, L, R);
    else return (S(lc, l, mid, L, mid)+S(rc, mid+1, r, mid+1, R))%mod;
}

void update(int d, int l, int r, int L, int R) {
    if (l == L && r == R) {
        tr[d].lz++;
        tr[d].sum = tr[d].sum*2%mod;
        return;
    }
    lazy(d);
    if (R <= mid) update(lc, l, mid, L, R);
    else if (L > mid) update(rc, mid+1, r, L, R);
    else update(lc, l, mid, L, mid), update(rc, mid+1, r, mid+1, R);
    Push(d);
}

void add(int d, int l, int r, int pos, ll v) {
    if (l == r && l == pos) {
        tr[d].sum += v;
        if (tr[d].sum >= mod) tr[d].sum -= mod;
        tr[d].cnt++;
        return;
    }
    lazy(d);
    if (pos <= mid) add(lc, l, mid, pos, v);
    else add(rc, mid+1, r, pos, v);
    Push(d);
}

int main()
{
    int n, i, j;
    while (~scanf("%d", &n)) {
        for (i = 1;i <= n;i++) {
            scanf("%d%d", &po[i].x, &po[i].y);
            b[i] = po[i].y;
        }
        sort(b+1, b+1+n);
        int m = unique(b+1, b+1+n)-b-1;
        build(1, 1, m);
        ll ans = 0;
        sort(po+1, po+n+1);
        for (i = 1;i <= n;i++) {
            int id = lower_bound(b+1, b+1+m, po[i].y)-b;
            int cnt = C(1, 1, m, 1, id-1);
            ll tm = cal(2, cnt), tp = cal(3, po[i].y), tk = cal(2, po[i].x);
            ans = ans+tm*tp%mod*tk%mod;
            while (ans >= mod) ans -= mod;
            ll sum = S(1, 1, m, id, m);
            ans = ans+sum*tk%mod;
            while (ans >= mod) ans -= mod;
         //   printf("%I64d\n", ans);
            update(1, 1, m, id, m);
            add(1, 1, m, id, tm*tp%mod);
        }
        printf("%I64d\n", ans);
    }
}
