#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define lson step << 1
#define rson step << 1 | 1
#pragma comment(linker,"/STACK:100000000,100000000")
using namespace std;
typedef long long LL;
const int N = 200005;
const LL MOD = 1000000007LL;
const LL HASH = 26LL;
struct Edge {
    int v , next , ch ;
}e[N << 1];
struct Trie {
    Trie *next[26];
    vector <int> v;
    void init () {
        v.clear();
        memset (next , 0 , sizeof(next));
    }
}s[N];
struct Question {
    int u , d , id;
    void input (int _i) {
        scanf ("%d %d" , &u , &d);
        id = _i;
    }
}question[N];
struct Seg_tree {
    int left , right;
    int maxrank;
    LL hash;
}L[N << 2];
vector<Question>askondep[N];
int n , start[N] , tot , idx;
LL hash[N] , fac[N] = {1};
int ans[N];
void _add (int u , int v , int c) {
    e[tot].v = v;
    e[tot].ch = c;
    e[tot].next = start[u];
    start[u] = tot ++;
}
void add (int u , int v , int c) {
    _add (u , v , c);
    _add (v , u , c);
}
Trie *NewNode () {
    Trie *t = &s[idx ++];
    t->init();
    return t;
}
void bulidtrie (Trie *p , int u , int pre , LL h) {
    p -> v.push_back (u);
    hash[u] = h;
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v , ch = e[i].ch;
        if (v == pre) continue;
        if (p -> next[ch] == NULL) p -> next[ch] = NewNode ();
        bulidtrie (p -> next[ch] , v , u , (h * HASH + ch) % MOD);
    }
}
int nowrank , rank[N];
void getrank (Trie *p ) {
    for (int i = 0 ; i < p -> v.size() ; i ++) {
        rank[p -> v[i]] = nowrank;
    }
    for (int i = 0 ; i < 26 ; i ++) {
        if (p -> next[i] != NULL) {
            nowrank ++;
            getrank (p -> next[i]);
        }
    }
}
vector<int> ondepth[N];
int depth[N] , id[N] , left_id[N] , right_id[N] , id_cnt , maxdep , mapping[N];
void caldepth (int u , int pre , int dep) {
    depth[u] = dep;
    id[u] = ++id_cnt;
    mapping[id_cnt] = u;
    left_id[u] = id_cnt + 1;
    ondepth[dep].push_back (id_cnt);
    maxdep = max (maxdep , dep);
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (v == pre) continue;
        caldepth (v , u , dep + 1);
    }
    right_id[u] = id_cnt;
}
void push_up (int step) {
    if (L[lson].maxrank > L[rson].maxrank) {
        L[step].maxrank = L[lson].maxrank;
        L[step].hash = L[lson].hash;
    }
    else {
        L[step].maxrank = L[rson].maxrank;
        L[step].hash = L[rson].hash;
    }
}
void bulid (int step , int l , int r , int d) {
    L[step].left = l;
    L[step].right = r;
    if (l == r) {
        L[step].maxrank = rank[mapping[ondepth[d][l]]];
        L[step].hash = hash[mapping[ondepth[d][l]]];
        return ;
    }
    int m = (l + r) >> 1;
    bulid (lson , l , m , d);
    bulid (rson , m + 1 , r , d);
    push_up (step);
}
pair<int , LL> query (int step , int l , int r) {
    if (l < L[step].left || r > L[step].right || l > r) return make_pair(-1 , -1);
    if (L[step].left == l && L[step].right == r) {
        return make_pair (L[step].maxrank , L[step].hash);
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query (lson , l , r);
    else if (l > m) return query (rson , l , r);
    else {
        pair<int , int> u = query (lson , l , m);
        pair<int , int> v = query (rson , m + 1 , r);
        if (u.first > v.first) return u;
        return  v;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        freopen ("output.txt" , "w" , stdout);
    #endif
    for (int i = 1 ; i < N ; i ++)
        fac[i] = (fac[i - 1] * 26LL) % MOD;
    int t , out = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = 0;idx = 0;
        memset (start , -1 , sizeof(start));
        scanf ("%d" , &n);
        for (int i = 1 ; i < n ; i ++) {
            int u , v ; char str[5];
            scanf ("%d %d %s" , &u , &v , str);
            add (u , v , str[0] - 'a');
        }
        Trie *root = NewNode ();
        bulidtrie (root , 1 , -1 , 0LL);
        nowrank = 0;
        getrank (root);
        id_cnt = 0;maxdep = 1;
        caldepth (1 , -1 , 1);
        int q;
        scanf ("%d" , &q);
        for (int i = 0 ; i < q ; i ++) {
            question[i].input(i);
            if (question[i].d == 0) ans[i] = 0;
            else if (depth[question[i].u] + question[i].d <= maxdep)
                askondep[depth[question[i].u] + question[i].d].push_back (question[i]);
            else  ans[i] = -1;
        }
        for (int dep = 1 ; dep <= maxdep ; dep ++) {
            if (askondep[dep].size () == 0) continue;
            int m = ondepth[dep].size() - 1;
            bulid (1 , 0 , m , dep);
            for (int i = 0 ; i < askondep[dep].size() ; i ++) {
                int u = askondep[dep][i].u , d = askondep[dep][i].d , id = askondep[dep][i].id;
                int l = left_id[u] , r = right_id[u];
                l = lower_bound (ondepth[dep].begin () , ondepth[dep].end () , l) - ondepth[dep].begin ();
                r = upper_bound (ondepth[dep].begin () , ondepth[dep].end () , r) - ondepth[dep].begin () - 1;   
                pair<int , LL> ret = query (1 , l , r);
                if (ret.second == -1) ans[id] = -1;
                else ans[id] = ((ret.second - (LL)hash[u] * fac[d]) % MOD + MOD) % MOD;
            }
        }
        for (int i = 0 ; i < q ; i ++) {
            if (ans[i] == -1) puts ("IMPOSSIBLE");
            else printf("%d\n" , ans[i]);
        }
        for (int i = 1 ; i <= maxdep ; i ++) {
            ondepth[i].clear();
            askondep[i].clear();
        }
    }
    return 0;
}