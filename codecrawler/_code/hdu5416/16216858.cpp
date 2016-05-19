#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <vector>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <iomanip>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
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
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int N = 1e5 + 10;
typedef long long ll;
typedef pair<int, int> pii;
struct Edge {
    int from, to, dis, nex;
}edge[3 * N];
int head[N], edgenum;  //fa[i][x] æ¯içç¬¬2^xä¸ªç¶äº²ï¼å¦æè¶è¿èå´å°±æ¯æ ¹ï¼  
void add(int u, int v, int w) {
    Edge E = { u,v,w,head[u] };
    edge[edgenum] = E;
    head[u] = edgenum++;
}
void init() { memset(head, -1, sizeof head); edgenum = 0; }

int n;
int mp[N*2];
void dfs(int u, int fa, int dep) {
    mp[dep]++;
    for (int i = head[u]; ~i; i = edge[i].nex) {
        int v = edge[i].to; if (v == fa)continue;
        dfs(v, u, dep ^ edge[i].dis);
    }    
}
ll ans;
int s;
void go(int u, int fa, int dep) {
//    mp[dep]--;
    ans += mp[s^dep];
    for (int i = head[u]; ~i; i = edge[i].nex) {
        int v = edge[i].to; if (v == fa)continue;
        go(v, u, dep ^ edge[i].dis);

    }
//    mp[dep]++;
}
int main() {
    int T; rd(T);
    while (T--) {
        init();
        rd(n);
        for (int i = 1, u, v, d; i < n; i++) {
            rd(u); rd(v); rd(d);
            add(u, v, d);
            add(v, u, d);
        }
        memset(mp, 0, sizeof mp);
        dfs(1, 1, 0);
        int Q; rd(Q);
        while (Q--) {
            rd(s);
            ans = 0;
            go(1, 1, 0);
            if (s == 0)ans += n;
            ans >>= 1;
            pt(ans); puts("");
        }
    }
    return 0;
}/*
1
2
1 2 0
10
0

 */