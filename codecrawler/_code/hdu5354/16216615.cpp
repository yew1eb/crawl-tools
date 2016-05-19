#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for(int i = pos[x]; i; i = g[i].nex)
using namespace std;
typedef long long LL;
const int N = 100005;
struct Edge { int y, nex, z1, z2, z; } g[N * 2];
int T, n, m, pos[N], sz, par[N], sum[N], l, ans[N], p1[N];
void Init(int x, int y) { g[++ sz].y = y, g[sz].nex = pos[x], pos[x] = sz; }
int Find(int x) { return (par[x] == x) ? x : (l = l ^ p1[x], Find(par[x])); }
bool Check(int l1, int r1, int l2, int r2) {
    bool fl = 0;
    Rep(x, l1, r1) {
        RepE(i, x) {
            int y = g[i].y;
            if (y > r2 || y < l2) {
                int lx, ly, x0, y0;
                l = 0, x0 = Find(x), lx = l;
                l = 0, y0 = Find(y), ly = l;
                if (x0 != y0) {
                    if (sum[x0] > sum[y0]) swap(x0, y0);
                    par[x0] = y0;
                    g[i].z1 = x0, g[i].z2 = y0, g[i].z = sum[y0];
                    p1[x0] = ((lx + ly) % 2 == 0);
                    sum[y0] += sum[x0];
                } else {
                    g[i].z1 = -1;
                    if ((lx + ly) % 2 == 0) fl = 1;
                }
            } else g[i].z1 = -1;
        }
    }
    return fl;
}
void Solve(int l, int r) {
    if (l == r) { ans[l] = 1; return ; }
    int mid = l + r >> 1;
    bool fl = Check(l, mid, mid + 1, r);
    if (fl) Rep(i, mid + 1, r) ans[i] = 0;
    else Solve(mid + 1, r);
    Rep(x, l, mid) {
        RepE(i, x) {
            int x0 = g[i].z1, y0 = g[i].z2;
            // cout << x0<<" "<<y0<<endl;
            if (x0 == -1) continue ;
            sum[y0] = min(sum[y0], g[i].z);
            par[x0] = x0;
        }
    }
    fl = Check(mid + 1, r, l, mid);
    if (fl) Rep(i, l, mid) ans[i] = 0;
    else Solve(l, mid);
    Rep(x, mid + 1, r) {
        RepE(i, x) {
            int x0 = g[i].z1, y0 = g[i].z2;
            if (x0 == -1) continue ;
            sum[y0] = min(sum[y0], g[i].z);
            par[x0] = x0;
        }
    }
}
int main()
{
    scanf ("%d", &T);
    while (T --) {
        scanf ("%d%d", &n, &m);
        Rep(i, 1, n) par[i] = i, sum[i] = 1, pos[i] = 0; sz = 0;
        Rep(i, 1, m) {
            int x, y;
            scanf ("%d%d", &x, &y);
            Init(x, y), Init(y, x);
        }
        Solve(1, n);
        Rep(i, 1, n) printf("%d", ans[i]);
        puts("");
    }
    
    return 0;
}