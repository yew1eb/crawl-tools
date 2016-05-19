#include <bits/stdc++.h>
using namespace std;

const int N = 30000 + 10;
const int M = 30000 + 10;

struct node {
    int id;
    int is;
    int flag;
    int l, r;
    node(int id = 0, int is = 0, int flag = 0, int l = 0, int r = 0) :
        id(id), is(is), flag(flag), l(l), r(r) {}
    bool operator < (const node& rhs) const {
        return is < rhs.is || (is == rhs.is && r < rhs.r);
    }
}date[M << 2];
int n, m, k, tot;
int a[N], cnt[N], answer[M];

void work() {
    sort(date + 1, date + tot + 1);
    int ans = 0;
    int l = 1, r = 0;
    for (int i = 1; i <= tot; i ++) {
        int x = date[i].id;
        int y = date[i].flag;
        while (date[i].l < l) {
            l --;
            cnt[a[l]] ++;
            if (k - a[l] >= 1) {
                ans += cnt[k - a[l]];
            }
        }
        while (date[i].l > l) {
            cnt[a[l]] --;
            if (k - a[l] >= 1) {
                ans -= cnt[k - a[l]];
            }
            l ++;
        }
        while (date[i].r > r) {
            r ++;
            cnt[a[r]] ++;
            if (k - a[r] >= 1) {
                ans += cnt[k - a[r]];
            }
        }
        while (date[i].r < r) {
            cnt[a[r]] --;
            if (k - a[r] >= 1) {
                ans -= cnt[k - a[r]];
            }
            r --;
        }
        answer[x] += y * ans;
    }
}
int main() {
    while (scanf("%d", &n) == 1) {
        scanf("%d", &k);
        for (int i = 1; i <= n; i ++) {
            cnt[i] = 0;
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        tot = 0;
        int size = (int)sqrt(n);
        for (int i = 1; i <= m; i ++) {
            answer[i] = 0;
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            date[++ tot] = node(i, l1 / size, 1, l1, r2);
            date[++ tot] = node(i, l1 / size, -1, l1, l2 - 1);
            date[++ tot] = node(i, (r1 + 1) / size, -1, r1 + 1, r2);
            if (r1 + 1 <= l2 - 1) {
                date[++ tot] = node(i, (r1 + 1) / size, 1, r1 + 1, l2 - 1);
            }
        }
        work();
        for (int i = 1; i <= m; i ++) {
            printf("%d\n", answer[i]);
        }
    }
    return 0;
}
