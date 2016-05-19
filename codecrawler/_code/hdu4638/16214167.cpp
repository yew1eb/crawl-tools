#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 101000
bool vis[N];
int n, s[N], m, ans[N], a[N], p[N];
struct node {
    int l, r, id;
    bool operator<(const node &x) const {
        return r > x.r;
    }
} q[N];
inline int lowbit(int x) {
    return x&(-x);
}
void add(int x, int v) {
    while (x <= n) {
        s[x] += v;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ret = 0;
    while (x) {
        ret += s[x];
        x -= lowbit(x);
    }
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            p[a[i]] = i;
        }
        memset(s, 0, sizeof(s));
        memset(vis, false, sizeof(vis));
        for (int i=n; i>0; i--) {
            if (vis[a[i]-1] && vis[a[i]+1]) add(i, -1);
            if (!vis[a[i]-1] && !vis[a[i]+1]) add(i, 1);
            vis[a[i]] = true;
        }

        for (int i=0; i<m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }

        sort(q, q+m);
        int j = n;
        for (int i=0; i<m; i++) {
            while (j > q[i].r) {
                if (a[j]>1 && p[a[j]-1] < j) add(p[a[j]-1], 1);
                if (a[j]<n && p[a[j]+1] < j) add(p[a[j]+1], 1);
                j--;
            }
            ans[q[i].id] = sum(q[i].r) - sum(q[i].l-1);
        }

        for (int i=0; i<m; i++) printf("%d\n", ans[i]);
    }

    return 0;
}
