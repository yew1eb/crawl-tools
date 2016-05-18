#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define clr(a,b) memset(a,b,sizeof(a))
typedef long long lld;
const int INF = ~0u>>1;

const int MAXN = 30010;
struct Edge {
    int v, next;
}g[MAXN*10];
int head[MAXN], tot;
int n,m,nq;
struct Q {
    int l, r, id;
    int b;
    bool operator < (const Q &tt) const {
        if(b == tt.b) return r < tt.r;
        return b < tt.b;
    }
}q[MAXN];
int ans[MAXN];
int fa[MAXN];
int L,R;
int vis[MAXN];
int tfa[MAXN];
int block_size;
int rcnt;
int now;

int Find(int x) {
    return fa[x] = (fa[x] == x) ? x : Find(fa[x]);
}

int merge(int a, int b) {
    a = Find(a);    b = Find(b);
    if(a == b) return 0;
    fa[a] = b;
    return 1;
}

int Tfind(int x) {
    if(vis[x] != now) {
        tfa[x] = fa[x];
        vis[x] = now;
    }
    return tfa[x] = (tfa[x] == x) ? x : Tfind(tfa[x]);
}

int Tmerge(int a, int b) {
    a = Tfind(a);   b = Tfind(b);
    if(a == b) return 0;
    tfa[a] = b;
    return 1;
}

int work(int l, int r, int ss) {
    if(ss != L/block_size - 1) {
        L = (ss+1) * block_size;
        rcnt = 0;
        R = L+1;
        for(int i=L-block_size+1; i<=L; i++) fa[i] = i;
    }
    for(; R<=r; R++) {
        fa[R] = R;
        rcnt ++;
        for(int p=head[R]; ~p; p=g[p].next) {
            int v = g[p].v;
            if(v >= R || v <= L) continue;
            if(merge(R,v)) rcnt --;
        }
    }
    int tr = min(r,L);
    int ret = 0;
    if(r>L) ret += rcnt;
    for(int i=l; i<=tr; i++) {
        ret ++;
        for(int p=head[i]; ~p; p=g[p].next) {
            int v = g[p].v;
            if(v<=i || v>r) continue;
            if(Tmerge(i,v)) ret --;
        }
    }
    return ret;
}

void add_edge(int a, int b) {
    g[tot].v = b;
    g[tot].next = head[a];
    head[a] = tot ++;
}

int main() {
    int cas, ca = 0;
    scanf("%d", &cas);
    while(cas--) {
        clr(head, -1);
        tot = 0;
        scanf("%d%d", &n, &m);
        int a,b;
        REP(i,0,m) {
            scanf("%d%d", &a, &b);
            add_edge(a,b);
            add_edge(b,a);
        }
        scanf("%d", &nq);
        block_size = (int)sqrt(n*1.0);
        REP(i,0,nq) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].b = q[i].l/block_size;
            q[i].id = i;
        }
        sort(q,q+nq);
        L = R = -1;
        clr(vis,-1);
        REP(i,0,nq) {
            now = i;
            ans[q[i].id] = work(q[i].l,q[i].r,q[i].b);
        }
        printf("Case #%d:\n", ++ca);
        REP(i,0,nq) printf("%d\n", ans[i]);
    }
    return 0;
}