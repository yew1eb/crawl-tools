#include <cstdio>
#include <set>
#include <vector>
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int MAXN = 5e4 + 5;

int cnt;
int left[MAXN], right[MAXN];
vector<int> G[MAXN];

void dfs(int k)
{
    left[k] = cnt++;
    for(int i = 0; i < G[k].size(); i++)
        dfs(G[k][i]);
    right[k] = cnt - 1;
}

int task[MAXN << 2], lazy[MAXN << 2];

void push_down(int rt)
{
    if(lazy[rt] != -1)
    {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        task[rt << 1] = task[rt << 1 | 1] = lazy[rt];
        lazy[rt] = -1;
    }
}
void build(int l, int r, int rt)
{
    lazy[rt] = -1;
    if(l == r)
    {
        task[rt] = -1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void updata(int L, int R, int t, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        task[rt] = t;
        lazy[rt] = t;
        return ;
    }
    push_down(rt);
    int m = (l + r) >> 1;
    if(m >= L) updata(L, R, t, lson);
    if(m < R) updata(L, R, t, rson);
}
int query(int k, int l, int r, int rt)
{
    if(l == r)
        return task[rt];
    push_down(rt);
    int m = (l + r) >> 1;
    if(m >= k) return query(k, lson);
    if(m < k) return query(k, rson);
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int ca = 1; ca <= T; ca++)
    {
        printf("Case #%d:\n", ca);

        int n;
        scanf("%d", &n);

        set<int> S;
        for(int i = 1; i <= n; i++)
            G[i].clear(), S.insert(i);

        for(int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[b].push_back(a);
            S.erase(a);
        }

        cnt = 1;
        dfs(*S.begin());
        build(root);

        int q;
        scanf("%d", &q);
        while(q--)
        {
            char op[2]; int x, y;
            scanf("%s", &op);
            if(op[0] == 'C')
            {
                scanf("%d", &x);
                printf("%d\n", query(left[x], root));
            }
            else
            {
                scanf("%d%d", &x, &y);
                updata(left[x], right[x], y, root);
            }
        }
    }

    return 0;
}