//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int maxn = 300010;

struct Query
{
    int a, b, i;
    bool operator < (const Query &rhs) const
    {
        return b < rhs.b;
    }
    void input(int ii = 0)
    {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        i = ii;
    }
} que[maxn], e[maxn];

int n, m, q, ans[maxn], block_tot;
int ch[maxn][2], fa[maxn], rt[maxn], miv[maxn];
int val[maxn], sum[maxn], rev[maxn];

void ins(int x, int c)
{
    for(int i = x; i <= n; i += i&(-i))
        sum[i] += c;
}

int getsum(int x)
{
    int ans = 0;
    for(int i = x; i; i -= i&(-i))
        ans += sum[i];
    return ans;
}

void update_rev(int r)
{
    if(!r) return;
    swap(ch[r][0], ch[r][1]);
    rev[r] ^= 1;
}

void push_up(int x)
{
    int lc = ch[x][0], rc = ch[x][1];
    miv[x] = x;
    if(val[miv[lc]] < val[miv[x]]) miv[x] = miv[lc];
    if(val[miv[rc]] < val[miv[x]]) miv[x] = miv[rc];
}

void push_down(int r)
{
    if(rev[r])
    {
        update_rev(ch[r][0]);
        update_rev(ch[r][1]);
        rev[r] = 0;
    }
}

bool judge(int u, int v)
{
    while(fa[u]) u = fa[u];
    while(fa[v]) v = fa[v];
    return u == v;
}

void rotate(int x)
{
    int y = fa[x], kind = ch[y][1]==x;
    ch[y][kind] = ch[x][!kind];
    fa[ch[y][kind]] = y;
    fa[x] = fa[y];
    fa[y] = x;
    ch[x][!kind] = y;
    if(rt[y])
        rt[y] = 0, rt[x] = 1;
    else
        ch[fa[x]][ch[fa[x]][1]==y] = x;
    push_up(y);
}

void P(int r)
{
    if(!rt[r]) P(fa[r]);
    push_down(r);
}

void splay(int x)
{
    P(x);
    while(!rt[x])
    {
        int f = fa[x], ff = fa[f];
        if(rt[f])
            rotate(x);
        else if((ch[ff][1]==f)==(ch[f][1]==x))
            rotate(f), rotate(x);
        else
            rotate(x), rotate(x);
    }
    push_up(x);
}

void access(int x)
{
    // return;
    for(int t = 0; x; t = x, x = fa[x])
    {
        splay(x);
        rt[ch[x][1]] = 1;
        rt[ch[x][1]=t] = 0;
        push_up(x);
    }
}

void makeroot(int x)
{
    access(x);
    splay(x);
    update_rev(x);
}

void cut(int x, int y)
{
    makeroot(x);
    splay(y);
    fa[ch[y][0]] = fa[y];
    fa[y] = 0;
    rt[ch[y][0]] = 1;
    ch[y][0] = 0;
    push_up(y);
}

void link(int x, int y)
{
    makeroot(x);
    fa[x] = y;
}

int query(int x, int y)
{
    makeroot(x);
    access(y);
    splay(y);
    return miv[y];
}

void gao(int u, int v, int i)
{
    // printf("%d %d :: %d %d", u, v, fa[u], fa[v]); cout << endl;
    if(judge(u, v))
    {
        int t = query(u, v);
        if(u == v || u <= val[t]) return;
        block_tot++;
        cut(t, e[t-n-1].a);
        cut(t, e[t-n-1].b);
        ins(val[t], -1);
    }
    block_tot--;
    val[n+i] = u;
    miv[n+i] = n+i;
    link(u, n+i);
    link(v, n+i);
    ins(u, 1);
    // for(int j = 1; j <= n+m; j++)
    //     printf("%d ", fa[j]);
    // cout << "return" << i << ' ' << u << ' ' << v << ' ' << block_tot << endl;
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &q))
    {
        for(int i = 0; i <= n; i++)
            val[i] = INF, sum[i] = 0;
        for(int i = 0; i <= n+m; i++)
            rev[i] = ch[i][0] = ch[i][1] = fa[i] = 0, rt[i] = 1;

        for(int i = 0; i < m; i++)
            e[i].input();
        sort(e, e+m);
        for(int i = 0; i < q; i++)
            que[i].input(i);
        sort(que, que+q);

        block_tot = n;
        for(int i = 0, j = 0; i < q; i++)
        {
            int l = que[i].a, r = que[i].b;
            while(j < m && e[j].b <= r)
            {
                gao(e[j].a, e[j].b, j+1);
                j++;
                // printf("%d %d___\n", j, m);
            }
            ans[que[i].i] = block_tot + getsum(l-1);
            // printf("%d %d__%d\n", l-1, block_tot, que[i].i);
        }
        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
