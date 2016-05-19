#include <stdio.h>
#include <string.h>

#define MAXN 20
#define MAXM 2000

struct Edge{
 int u, v;
}edge[MAXM];

int n, m, cnt, fa[MAXN], d1[MAXM], d2[MAXM];
bool used[MAXN];
bool solved;

int findset(int u){
 int v = fa[u];
 while(u != fa[u]) u = fa[u];
 while(fa[v] != u){
 int t = fa[v];
 fa[v] = u;
 t = v;
 }
 return u;
}

bool check1(){
 for(int i = 0; i < n; ++i) fa[i] = i;
 for(int i = 0; i < cnt; ++i){
 int x = findset(d1[i]), y = findset(d2[i]);
 if(x == y) return false;
 fa[y] = x;
 }
 return true;
}

bool check2(){
 for(int i = 0; i < n; ++i) fa[i] = i;
 int total = 1;
 for(int i = 0; i < m && total < n; ++i){
 if(used[i]) continue;
 int x = findset(edge[i].u), y = findset(edge[i].v);
 if(x != y){
 fa[y] = x;
 ++total;
 }
 }
 return total == n;
}

void dfs(int level){
 if(cnt == n - 1){
 if(check2()) solved = true;
 return;
 }
 if(m - level - 1 + cnt >= n - 1 && !solved) dfs(level + 1);
 d1[cnt] = edge[level].u, d2[cnt++] = edge[level].v;
 used[level] = true;
 if(!solved && check1())
 dfs(level + 1);
 used[level] = false;
 --cnt;
}

int main(){
 while(scanf("%d%d", &n, &m), n != -1){
 cnt = 0;
 solved = false;
 memset(used, false, sizeof(used));
 for(int i = 0; i < m; ++i) scanf("%d%d", &edge[i].u, &edge[i].v);
 dfs(0);
 if(solved) puts("YES");
 else puts("NO");
 }
 return 0;
}