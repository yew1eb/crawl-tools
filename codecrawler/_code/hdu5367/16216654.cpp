#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1200005;
int n, m, h, l, r;

struct node
{
    int lh, rh, lr, rl, lf, rf,l, r;
    void clear(){ l = r = lh = rh = lr = rl = lf = rf = 0; }
};

struct ST
{
    int L[maxn], R[maxn], f[maxn], sum[maxn];
    node u[maxn];
    int n, tt;
    int newnode(int l, int r)
    {
        f[++tt] = 0;
        L[tt] = R[tt] = sum[tt] = 0;
        u[tt].clear();
        u[tt].l = u[tt].rl = l;
        u[tt].r = u[tt].lr = r;
        return tt;
    }
    void build(int x)
    { 
        n = x; tt = 1; 
        sum[1] = L[1] = R[1] = f[1] = 0;
        u[1].clear();
        u[0].clear();
        u[1].rl = u[1].l = 1;
        u[1].lr = u[1].r = n;
    }
    void update(int x, int l, int r, int lx, int rx)
    {
        int llh = u[lx].lh + sum[lx];
        int lrh = u[lx].rh + sum[lx];
        int rlh = u[rx].lh + sum[rx];
        int rrh = u[rx].rh + sum[rx];
        int mid = (l + r) >> 1;
        u[x].lh = llh;    u[x].rh = rrh;
        if (u[lx].lr == u[lx].r && llh == rlh)
        {
            u[x].lr = rx ? u[rx].lr : r;
            u[x].lf = u[rx].lf;
        }
        else
        {
            u[x].lr = lx ? u[lx].lr : mid;
            if (u[lx].lr == u[lx].r) u[x].lf = llh > rlh ? 1 : 0;
            else u[x].lf = u[lx].lf;
        }
        if (u[rx].rl == u[rx].l&&rrh == lrh)
        {
            u[x].rl = lx ? u[lx].rl : l;
            u[x].rf = u[lx].rf;
        }
        else
        {
            u[x].rl = rx ? u[rx].rl : (mid + 1);
            if (u[rx].rl == u[rx].l) u[x].rf = rrh > lrh ? 1 : 0;
            else u[x].rf = u[rx].rf;
        }
        f[x] = f[lx] + f[rx];
        if (u[lx].rl > u[lx].l&&lrh > rlh&&u[lx].rf) f[x] += u[lx].r - u[lx].rl + 1;
        if (u[rx].lr < u[rx].r&&rlh > lrh&&u[rx].lf) f[x] += u[rx].lr - u[rx].l + 1;
        if (u[lx].rl > u[lx].l&&u[rx].lr < u[rx].r&&lrh == rlh&&u[lx].rf&&u[rx].lf)
            f[x] += u[rx].lr - u[lx].rl + 1;
    }
    void add(int x, int l, int r, int ll, int rr, int v)
    {
        if (ll <= l&&r <= rr) sum[x] += v; 
        else
        {
            int mid = (l + r) >> 1;
            if (ll <= mid)
            {
                if (!L[x]) L[x] = newnode(l, mid);
                add(L[x], l, mid, ll, rr, v);
            }
            if (rr > mid)
            {
                if (!R[x]) R[x] = newnode(mid + 1, r);
                add(R[x], mid + 1, r, ll, rr, v);
            }
            update(x, l, r, L[x], R[x]);
        }
    }
}st;

int main()
{
    while (scanf("%d%d%d", &n, &m, &h) != EOF)
    {
        st.build(n);
        while (m--)
        {
            scanf("%d%d%d", &l, &r, &h);
            l ^= st.f[1];    
            r ^= st.f[1];    
            h ^= st.f[1];
            if (l > r) swap(l, r);
            st.add(1, 1, n, l, r, h);
            printf("%d\n", st.f[1]);
        }
    } 
    return 0;
}