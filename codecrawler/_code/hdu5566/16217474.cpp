#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int N = 26;
const int maxn = 100008;

int n, p[maxn], fp[maxn]; 

inline void mymax(int &x, int y){
    if(y > x) x = y;
}

struct tire{
    int nxt[N + 2], fail, is, len;
    void init(){
        memset(nxt, 0, sizeof(nxt));
        fail = is = len = 0;
    }
};

struct act{
    tire t[maxn];
    int root = 0, all;

    void init(){
        t[all = 0].init();
    }
    void insert(string s){
        int now = 0;

        for(int i = 0; i < (int)s.length(); i++){
            int cc = s[i] - 'a';
            if(!t[now].nxt[cc]){
                t[now].nxt[cc] = ++all;
                t[all].init();
            }
            now = t[now].nxt[cc];
        }
        t[now].is = 1;
        t[now].len = s.length();
    }
    void build(){
        int now = 0;
        queue<int> q;

        for(int i = 0; i < N; i++){
            if(!t[now].nxt[i]) continue;
            else{
                t[t[now].nxt[i]].fail = 0;
                q.push(t[now].nxt[i]);
            }
        }
        while(!q.empty()){
            now = q.front();
            q.pop();
            for(int i = 0; i < N; i++){
                if(!t[now].nxt[i]){
                    t[now].nxt[i] = t[t[now].fail].nxt[i];
                }
                else{
                    t[t[now].nxt[i]].fail = t[t[now].fail].nxt[i];
                    mymax(t[t[now].nxt[i]].len, t[t[t[now].nxt[i]].fail].len);
                    q.push(t[now].nxt[i]);
                }
            }
        }
    }
    int run(string s){
        int res = 0, now = 0;

        for(int i = 0; i < (int)s.length(); i++){
            int cc = s[i] - 'a';
            now = t[now].nxt[cc];
            mymax(res, t[now].len);
        }

        return res;
    }
}ac;

string s[maxn], ans[maxn];
int res[maxn];

struct segtree{
    vector<int> v[maxn << 2];

    void init(int pos, int l, int r){
        v[pos].clear();
        if(l == r) return ;
        int mid = (l + r) >> 1;
        init(pos << 1, l, mid);
        init(pos << 1 | 1, mid + 1, r);
    }
    void query(int pos, int l, int r, int tl, int tr, int vv){
        if(tl <= l && r <= tr){
            v[pos].push_back(vv);
            return ;
        }
        int mid = (l + r) >> 1;
        if(tr <= mid){
            query(pos << 1, l, mid, tl, tr, vv);
        }
        else if(tl > mid){
            query(pos << 1 | 1, mid + 1, r, tl, tr, vv);
        }
        else{
            query(pos << 1, l, mid, tl, mid, vv);
            query(pos << 1 | 1, mid + 1, r, mid + 1, tr, vv);
        }
    }
    void getans(int pos, int l, int r){
        if(v[pos].size()){
            //printf("pos  %d   %d   %d\n", pos, l, r);
            ac.init();
            for(int i = l; i <= r; i++){
                ac.insert(s[fp[i]]);
            }
            ac.build();
            for(int i = 0; i < (int)v[pos].size(); i++){
                mymax(res[v[pos][i]], ac.run(ans[v[pos][i]]));
            }
        }
        if(l == r) return ;
        int mid = (l + r) >> 1;
        getans(pos << 1, l, mid);
        getans(pos << 1 | 1, mid + 1, r);
    }
}st;

struct edge{
    int to, nxt;
};

struct slpf{
    edge e[maxn << 2];
    int head[maxn], top[maxn], fa[maxn];
    int deep[maxn], num[maxn];
    int son[maxn], tot, pos, root;

    void init(){
        tot = 0;
        memset(head, -1, sizeof(head));
        pos = 1;
        memset(son, -1, sizeof(son));
    }
    void addedge(int u, int v){
        e[tot].to = v;
        e[tot].nxt = head[u];
        head[u] = tot++;
    }
    void dfs1(int u, int pre, int d){
        deep[u] = d;
        fa[u] = pre;
        num[u] = 1;
        for(int i = head[u]; i != -1; i = e[i].nxt){
            int v = e[i].to;
            if(v != pre){
                dfs1(v, u, d + 1);
                num[u] += num[v];
                if(son[u] == -1 || num[v] > num[son[u]])
                    son[u] = v;
            }
        }
    }
    void getpos(int u, int sp){
        top[u] = sp;
        p[u] = pos++;
        fp[p[u]] = u;
        if(son[u] == -1) return ;
        getpos(son[u], sp);
        for(int i = head[u]; i != -1; i = e[i].nxt){
            int v = e[i].to;
            if(v != son[u] && v != fa[u])
                getpos(v, v);
        }
    }
    void build(){
        dfs1(1, 0, 0);
        getpos(1, 1);
    }
    void query(int u, int v, int vv){
        int f1 = top[u], f2 = top[v];

        while(f1 != f2){
            if(deep[f1] < deep[f2]){
                swap(f1, f2);
                swap(u, v);
            }
            st.query(1, 1, n, p[f1], p[u], vv);
            //printf("query   %d   %d\n", p[f1], p[u]);
            u = fa[f1];
            f1 = top[u];
        }
        if(deep[u] > deep[v]) swap(u, v);
        st.query(1, 1, n, p[u], p[v], vv);
    }
}spt;

int main(){
    int _, x, y, m;

    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin >> _;
    while(_--){
        cin >> n;
        st.init(1, 1, n);
        spt.init();
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
        for(int i = 1; i < n; i++){
            cin >> x;
            spt.addedge(i + 1, x);
            spt.addedge(x, i + 1);
        }
        spt.build();
        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> x >> y >> ans[i];
            spt.query(x, y, i);
        }
        memset(res, 0, sizeof(res));
        st.getans(1, 1, n);
        for(int i = 1; i <= m; i++){
            cout << res[i] << endl;
        }
    }

    return 0;
}
