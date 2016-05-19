#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

typedef long long LL;

#define REP(i, n) for (int i(0); i < (int) (n); i++)

#define left LLLLL
#define right RRRRR

const int N = 100000 + 10;

int n;
int a[N];
int f[N];
int c[N];
int head, tail;
int left[N], right[N], pos[N];

void solve() {
    int tot = 0;
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", a + i);
        c[tot ++] = a[i];
    }
    sort(c, c + tot);
    tot = unique(c, c + tot) - c;
    for(int i = 1; i <= n; ++ i) {
        a[i] = lower_bound(c, c + tot, a[i]) - c + 1;
    }
    for(int i = 1; i <= tot; ++ i) {
        pos[i] = -1;
    }
    
    f[0] = 0;
    head = tail = 0;
    pos[0] = 0;

    for(int i = 1; i <= n; ++ i) {
        int v = a[i];
        if (v == tail) {
        } else {
            if (pos[v] != -1) {
                int nl = left[v];
                int nr = right[v];
                left[nr] = nl;
                right[nl] = nr;
            }
            left[v] = tail;
            right[tail] = v;
            tail = v;
        }
        pos[v] = i;

        int cost = 1;
        for(int u = left[tail]; ; u = left[u]) {
            if (cost == 1) {
                f[i] = f[pos[u]] + cost * cost;
            } else {
                f[i] = min(f[i], f[pos[u]] + cost * cost);
            }
            if (u == 0) break;
            ++ cost;
            if (cost * cost >= f[i]) break;
        }
    }

    cout << f[n] << endl;
}

int main() {
    for( ; cin >> n; ) {
        solve();
    }
    return 0;
}