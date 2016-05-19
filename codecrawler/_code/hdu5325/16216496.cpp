#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<int, int> pii;
const int N = 500000 + 10;

int n;
vector<int>G[N];
pii a[N];
int w[N], r[N];
int main() {
    while (cin>>n) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            rd(a[i].first); a[i].second = i;
            w[i] = a[i].first;
        }
        for (int i = 1, u, v; i < n; i++) {
            rd(u); rd(v); G[u].push_back(v); G[v].push_back(u);
        }
        sort(a + 1, a + 1 + n);
        int ans = 1;
        for (int i = n; i; i--) {
            int id = a[i].second;
            int tmp = 1;
            for (auto v : G[id]) {
                if (w[id] > w[v])continue;
                tmp += r[v];
            }
            r[id] = tmp;
            ans = max(ans, tmp);
        }
        pt(ans); puts("");
    }
    return 0;
}