#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define N 20002
struct node {
    int l, r, b, id;
} q[N];
int n, a[N], m, L, R, c[N], phi[N];
ll sum, ans[N];
vector<int> d[N];
bool cmp(const node &x, const node &y) {
    if (x.b == y.b) return x.r < y.r;
    return x.b < y.b;
}
ll add(int val) {
    ll ret = 0;
    for (int i=0; i<d[val].size(); i++)
        ret += phi[d[val][i]]*(c[d[val][i]]++);
    return ret;
}
ll del(int val) {
    ll ret = 0;
    for (int i=0; i<d[val].size(); i++)
        ret += phi[d[val][i]]*(--c[d[val][i]]);
    return ret;
}
void work(int l, int r, int x) {
    if (x) {
        for (int i=l; i<L; i++) sum += add(a[i]);
        for (int i=R+1; i<=r; i++) sum += add(a[i]);
        for (int i=L; i<l; i++) sum -= del(a[i]);
        for (int i=r+1; i<=R; i++) sum -= del(a[i]);
    } else {
        sum = 0;
        for (int i=l; i<=r; i++) sum += add(a[i]);
    }
    L = l, R = r;
}
int main() {
    for (int i=1; i<N; i++) phi[i] = i;
    for (int i=2; i<N; i++) if (phi[i] == i) {
        for (int j=i; j<N; j+=i) phi[j] = phi[j]/i*(i-1);
    }
    for (int i=1; i<N; i++) for (int j=i; j<N; j+=i) d[j].push_back(i);


    int T;
    scanf("%d", &T);
    for (int cas=1; cas<=T; cas++) {
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int i=1; i<=n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);
        int block_size = sqrt(n*1.0);
        for (int i=0; i<m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].b = q[i].l / block_size;
            q[i].id = i;
        }
        sort(q, q+m, cmp);

        for (int i=0; i<m; i++) {
            work(q[i].l, q[i].r, i);
            ans[q[i].id] = sum;
        }
        printf("Case #%d:\n", cas);
        for (int i=0; i<m; i++)
            cout << ans[i] << endl;
    }
    return 0;
}
