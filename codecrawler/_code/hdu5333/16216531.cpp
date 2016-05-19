#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

#define LL long long
#define eps 1e-8
#define MP make_pair
#define N 500020
#define M 80020
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define ls (i << 1)
#define rs (ls | 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define mod 258280327
#define inf 0x3f3f3f3f


#define ULL unsigned long long


int readint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9'));
    int ret = c - '0';
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    return ret;
}


struct edge {
    int u, v;
    edge() {}
    void input() {
        u = readint();
        v = readint();
        if(u < v) swap(u, v);
    }
    bool operator < (const edge &b) const {
        return u < b.u;
    }

}a[N];

struct query {
    int l, r, ans, id;
    void input(int id) {
        this -> id = id;
        l = readint();
        r = readint();
        ans = 0;
    }
    bool operator < (const query &b) const {
        return r < b.r;
    }
}b[N];

int ch[N][2], rt[N], pre[N], rev[N], mi[N];
int val[N];

int key[N];


int n, m, q;

int bit[N];

void update_rev(int x) {
    if(!x) return;
    rev[x] ^= 1;
    swap(ch[x][0], ch[x][1]);
}

bool judge(int x, int y) {
    while(pre[x]) x = pre[x];
    while(pre[y]) y = pre[y];
    return x == y;
}

void push_up(int x) {
    mi[x] = key[x];
    if(val[mi[ch[x][0]]] < val[mi[x]]) mi[x] = mi[ch[x][0]];
    if(val[mi[ch[x][1]]] < val[mi[x]]) mi[x] = mi[ch[x][1]];
}

void push_down(int x) {
    if(rev[x]) {
        update_rev(ch[x][0]);
        update_rev(ch[x][1]);
        rev[x] = 0;
    }
}

void P(int x) {
    if(!rt[x]) P(pre[x]);
    push_down(x);
}

void rot(int x) {
    int y = pre[x], d = ch[y][1] == x;

    ch[y][d] = ch[x][!d];
    pre[ch[x][!d]] = y;
    pre[x] = pre[y];
    pre[y] = x;
    ch[x][!d] = y;
    if(rt[y]) rt[y] = false, rt[x] = true;
    else
        ch[pre[x]][ch[pre[x]][1]==y] = x;
    push_up(y);
}

void splay(int x) {
    P(x);
    while(!rt[x]) {
        int f = pre[x], ff = pre[f];
        if(rt[f]) rot(x);
        else if((ch[ff][1] == f) == (ch[f][1] == x))
            rot(f), rot(x);
        else
            rot(x), rot(x);
    }
    push_up(x);
}

void Access(int x) {
    int y = 0;
    for(; x; y = x, x = pre[x]) {
        splay(x);
        rt[ch[x][1]] = true;
        ch[x][1] = y;
        rt[y] = false;
        push_up(x);
    }
}
void make_root(int x) {
    Access(x);
    splay(x);
    update_rev(x);
}

void link(int x, int y) {
    make_root(x);
    pre[x] = y;
}

void cut(int x, int y) {
    make_root(x);
    splay(y);
    pre[ch[y][0]] = pre[y];
    pre[y] = 0;
    rt[ch[y][0]] = true;
    ch[y][0] = 0;
    push_up(y);
}

void lca(int &x, int &y) {
    Access(y), y = 0;
    for(splay(x); pre[x]; y = x, x = pre[x], splay(x)) {
        rt[ch[x][1]] = true;
        ch[x][1] = y;
        rt[y] = false;
        push_up(x);
    }
}

//ok
int query_mi(int x, int y) {
    /*
    make_root(x);
    Access(y);
    splay(y);
    return mi[y];
    */
    lca(x, y);
    int ret = key[x];
    if(val[mi[y]] < val[ret]) ret = mi[y];
    if(val[mi[ch[x][1]]] < val[ret]) ret = mi[ch[x][1]];
    return ret;
}

bool cmp(query x, query y) {
    return x.id < y.id;
}
//ok
void bit_add(int x, int v) {
   // printf("bit_add %d %d\n", x, v);
    while(x <= n) {
        bit[x] += v;
        x += x & -x;
    }
}
//ok
int bit_query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

int main() {
    //freopen("tt.txt", "r", stdin);
    while(scanf("%d%d%d", &n, &m, &q) != EOF) {
        for(int i = 1; i <= m; ++i) {
            a[i].input();
        }
        for(int i = 1; i <= q; ++i) {
            b[i].input(i);
        }

        sort(a + 1, a + m + 1);
        sort(b + 1, b + q + 1);

        for(int i = 0; i <= n; ++i) val[i] = inf;
        for(int i = 1; i <= m; ++i) val[i+n] = a[i].v;

        int j = 1;

        for(int i = 1; i <= n + m; ++i) {
            pre[i] = 0;
            rt[i] = 1;
            key[i] = i;
            mi[i] = i;
            ch[i][0] = ch[i][1] = 0;
            rev[i] = 0;
        }

        for(int i = 1; i <= n; ++i) bit[i] = 0;
        int tot = 0;
        for(int i = 1; i <= q; ++i) {
            while(j <= m && a[j].u <= b[i].r) {
                int u = a[j].u, v = a[j].v;

                if(!judge(u, v)) {
                    link(u, j + n);
                    link(v, j + n);
                    bit_add(val[j+n], 1);
                    ++tot;
                }
                else {
                    int t = query_mi(u, v);
                    if(val[t] < val[j+n]) {
                        cut(a[t-n].u, t);
                        cut(a[t-n].v, t);
                        bit_add(val[t], -1);
                        link(u, j + n);
                        link(v, j + n);
                        bit_add(val[j+n], 1);
                    }
                }
                ++j;
            }
            int t = bit_query(b[i].l - 1);
            b[i].ans = n - (tot - t);
        }
        sort(b + 1, b + q + 1, cmp);
        for(int i = 1; i <= q; ++i)
            printf("%d\n", b[i].ans);
    }
    return 0;
}
