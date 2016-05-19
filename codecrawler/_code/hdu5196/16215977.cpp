#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000000
#define MOD 1000000
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
template<class T> inline T Max(T a, T b)
{
    return a > b ? a : b;
}
template<class T> inline T Min(T a, T b)
{
    return a < b ? a : b;
}
const int maxn = 100005;
int a[maxn],b[maxn],rmi[maxn],rma[maxn],nct,n;
ll k,c[maxn];
inline int getpos(int x)
{
    return lower_bound(b+1,b+1+nct,x)-b;
}

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int x, int k)
{
    while(x <= nct)
    {
        c[x] += k;
        x += lowbit(x);
    }
}

ll sum(int x)
{
    ll ret = 0;
    while(x)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

struct node
{
    int l,r,id;
    bool operator < (const node &t) const
    {
        return l != t.l ? l < t.l : r < t.r;
    }
};

node no[maxn];

void init(int *tmp, int flag)
{
    for(int i = 0; i <= nct; i++) c[i] = 0;
    int r = 0;
    ll all = 0,da = 0;
    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            if(all == k)
            {
                tmp[i] = r;
                if(flag) break;
            }
            if(r == n) break;
            da = sum(nct)-sum(a[r+1]);
            if(all+da == k)
            {
                all += da;
                tmp[i] = ++r;
                add(a[r],1);
                if(flag) break;
            }
            else if(all+da > k) break;
            else
            {
                all += da;
                r++;
                add(a[r],1);
            }
        }
        all -= sum(a[i]-1);
        add(a[i],-1);
    }
}

struct Tree
{
    ll v,flag;
};
Tree T[maxn<<2];

inline void pushup(int rt)
{
    T[rt].v = T[rt<<1].v+T[rt<<1|1].v;
}

void build(int l, int r, int rt)
{
    T[rt].v = T[rt].flag = 0;
    if(l == r) return;
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
}

inline void pushdown(int l, int r, int rt)
{
    if(T[rt].flag)
    {
        int mid = (l+r)>>1;
        T[rt<<1].flag += T[rt].flag;
        T[rt<<1|1].flag += T[rt].flag;
        T[rt<<1].v += (ll)(mid-l+1)*T[rt].flag;
        T[rt<<1|1].v += (ll)(r-mid)*T[rt].flag;
        T[rt].flag = 0;
    }
}

void update(int L, int R, ll k, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        T[rt].v += (ll)(r-l+1)*k;
        T[rt].flag += k;
        return;
    }
    pushdown(l,r,rt);
    int mid = (l+r)>>1;
    if(L <= mid) update(L,R,k,lson);
    if(R > mid) update(L,R,k,rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
        return T[rt].v;
    pushdown(l,r,rt);
    int mid = (l+r)>>1;
    ll ret = 0;
    if(L <= mid) ret += query(L,R,lson);
    if(R > mid) ret += query(L,R,rson);
    return ret;
}

ll ans[maxn];
int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o.txt","w",stdout);
#endif
    int q;
    while(~scanf("%d%d%I64d",&n,&q,&k))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+1+n);
        nct = unique(b+1,b+1+n)-(b+1);
        for(int i = 1; i <= n; i++)
            a[i] = getpos(a[i]);
//        for(int i = 1; i <= n; i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        if(k != 0)
        {
            for(int i = 1; i <= n; i++) rmi[i] = rma[i] = 0;
            init(rmi,1);
            init(rma,0);
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                rmi[i] = i;
                rma[i] = 0;
            }
            int r = 1,i = 1;
            while(i <= n)
            {
                while(a[r+1] >= a[r] && r <= n) r++;
                while(i <= r)
                {
                    rma[i] = r;
                    i++;
                }
                r++;
            }
        }
//        for(int i = 1; i <= 9; i++) cout<<rmi[i]<<" ";
//        cout<<endl;
//        for(int i = 1; i <= 9; i++) cout<<rma[i]<<" ";
//        cout<<endl;
        for(int i = 1; i <= q; i++)
        {
            scanf("%d%d",&no[i].l,&no[i].r);
            no[i].id = i;
        }
        sort(no+1,no+1+q);
        build(1,n,1);
        for(int i = 1; i <= n; i++)
        {
            if(rmi[i] != 0) update(rmi[i],rma[i],1,1,n,1);
        }
        int i = 1,l = 1;
        while(i <= q)
        {
            while(l < no[i].l)
            {
                if(rmi[l] != 0) update(rmi[l],rma[l],-1,1,n,1);
                l++;
            }
            while(no[i].l == l && i <= q)
            {
                ans[no[i].id] = query(no[i].l,no[i].r,1,n,1);
                i++;
            }
        }
        for(int i = 1; i <= q; i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}