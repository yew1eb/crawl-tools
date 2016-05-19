#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 110
typedef long long LL;
int A, M, P, Q, R, S;
struct List
{
    int s, n, cnt[MAXN];
    bool add[MAXN];
    bool operator < (const List &t) const
    {
        if(s != t.s) return s < t.s;
        int p = 0, r = cnt[0], tp = 0, tr = t.cnt[0];
        while(p < n && tp < t.n)
        {
            if(add[p] && !t.add[tp]) return true;
            if(!add[p] && t.add[tp]) return false;
            int min = std::min(r, tr);
            r -= min, tr -= min;
            if(r == 0) r = cnt[++ p];
            if(tr == 0) tr = t.cnt[++ tp];
        }
        return p == n && tp < t.n;
    }
}ans;
List gen(int a[], int mn)
{
    List ret;
    ret.s = mn, ret.n = 0;
    for(int i = 0, &n = ret.n; i <= mn; i ++)
    {
        ret.s += a[i];
        if(a[i] > 0)
        {
            ret.cnt[n] = a[i], ret.add[n] = true;
            ++ n;
        }
        if(i < mn)
        {
            if(n == 0 || ret.add[n - 1])
            {
                ret.cnt[n] = 1, ret.add[n] = false;
                ++ n;
            }
            else ++ ret.cnt[n - 1];
        }
    }
    return ret;
}
void process(int mn, int p, int px, int py)
{
    if(p > px) px = p;
    LL sum = ((p - px) % A + A) % A + px;
    if(sum > py) return;
    sum = (sum - p) / A;
    int t = sum, max = (py - p) / A, a[MAXN];
    for(int i = mn; i > 0; i --) a[i] = t % M, t /= M;
    a[0] = t;

    List opt;
    for(int i = mn, fac = 1; i >= 0; i --, fac *= M)
    {
        opt = gen(a, mn);
        if(opt < ans) ans = opt;
        if(i > 0 && a[i] != 0)
        {
            sum += (LL)(M - a[i]) * fac, a[i] = M;
            if(sum > max) break;
            for(int j = i; j > 0 && a[j] == M; j --)
                ++ a[j - 1], a[j] = 0;
        }
    }
}
int main()
{
    int t = 0;
    while(scanf("%d%d%d%d%d%d", &A, &M, &P, &Q, &R, &S), A > 0)
    {
        ans.s = INF;
        LL len = Q - P, p = P;
        for(int i = 0; p <= S - len && len <= S - R; i ++, len *= M, p *= M)
        {
            process(i, p, R, S - len);
            if(M == 1) break;
        }
        printf("Case %d:", ++ t);
        if(ans.s == INF) printf(" impossible");
        else if(ans.s == 0) printf(" empty");
        else
        {
            for(int i = 0; i < ans.n; i ++)
                printf(" %d%c", ans.cnt[i], ans.add[i] ? 'A' : 'M');
        }
        printf("\n");
    }
    return 0;
}