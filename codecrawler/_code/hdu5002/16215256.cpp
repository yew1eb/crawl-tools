#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
#define N 100010
#define L(x) (ch[x][0])
#define R(x) (ch[x][1])
#define inf -2147483640

int ch[N][2], pre[N], rev[N], me[N];
int cov[N], add[N], size[N], max1[N], num1[N], max2[N], num2[N];
bool rt[N];

struct helper {
    int val, num;
    bool operator<(const helper ff) const {
        return val > ff.val;
    }
} hel[10];

void Update_COV(int u, int d) {
    if (!u)
        return;
    me[u] = d;
    cov[u] = d;
    add[u] = inf;
    max1[u] = d;
    num1[u] = size[u];
    max2[u] = inf;
    num2[u] = 0;
}

void Update_Add(int u, int d) {
    if (!u)
        return;
    me[u] += d;
    if (add[u] != inf)
        add[u] += d;
    else
        add[u] = d;
    max1[u] += d;
    if (max2[u] != inf)
        max2[u] += d;
}

void Update_Rev(int u) {
    if (!u)
        return;
    swap(L(u), R(u));
    rev[u] ^= 1;
}

void down(int u) {
    if (rev[u]) {
        Update_Rev(L(u));
        Update_Rev(R(u));
        rev[u] = 0;
    }
    if (cov[u] != inf) {
        Update_COV(L(u), cov[u]);
        Update_COV(R(u), cov[u]);
        cov[u] = inf;
    }
    if (add[u] != inf) {
        Update_Add(L(u), add[u]);
        Update_Add(R(u), add[u]);
        add[u] = inf;
    }
}

void up(int u) {
    size[u] = size[L(u)] + size[R(u)] + 1;
    hel[0].val = max1[L(u)];
    hel[0].num = num1[L(u)];
    hel[1].val = max2[L(u)];
    hel[1].num = num2[L(u)];
    hel[2].val = max1[R(u)];
    hel[2].num = num1[R(u)];
    hel[3].val = max2[R(u)];
    hel[3].num = num2[R(u)];
    hel[4].val = me[u];
    hel[4].num = 1;
    sort(hel, hel + 5);
    int i;
    for (i = 1; i < 5; i++) {
        if (hel[i].val != hel[i - 1].val)
            break;
    }
    max1[u] = hel[0].val;
    max2[u] = hel[i].val;
    num1[u] = num2[u] = 0;
    for (i = 0; i < 5; i++) {
        if (hel[i].val == max1[u])
            num1[u] += hel[i].num;
        else if (hel[i].val == max2[u])
            num2[u] += hel[i].num;
    }
}

//Rotate P Splay ä¸è¬ä¸å
void Rotate(int x) {
    int y = pre[x], kind = ch[y][1] == x;
    ch[y][kind] = ch[x][!kind];
    pre[ch[y][kind]] = y;
    pre[x] = pre[y];
    pre[y] = x;
    ch[x][!kind] = y;
    if (rt[y])
        rt[y] = false, rt[x] = true;
    else
        ch[pre[x]][ch[pre[x]][1] == y] = x;
    up(y);
}

//På½æ°åå°splayæ ¹ç»ç¹å°uçè·¯å¾ä¸ææçç»ç¹çæ è®°éçº§ä¸æ¾
void P(int u) {
    if (!rt[u])
        P(pre[u]);
    down(u);
}

void Splay(int u) {
    P(u);
    while (!rt[u]) {
        int fa = pre[u], ffa = pre[fa];
        if (rt[fa])
            Rotate(u);
        else if ((R(ffa) == fa) == (R(fa) == u))
            Rotate(fa), Rotate(u);
        else
            Rotate(u), Rotate(u);
    }
    up(u);
}

//å°rootå°uçè·¯å¾åæå®è¾¹
int Access(int u) {
    int v = 0;
    for (; u; u = pre[v = u]) {
        Splay(u);
        rt[R(u)] = true, rt[R(u) = v] = false;
        up(u);
    }
    return v;
}

//ä½¿uæä¸ºå®æå¨çæ çæ ¹
void mroot(int u) {
    Access(u);
    Splay(u);
    Update_Rev(u);
}

//è¿æ¥ä¸¤æ£µæ   uæ¥å¨vä¸
void link(int u, int v) {
    mroot(u);
    pre[u] = v;
}

//u-vè¾¹æ­å¼
void cut(int u, int v) {
    mroot(u);
    Access(u);
    Splay(v);
    pre[L(v)] = pre[v];
    pre[v] = 0;
    rt[L(v)] = true;
    L(v) = 0;
    up(v);
}

//u-vè·¯å¾æå¼åä¸ºw
void COV(int u, int v, int w) {
    mroot(u);
    Access(v);
    Splay(v);
    Update_COV(v, w);
}

//u-vè·¯å¾+w
void ADD(int u, int v, int w) {
    mroot(u);
    Access(v);
    Splay(v);
    Update_Add(v, w);
}

//u-vè·¯å¾æå¤§å¼
void query(int u, int v) {
    mroot(u);
    Access(v);
    Splay(v);
    if (max2[v] != inf)
        printf("%d %d\n", max2[v], num2[v]);
    else
        printf("ALL SAME\n");
}

struct edge {
    int v, next;
} ed[N * 2];
int head[N], tot;

void addedge(int u, int v) {
    ed[tot].v = v;
    ed[tot].next = head[u];
    head[u] = tot++;
}

//å©ç¨dfsåå§åpreæ°ç»  å»ºç«LCT
void dfs(int u) {
    for (int i = head[u]; ~i; i = ed[i].next) {
        int v = ed[i].v;
        if (pre[v] != 0)
            continue;
        pre[v] = u;
        dfs(v);
    }
}

int main() {
    int T, t, n, m, i, op, u, v, x, y, w;
    max1[0] = max2[0] = inf;
    rt[0] = true;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            scanf("%d", &me[i]);
            max1[i] = me[i];
            max2[i] = inf;
            num1[i] = 1;
            num2[i] = 0;
            size[i] = 1;
            add[i] = cov[i] = inf;
            L(i) = R(i) = pre[i] = rev[i] = 0;
            rt[i] = true;
        }
        tot = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        pre[1] = -1;
        dfs(1);
        pre[1] = 0;
        printf("Case #%d:\n", t);
        while (m--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d%d", &u, &v, &x, &y);
                cut(u, v);
                link(x, y);
            } else if (op == 2) {
                scanf("%d%d%d", &u, &v, &w);
                COV(u, v, w);
            } else if (op == 3) {
                scanf("%d%d%d", &u, &v, &w);
                ADD(u, v, w);
            } else {
                scanf("%d%d", &u, &v);
                query(u, v);
            }
        }
    }
    return 0;
}
