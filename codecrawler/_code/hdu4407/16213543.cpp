#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define N 400010
typedef long long LL;

int n, m;
struct node {
    int idx, v;
    node() {}
    node(int x, int y): idx(x), v(y) {}
};
vector<node> c;
bool is[N];
vector<int> pr;
void prime() {
    memset(is, true, sizeof(is));
    pr.clear();
    pr.push_back(2);
    for (int i=3; i<N; i+=2)
        if (is[i]) {
            pr.push_back(i);
            for (int j=i+i; j<N; j+=i) is[j] = false;
        }
}
LL cal(int x, int p, vector<int> &g) {
    LL ret = (LL)x*(x+1)/2;

    for (int s=1; s<(1<<g.size()); s++) {
        int cnt = 0;
        int v = 1;
        for (int i=0; i<g.size(); i++)
            if (s & (1<<i)) {
                cnt++;
                v *= g[i];
            }


        LL k = x / v;
        k = k*(k+1)*v/2;
        if (cnt % 2 == 1) ret -= k;
        else ret += k;
    }

    for (int i=0; i<c.size(); i++)
        if (c[i].idx <= x) {
            if (__gcd(c[i].idx, p) == 1)ret -= c[i].idx;
            if (__gcd(c[i].v, p) == 1) ret += c[i].v;
        }
    return ret;
}
void work(int x, int y, int p) {
    vector<int> g;
    int k = p;
    for (int i=0; i<pr.size() && pr[i]<=k; i++)
        if (k % pr[i] == 0) {
            g.push_back(pr[i]);
            while (k % pr[i] == 0) k /= pr[i];
        }

    printf("%I64d\n", cal(y, p, g)-cal(x-1, p, g));
}
int main() {

    prime();

    int T, x, y, o, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        c.clear();
        while (m--) {
            scanf("%d", &o);
            if (o == 1) {
                scanf("%d%d%d", &x, &y, &p);
                work(x, y, p);
            } else {
                scanf("%d%d", &x, &y);
                //å¤æ­å½åä½ç½®xæ¯ä¸æ¯å·²ç»è¢«ä¿®æ¹è¿ï¼å¤é
                bool f = true;
                for (int i=0; i<c.size(); i++)
                    if (c[i].idx == x) {
                        c[i].v = y;
                        f = false; break;
                    }
                if (f) c.push_back(node(x, y));
            }
        }
    }
    return 0;
}
