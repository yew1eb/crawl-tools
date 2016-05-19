#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 100005
#define MAXM 320005
#define INF 100000007
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
int n;
int a[MAXN];
bool ls[4 * MAXN][10], rs[4 * MAXN][10], ok[4 * MAXN][10];
int sum[4 * MAXN];
struct node
{
    bool ls[10], rs[10], ok[10];
    int sum;
    void init()
    {
        memset(ls, 0, sizeof(ls));
        memset(rs, 0, sizeof(rs));
        memset(ok, 0, sizeof(ok));
    }
};
void up(int rt)
{
    ok[rt][sum[lch(rt)]] = 1;
    ok[rt][sum[rch(rt)]] = 1;
    for(int i = 0; i < 10; i++)
    {
        if(ls[lch(rt)][i]) ls[rt][i] = 1;
        if(rs[rch(rt)][i]) rs[rt][i] = 1;
        if(ok[lch(rt)][i] || ok[rch(rt)][i]) ok[rt][i] = 1;
        if(ls[rch(rt)][i])
        {
            int v = sum[lch(rt)] + i;
            if(v > 9) v -= 9;
            ls[rt][v] = 1;
            ok[rt][v] = 1;
        }
        if(rs[lch(rt)][i])
        {
            int v = sum[rch(rt)] + i;
            if(v > 9) v -= 9;
            rs[rt][v] = 1;
            ok[rt][v] = 1;
            for(int j = 0; j < 10; j++)
                if(ls[rch(rt)][j])
                {
                    v = i + j;
                    if(v > 9) v -= 9;
                    ok[rt][v] = 1;
                }
        }
    }
    sum[rt] = sum[lch(rt)] + sum[rch(rt)];
    if(sum[rt] > 9) sum[rt] -= 9;
    ok[rt][sum[rt]] = 1;
}
void build(int l, int r, int rt)
{
    memset(rs[rt], 0, sizeof(rs[rt]));
    memset(ls[rt], 0, sizeof(ls[rt]));
    memset(ok[rt], 0, sizeof(ok[rt]));
    if(l == r)
    {
        rs[rt][a[l]] = 1;
        ls[rt][a[l]] = 1;
        ok[rt][a[l]] = 1;
        sum[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    up(rt);
}
int out[11];
void query(int L, int R, int l, int r, int rt, node &p)
{
    if(L <= l && R >= r)
    {
        p.sum = sum[rt];
        p.ok[sum[rt]] = 1;
        for(int i = 0; i < 10; i++)
        {
            if(ok[rt][i]) p.ok[i] = 1;
            if(ls[rt][i]) p.ls[i] = 1;
            if(rs[rt][i]) p.rs[i] = 1;
        }
        return;
    }
    int m = (l + r) >> 1;
    if(m < L) query(L, R, rson, p);
    else if(m >= R) query(L, R, lson, p);
    else
    {
        node lf, rf;
        lf.init(), rf.init();
        query(L, m, lson, lf);
        query(m + 1, R, rson, rf);
        p.sum = lf.sum + rf.sum;
        if(p.sum > 9) p.sum -= 9;
        p.ok[p.sum] = 1;
        for(int i = 0; i < 10; i++)
        {
            if(lf.ls[i]) p.ls[i] = 1;
            if(rf.rs[i]) p.rs[i] = 1;
            if(lf.ok[i] || rf.ok[i]) p.ok[i] = 1;
            if(rf.ls[i])
            {
                int v = i + lf.sum;
                if(v > 9) v -= 9;
                p.ls[v] = 1;
                p.ok[v] = 1;
            }
            if(lf.rs[i])
            {
                int v = i + rf.sum;
                if(v > 9) v -= 9;
                p.rs[v] = 1;
                p.ok[v] = 1;
                for(int j = 0; j < 10; j++)
                    if(rf.ls[j])
                    {
                        int v = i + j;
                        if(v > 9) v -= 9;
                        p.ok[v] = 1;
                    }
            }
        }
    }
}
int in()
{
    int flag = 1;
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    if(ch == '-') flag = -1;
    else
        a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return flag * a;
}
void Out(int a)
{
    if(a < 0)
    {
        putchar('-');
        a = -a;
    }
    if(a >= 10)Out(a / 10);
    putchar(a % 10 + '0');
}
int main()
{
    int T, cas = 0;
    T = in();
    //scanf("%d", &T);
    while(T--)
    {
        if(cas) printf("\n");
        n = in();
        //scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            //scanf("%d", &a[i]);
            a[i] = in();
            if(a[i] && a[i] % 9 == 0) a[i] = 9;
            else a[i] = a[i] % 9;
        }
        build(1, n, 1);
        int ask, x, y;
        printf("Case #%d:\n", ++cas);
        scanf("%d", &ask);
        int tp[10], fk[10];
        while(ask--)
        {
            //scanf("%d%d", &x, &y);
            x = in();
            y = in();
            node ans;
            ans.init();
            query(x, y, 1, n, 1, ans);
            int ct = 0;
            for(int i = 9; i >= 0; i--)
                if(ans.ok[i])
                {
                    tp[ct++] = i;
                    if(ct >= 5) break;
                }
            for(int i = 0; i < ct; i++)
            {
                //printf("%d", tp[i]);
                Out(tp[i]);
                if(i == ct - 1 && ct == 5) putchar('\n');
                else putchar(' ');
            }
            if(ct < 5)
            {
                for(int i = 0; i < 5 - ct; i++)
                {
                    Out(-1);
                    //printf("-1");
                    if(i == 4 - ct) putchar('\n');
                    else putchar(' ');
                }
            }
        }
    }
    return 0;
}
