#pragma comment(linker, "/STACK:10240000000000,10240000000000")
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int inf = 10000000;
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1000000+3;
int ni[mod];
void quick(int x){
    int ans = 1, tmp = x, y = mod-2;
    while(y){
        if(y&1)
            ans = (ll)ans * (ll)x % (ll)mod;
        x = (ll)x*(ll)x%(ll)mod;
        y>>=1;
    }
    ni[tmp] = ans;
}
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if(x>9) pt(x/10);
    putchar(x%10+'0');
}
#define N 100005
pii ans;
void updata(int x, int y){
    if(x>y)swap(x,y);
    if(ans.first > x || ans.first==x && ans.second > y)
        ans = pii(x,y);
}
struct Edge{
    int to, nex;
}edge[N<<1];
int head[N], edgenum;
void init(){memset(head,-1,sizeof head); edgenum = 0;}
void add(int u, int v){
    Edge E = {v,head[u]};
    edge[edgenum] = E;
    head[u] = edgenum++;
}
int a[N], K, mul[N];
int n, siz[N];
int s[N], id[N], top;
int  has[mod], has_id[mod], tim;
bool vis[N];
void add_hash(int u, int multi_ans){
    if(has[multi_ans] == tim)
        has_id[multi_ans] = min(has_id[multi_ans], u);
    else {
        has[multi_ans] = tim;
        has_id[multi_ans] = u;
    }
}
int wval, wroot;
void getroot(int u, int fa){
    siz[u] = 1;
    int maxv = 0;
    for(int i = head[u]; ~i; i = edge[i].nex){
        int v = edge[i].to; if(v == fa || vis[v])continue;
        getroot(v, u);
        siz[u] += siz[v];
        maxv = max(maxv, siz[v]);
    }
    maxv = max(maxv, siz[0] - siz[u]);
    if(maxv < wval)wval = maxv, wroot = u;
}
int find_root(int u, int fa){ //æ¾å°å­æ çéå¿
    wval = 1000000;
    getroot(u, fa);
    return wroot;
}

void multi(int u, int fa){
    mul[u] = ((ll)a[u]*(ll)mul[fa])%(ll)mod;
    siz[u] = 1;
    s[top] = mul[u];    id[top++] = u;
    for(int i = head[u];~i;i=edge[i].nex){
        int v = edge[i].to; if(v == fa || vis[v])continue;
        multi(v, u);
        siz[u] += siz[v];
    }
}
void solve(int u){
    tim++;
    mul[u] = 1;
    vis[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].nex){
        int v = edge[i].to; if(vis[v])continue;
        top = 0;
        multi(v, u);
        for(int i = 0; i < top; i++)
        {
            if(K == (ll)s[i]*(ll)a[u]%(ll)mod)
                updata(u, id[i]);
            int x = (ll)K * (ll)ni[ (ll)s[i] * (ll)a[u] % (ll)mod ] % (ll)mod;
            if(has[x] == tim)
                updata(id[i], has_id[x]);
        }
        for(int i = 0; i < top; i++)
        {
            add_hash(id[i], s[i]);
        }
    }
    for(int i = head[u];~i;i=edge[i].nex){
        int v = edge[i].to; if(vis[v])continue;
        siz[0] = siz[v];
        solve(find_root(v, u));
    }
}
void input(){
    init();
    for(int i = 1; i <= n; i++)rd(a[i]);
    for(int i = 1, u, v; i < n; i++)
    {
        rd(u); rd(v);
        add(u,v); add(v,u);
    }
}
int main() {
    tim = 0;
    memset(has, 0, sizeof has);
    for(int i = 0; i < mod; i++) quick(i);
    while(rd(n) && rd(K)) {
        input();
        ans.first = inf;
        memset(vis, 0, sizeof vis);
        siz[0] = n;
        solve(find_root(1,1));
        if(ans.first == inf)puts("No solution");
        else {
            pt(ans.first); putchar(' ');
            pt(ans.second); putchar('\n');
        }
    }
    return 0;
}
