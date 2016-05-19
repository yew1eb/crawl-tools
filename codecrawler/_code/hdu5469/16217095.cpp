#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
#define eps 1e-6
#define pii pair<int, int>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define ULL unsigned long long
const int MAXN = 10100;
const int INF = 0x3f3f3f3f;
const ULL base = 31;
int n, len;
char node[MAXN], target[MAXN];
ULL pre[MAXN], suf[MAXN], bit[MAXN];
int vis1[MAXN], vis2[MAXN];
bool vis[MAXN], ans;
int root, cnt;  
int des[MAXN], bal[MAXN];
struct Edge {
    int to,next;
} edge[MAXN*2];
int head[MAXN], tot;
void addedge(int u,int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void get_root(int cur, int fa, int tot) {
    des[cur] = 1;
    bal[cur] = 0;
    for(int i = head[cur]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(vis[u] || u==fa) continue;
        get_root(u, cur, tot);
        des[cur] += des[u];
        bal[cur] = max(bal[cur], des[u]);
    }
    bal[cur] = max(bal[cur], tot-des[cur]);
    if(bal[cur] < bal[root]) root = cur;
    else if(bal[cur] == bal[root]) root=min(cur, root);
}

int get_size(int cur, int fa) {
    int ans = 1;
    for(int i = head[cur]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(u==fa || vis[u]) continue;
        ans += get_size(u, cur);
    }
    return ans;
}
void dfs(int cur, int fa, ULL w, int op, int dep) {
    dep++;
    if(ans || dep>len) return;
    w = w*base+(ULL)node[cur];
    if(!op) {
        if(w==pre[dep]) {
            if(vis2[dep] == cnt) {
                ans = 1;
                return;
            }
        }
        if(w==suf[len-dep+1]) {
            if(vis1[len-dep+1] == cnt) {
                ans = 1;
                return;
            }
        }
    }
    else {
        if(w==pre[dep]) vis1[dep] = cnt;
        if(w==suf[len-dep+1]) vis2[len-dep+1] = cnt;
    }
    for(int i = head[cur]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(vis[u] || u==fa) continue;
        dfs(u, cur, w, op, dep);
    }
}
void solve(int cur, int tot) {
    if(ans) return;
    vis[cur] = 1;
    ++cnt;
    ULL w = node[cur];
    if(w==pre[len]) {
        ans = 1; 
        return;
    }
    if(w==pre[1]) vis1[1] = cnt;
    if(w==suf[len]) vis2[len] = cnt;
    for(int i = head[cur]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(vis[u]) continue;
        dfs(u, cur, w, 0, 1);
        if(ans) return;
        dfs(u, cur, w, 1, 1);
    }
    //cout << ans1 << endl << ans2 <<endl;
    for(int i = head[cur]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(vis[u]) continue;
        int sz = get_size(u, cur);
        if(sz < len) continue;
        root = 0; get_root(u, cur, sz);
        solve(root, sz);
    }
}
void init() {
    memset(head,-1,sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    bal[0] = INF;
    cnt = 0;
    ans = 0;
    tot = 0; 
}
template<class T>
inline bool read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int T; cin >> T;
    bit[0] = 1;
    for(int i = 1; i <= 10001; i++) bit[i] = bit[i-1]*base;
    int kase = 0;
    while(T--) {
        scanf("%d", &n);
        init();
        for(int i = 1, u, v; i < n; i++) {
            read(u); read(v);
            addedge(u, v);
            addedge(v, u);
        }
        scanf("%s", (node+1));
        scanf("%s", (target+1));
        len = strlen(target+1); 
        for(int i = 1; i <= len; i++) pre[i] = pre[i-1]+target[i]*bit[i-1];
        suf[len+1] = 0;
        for(int i = len; i>=1; i--) suf[i] = suf[i+1]+target[i]*bit[len-i];
        root = 0; get_root(1, -1, n);
        solve(root, n);
        printf("Case #%d: ", ++kase); 
        if(ans) puts("Find"); 
        else puts("Impossible");
    }
    return 0;
}
















