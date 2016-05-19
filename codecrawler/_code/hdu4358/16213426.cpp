#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100010;
int t, n, k, q;
int w[maxn], a[maxn];
int L[maxn], R[maxn];   // è¯¢é®åºé´çå·¦ãå³ç«¯ç¹ 
int ans[maxn], id;
vector<int> vt[maxn];   // ä¸´æ¥è¡¨ 
vector<int> vv[maxn];
bool vis[maxn];
map<int, int> mp;
struct Query {
    int l, r, id;
}Q[maxn];
// for segment tree:
int add[maxn<<2];

bool cmp(Query q1, Query q2)
{
    return q1.r < q2.r;
}

void dfs(int x)
{   // å°æ å½¢ç»æåæçº¿æ§ç»æ 
    vis[x] = true;
    L[x] = id;
    a[id] = w[x];
    int size = vt[x].size();
    for (int i = 0; i < size; ++i) {
        if (!vis[vt[x][i]]) {
            id++;
            dfs(vt[x][i]);
        }
    }
    R[x] = id;
}

void pushDown(int rt)
{
    if (add[rt]) {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        add[rt] = 0;
    }
    return ;
}

void build(int l, int r, int rt)
{
    add[rt] = 0;
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void update(int l, int r, int rt, int L, int R, int c)
{
    if (L <= l && R >= r) {
        add[rt] += c;
        return ;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) {
        update(l, m, rt << 1, L, R, c);
    }
    if (R > m) {
        update(m + 1, r, rt << 1 | 1, L, R, c);
    }
}

int query(int l, int r, int rt, int p)
{
    if (l == r) {
        return add[rt];
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (p <= m) {
        return query(l, m, rt << 1, p);
    } else {
        return query(m + 1, r, rt << 1 | 1, p);
    }
}

int main()
{
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d%d", &n, &k);
        mp.clear();
        id = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &w[i]);
            // ç¦»æ£å 
            if (mp[w[i]] == 0) {
                mp[w[i]] = id++;
            }
            w[i] = mp[w[i]];
        }
        int u, v;
        for (int i = 0; i < maxn; ++i) {
            vt[i].clear();
            vv[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        memset(vis, false, sizeof(vis));
        id = 1;
        dfs(1);
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d", &u);
            Q[i].id = i;
            Q[i].l = L[u];
            Q[i].r = R[u];
        }
        sort(Q, Q + q, cmp);
        build(1, n, 1);
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            // çº¿æ®µæ ç¬¬jä¸ªæ°è¡¨ç¤º[j, i]é´åºç°kæ¬¡çæ°çä¸ªæ° 
            int num = a[i];
            vv[num].push_back(i);
            int size = vv[num].size();
            if (size >= k) {
                if (size > k) {
                    // 1 ~ vv[num][size-k-1]é½å1 
                    update(1, n, 1, 1, vv[num][size-k-1], -1);
                    // vv[num][size-k-1]+1 ~ vv[num][size-k]é½å 1 
                    update(1, n, 1, vv[num][size-k-1] + 1, vv[num][size-k], 1);
                } else {
                    // å 1 
                    update(1, n, 1, 1, vv[num][size-k], 1);
                }
            }
            while (Q[idx].r == i) {
                ans[Q[idx].id] = query(1, n, 1, Q[idx].l);
                idx++;
            }
        }
        if (cas != 1) {
            printf("\n");
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < q; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
