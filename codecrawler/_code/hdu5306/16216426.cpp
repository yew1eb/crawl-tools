#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define prt(k) cout<<#k" = "<<k<<" ";
const int N = 1000003<<2;
struct Node
{
    int l, r;
    int mx;
    ll ss;
    int tag;
    int cv; /// How many nodes are infected by tag in subtree
} T[N] ;
int a[N];
#define lx x<<1
#define rx x<<1|1
#define lo o<<1
#define ro o<<1|1
/// cvï¼è¿ä¸ªåºé´æå¤å°ä¸ªç»ç¹ï¼å·²è¢« tag å½±åã

void pushup(int x)
{
    T[x].ss = T[lx].ss + T[rx].ss;
    T[x].mx = max(T[lx].mx, T[rx].mx);
    T[x].cv = T[lx].cv + T[rx].cv;
}
void mark(int x, int t)  /// da biao ji
{
    if (T[x].tag!=0 && T[x].tag <= t) return ;

    T[x].tag = t;
    int l = T[x].l, r = T[x].r;
    if (T[x].cv != r - l + 1)
    {
        T[x].mx = t;
        T[x].ss += 1ll * (r - l + 1 - T[x].cv) * t;
        T[x].cv = r - l + 1;
    }
}
void pushdown(int x)
{
    if (T[x].tag==0) return;
    mark(lx, T[x].tag);
    mark(rx, T[x].tag);
}
void fix(int o, int t )
{
    if (T[o].mx < t) return;
    if (T[o].tag >= t)
    {
        T[o].tag = 0;  ///
    }
    if (T[o].l==T[o].r)
    {
        T[o].ss = T[o].mx = T[o].tag;
        T[o].cv = T[o].tag != 0;
    }
    else
    {
        pushdown(o);
        fix(lo, t);
        fix(ro, t);
        pushup(o);
    }
}
void update(int o, int t , int L, int R)
{
    if (T[o].mx <= t) return;
    if (R < T[o].l || T[o].r < L ) return;

    if (L<=T[o].l && T[o].r<=R)
    {
        fix(o, t);
        if (T[o].l == T[o].r)
        {
            T[o].ss = T[o].mx=  T[o].tag = t;
            T[o].cv = 1;
        }
        else
        {
            pushup(o);
        }
        mark(o, t);
    }
    else
    {
        pushdown(o);
        update(o<<1, t, L, R);
        update(o<<1|1, t, L, R);
        pushup(o);
    }
}

void build(int o, int l, int  r)
{
    T[o].l = l;
    T[o].r = r;
    if (l==r)
    {
        T[o].ss = T[o].mx = T[o].tag = a[l];
        T[o].cv = 1;
        return;
    }
    int m = (l + r) >> 1;
    T[o].tag = 0;
    build(lo, l, m);
    build(ro, m+1, r);
    pushup(o);
}
Node query(int o, int L, int R)
{
    Node ret ;
    if (L > T[o].r || R < T[o].l)
    {
        ret.mx = ret.ss = 0;
        return ret;
    }
    if (L<=T[o].l && T[o].r <= R) return T[o];
    pushdown(o);
    Node a = query(lo, L, R);
    Node b = query(ro, L, R);
    ret.mx = max(a.mx, b.mx);
    ret.ss = a.ss + b.ss;
    return ret;
}
/************Read**********/
char *ch, *ch1, buf[40*1024000+5], buf1[40*1024000+5];

void read(int &x)
{
    for (++ch; *ch <= 32; ++ch);
    for (x = 0; '0' <= *ch; ch++)    x = x * 10 + *ch - '0';
}

/**************************/
int n, m;
int main()
{
    ch = buf - 1;
    ch1 = buf1 - 1;
    fread(buf, 1, 1000 * 35 * 1024, stdin);
    int re;
    read(re);
    while (re--)
    {
        read(n);
        read(m);
        for (int i = 1; i <= n; i++)
            read(a[i]);

        build(1 ,  1, n);

        while (m--)
        {
            int t, x, y, z;
            read(t);
            read(x);
            read(y);
            if (!t)
            {
                read(z);
                update(1, z, x, y);

            }
            else if (t == 1) printf("%d\n", query(1, x, y).mx);
            else printf("%I64d\n", query(1, x, y).ss);

        }
    }
    return 0;
}
/**
1
5 5
1 2 3 4 5
1 1 5
2 1 5
0 3 5 3
1 1 5
2 1 5
*/
