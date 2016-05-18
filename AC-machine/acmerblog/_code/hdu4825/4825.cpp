#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
//typedef __int64 ll;
typedef long long ll;

const int M = 55;
const int N = M*1e5;

struct Node {
    ll val;
    int l;
    int r;

    void clear() {
        l = r = -1;
    }
}node[N];

int p;
ll a, t[M];

void insert (int& root, int d, ll u) {

    if (root == -1) {
        root = p++;
        node[root].clear();
    }

    if (d == -1) {
        node[root].val = u;
        return;
    }

    if (u & t[d])
        insert(node[root].r, d - 1, u);
    else
        insert(node[root].l, d - 1, u);
}

void query(int root, int d, ll u) {

    if (d == -1) {
        printf("%lld\n", node[root].val);
        return;
    }

    if (((u & t[d]) && node[root].l != -1) || node[root].r == -1)
        query(node[root].l, d - 1, u);
    else
        query(node[root].r, d - 1, u);
}

int main () {
    int cas, n, m;
    scanf("%d", &cas);

    t[0] = 1;
    for (int i = 1; i < 55; i++)
        t[i] = t[i-1] * 2;

    for (int i = 1; i <= cas; i++) {
        p = 0;
        int root = -1;

        scanf("%d%d", &n, &m);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a);
            insert(root, 50, a);
        }

        printf("Case #%d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a);
            query(root, 50, a);
        }
    }
    return 0;
}