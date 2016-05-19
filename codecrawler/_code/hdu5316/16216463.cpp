#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 400005;
LL T, n, m, x, y, z, ans;

struct tree
{
    LL aa, ab, ba, bb;
    void clear(){ aa = ab = ba = bb = -0x7FFFFFFF; }
    LL maxn()
    {
        return max(max(aa, ab), max(ba, bb));
    }
}f[maxn], t;

tree reset(tree a, tree b)
{
    tree c;
    c.aa = max(a.aa + b.ba, a.ab + b.aa);
    c.aa = max(c.aa, max(a.aa, b.aa));
    c.ab = max(a.aa + b.bb, a.ab + b.ab);
    c.ab = max(c.ab, max(a.ab, b.ab));
    c.ba = max(a.ba + b.ba, a.bb + b.aa);
    c.ba = max(c.ba, max(a.ba, b.ba));
    c.bb = max(a.ba + b.bb, a.bb + b.ab);
    c.bb = max(c.bb, max(a.bb, b.bb));
    return c;
}

void build(LL now, LL l, LL r)
{
    if (l == r)
    {
        f[now].clear();
        if (l & 1) scanf("%lld", &f[now].aa);
        else scanf("%lld", &f[now].bb);
    }
    else
    {
        int mid = (l + r) >> 1;
        build(now + now, l, mid);
        build(now + now + 1, mid + 1, r);
        f[now] = reset(f[now + now], f[now + now + 1]);
    }
}

void change(LL now,LL l,LL r,LL one,LL v)
{
    if (l == r)
    {
        f[now].clear();
        if (l & 1) f[now].aa = v;
        else f[now].bb = v;
    }
    else
    {
        int mid = (l + r) >> 1;
        if (one <= mid) change(now + now, l, mid, one, v);
        else change(now + now + 1, mid + 1, r, one, v);
        f[now] = reset(f[now + now], f[now + now + 1]);
    }
}

void get(LL now, LL l, LL r, LL ll, LL rr)
{
    if (l >= ll&&r <= rr) t = reset(t, f[now]);
    else
    {
        int mid = (l + r) >> 1;
        if (ll <= mid) get(now + now, l, mid, ll, rr);
        if (rr > mid) get(now + now + 1, mid + 1, r, ll, rr);
    }
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        build(1, 1, n);
        while (m--)
        {
            scanf("%lld%lld%lld", &x, &y, &z);
            if (x) change(1, 1, n, y, z);
            else
            {
                t.clear();
                get(1, 1, n, y, z);
                printf("%lld\n", t.maxn());
            }
        }
    }
    return 0;
}