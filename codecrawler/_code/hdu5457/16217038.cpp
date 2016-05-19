#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;

#define REP( i, a, b ) for( int i = a; i < b; i++ )
#define FOR( i, a, b ) for( int i = a; i <= b; i++ )
#define CLR( a, x ) memset( a, x, sizeof a )
#define CPY( a, x ) memcpy( a, x, sizeof a )

const int maxn = 1200 + 10;
const int maxe = 3000 + 10;
const int INF = 1e6;

struct Edge{
  int v, c, f;
  int next;
  Edge() {}
  Edge(int v, int c, int f, int next) : v(v), c(c), f(f), next(next) {}
};

struct ISAP{
  int n, s, t;
  int num[maxn], cur[maxn], d[maxn], p[maxn];
  int Head[maxn], cntE;
  int Q[maxn], head, tail;
  Edge edge[maxe];
  void Init(int n){
    this -> n = n;
    CLR(Head, -1);
    cntE = 0;
  }
  void Add(int u, int v, int c){
    edge[cntE] = Edge(v, c, 0, Head[u]);
    Head[u] = cntE++;
    edge[cntE] = Edge(u, 0, 0, Head[v]);
    Head[v] = cntE++;
  }
  void Bfs(){
    CLR(d, -1);
    CLR(num, 0);
    d[t] = 0;
    head = tail = 0;
    Q[tail++] = t;
    num[0] = 1;
    while(head != tail){
      int u = Q[head++];
      for(int i = Head[u]; ~i; i = edge[i].next){
        Edge &e = edge[i];
        if(~d[e.v]) continue;
        d[e.v] = d[u] + 1;
        Q[tail++] = e.v;
        num[d[e.v]]++;
      }
    }
  }
  int Maxflow(int s, int t){
    this -> s = s;
    this -> t = t;
    CPY(cur, Head);
    Bfs();
    int flow = 0, u = p[s] = s;
    while(d[s] < n){
      if(u == t){
        int f = INF, neck;
        for(int i = s; i != t; i = edge[cur[i]].v){
          if(f > edge[cur[i]].c - edge[cur[i]].f){
            f = edge[cur[i]].c - edge[cur[i]].f;
            neck = i;
          }
        }
        for(int i = s; i != t; i = edge[cur[i]].v){
          edge[cur[i]].f += f;
          edge[cur[i]^1].f -= f;
        }
        flow += f;
        u = neck;
      }
      int ok = 0;
      for(int i = cur[u]; ~i; i = edge[i].next){
        Edge &e = edge[i];
        if(e.c > e.f && d[e.v] + 1 == d[u]){
          ok = 1;
          cur[u] = i;
          p[e.v] = u;
          u = e.v;
          break;
        }
      }
      if(!ok){
        int m = n - 1;
        if(--num[d[u]] == 0) break;
        for(int i = Head[u]; ~i; i = edge[i].next){
          Edge &e = edge[i];
          if(e.c > e.f && m > d[e.v]){
            cur[u] = i;
            m = d[e.v];
          }
        }
        ++num[d[u] = m + 1];
        u = p[u];
      }
    }
    return flow;
  }
}solver;

struct Trie{
    int va;
    Trie *next[2];
    Trie(){
        va = INF;
        next[0] = next[1] = NULL;
    }
};

int n, m, nu[300];
map<string, int> ma[2];
string bi_str;
int node;
int S, T;

void build_trie(Trie *root, char *bi){
    Trie *p = root;
    for(int i = 0; i < 8; i++){
        int va = bi[i] - '0';
        if(p -> next[va] == NULL){
            Trie *q = new Trie;
            p -> next[va] = q;
        }
        p = p -> next[va];
    }
}

void build_prefix_suffix(char *str, int val, Trie *root){
    int len = strlen(str);
    Trie *p = root;
    for(int i = 0; i < len; i++){
        int va = str[i] - '0';
        if(p -> next[va] == NULL) return;
        p = p -> next[va];
    }
    p -> va = min(val, p -> va);
}

void trans(char *str){
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++)
        swap(str[i], str[len-i-1]);
}

void trans_bi(char *bi, int x){
    for(int i = 7; i >= 0; i--){
        bi[i] = (x % 2) + '0';
        x /= 2;
    }
    bi[8] = '\0';
}

void build_graph(Trie *root, int u, int ind, int add){
    Trie *p = root;
    for(int i = 0; i < 2; i++)if(p -> next[i] != NULL){
        bi_str += i + '0';
        ma[ind][bi_str] = node;
        int v = node++;
        if(ind == 0)
            solver.Add(u + add, v + add, p -> next[i] -> va);
        else
            solver.Add(v + add, u + add, p -> next[i] -> va);
        build_graph(p -> next[i], v, ind, add);
        bi_str.erase(bi_str.end()-1);
    }
}

void Union(){
    char str1[10], str2[10];
    for(int i = 0; i < n; i++){
        trans_bi(str1, nu[i]);
        trans_bi(str2, nu[i]);
        trans(str2);
        string s1("S"); s1 += string(str1, str1 + 8);
        string s2("T"); s2 += string(str2, str2 + 8);
        solver.Add(ma[0][s1], ma[1][s2] + 520, INF);
    }
}
void delete_Trie(Trie *root){
    if(root == NULL) return;
    delete_Trie(root -> next[0]);
    delete_Trie(root -> next[1]);
    delete []root;
}
int cas = 0;
void solve(){
    Trie *s = new Trie, *t = new Trie;
    scanf("%d%d",&n, &m);
    ma[0].clear(); ma[1].clear();
    S = T = 0;
    solver.Init(maxn-10);
    for(int i = 0; i < n; i++){
        char bi[10];
        scanf("%d", &nu[i]);
        trans_bi(bi, nu[i]);
        build_trie(s, bi);
        trans(bi);
        build_trie(t, bi);
    }
    for(int i = 0; i < m; i++){
        char str[10];
        int va;
        scanf("%s", str);
        if(str[0] == 'P'){
            scanf("%s%d", str, &va);
            build_prefix_suffix(str, va, s);
        }
        else{
            scanf("%s%d", str, &va);
            trans(str);
            build_prefix_suffix(str, va, t);
        }
    }
    bi_str.clear(); bi_str += 'S'; node = 1;
    build_graph(s, S, 0, 0);
    bi_str.clear(); bi_str += 'T'; node = 1;
    build_graph(t, T, 1, 520);
    Union();
    int ans = solver.Maxflow(S, T+520);
    printf("Case #%d: ", ++cas);
    if(ans >= INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
    delete_Trie(s); delete_Trie(t);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}

