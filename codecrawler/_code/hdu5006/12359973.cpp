#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 10032;
const int INF = 1000000000;
const long long Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-6;

struct EDGE {
    int u, v, w, next;
}e[N * 8];
int head[N], cnt;

void add(int u, int v, int w) {
    e[cnt].u = u; e[cnt].v = v; e[cnt].w = w; e[cnt].next = head[u]; head[u] = cnt ++;
}

int n, m, sv, tv, bel[N], ID, mp[1010][1010], INV[1010];
queue<int> q;
double a[510][510];

void init() {
    memset(head, - 1, sizeof(head)); 
    cnt = 0;

    memset(bel, - 1, sizeof(bel));
    ID = 0;
}

void Merge(int s) {
    while(!q.empty()) q.pop();
    bel[s] = ++ ID; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i != - 1; i = e[i].next) {
            if(e[i].w == 0) {
                int v = e[i].v;
                if(bel[v] == -1) {
                    bel[v] = ID;
                    q.push(v);
                }  
            }
        }
    }
}

void color_bfs(int s) {
    while(!q.empty()) q.pop();
    q.push(s); bel[s] = ++ ID; INV[ID] = s;
    while(!q.empty()) {
        int u = q.front(); q.pop(); 
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(bel[v] == -1) {
                bel[v] = ++ ID;
                INV[ID] = v;
                q.push(v);
            }
        }
    }
}

double calc() {
    for(int k = 1; k <= n; k++) {
        int p = k;
        while(p <= n && fabs(a[p][k]) < eps) ++ p;
        if(p != k) {
            for(int j = 1; j <= n + 1; j++) {
                swap(a[p][j], a[k][j]);
            }
        }
        if(p == n + 1) {
            continue;
        }
        double tmp = a[k][k];
        for(int j = 1; j <= n + 1; j++) {
            a[k][j] /= tmp;
        }
        for(int i = 1; i <= n; i++) {
            if(i == k) continue;
            double t = a[i][k];
            for(int j = 1; j <= n + 1; j++) {
                a[i][j] -= t * a[k][j];
            }
        }
    }
    return a[bel[sv]][n + 1] - a[bel[tv]][n + 1];
}

void solve() {
    scanf("%d%d%d%d", &n, &m, &sv, &tv);
    init();
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= n; i++) {
        if(bel[i] == -1) {
            Merge(i);
        }
    }

    
    if(ID >= 1010) {
        while(1);
    }
    

    memset(mp, 0, sizeof(mp));
    for(int i = 0; i < cnt; i += 2) {
        int u = e[i].u, v = e[i].v;
        if(bel[u] == bel[v] || e[i].w == 0) continue;
        mp[bel[u]][bel[v]] ++;
        mp[bel[v]][bel[u]] ++;
    }
    /*
    printf("%d %d %d\n", ID, bel[sv], bel[tv]);
    for(int i = 1; i <= ID; i++) {
        for(int j = 1; j <= ID; j++) {
            printf("%d ", mp[i][j]);
        }
        puts("");
    }
    */
    n = ID; sv = bel[sv]; tv = bel[tv];
    if(sv == tv) {
        printf("%.6f\n", 0.0);
        return;
    }
    init();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[i][j]) {
                add(i, j, mp[i][j]);
            }
        }
    }
    color_bfs(sv);
    if(bel[tv] == -1) {
        puts("inf");
        return;
    }
    memset(a, 0, sizeof(a));
    n = ID;
    
    if(ID >= 510) {
        puts("fuck");
        while(1);
    }
    
    
    for(int k = 1; k <= n; k++) {
        int u = INV[k], c = 0;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            a[k][bel[v]] = w;
            c += w;
        }
        a[k][k] = -c;
        if(k == bel[sv]) {
            a[k][n + 1] = -1;
        }
        else if(k == bel[tv]) {
            a[k][n + 1] = 1;
        }
        else {
            a[k][n + 1] = 0;
        }
    }
    double ans = calc();
    printf("%.6f\n", ans);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}