#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 2005
int n , m , pre[N] , mcnt , f[N] , dep[N];
struct edge
{
  int x , f , next;
}e[40005];
pair<int , int> a[20005];
bool vis[N];
void dfs(int x , int fa)
{
  f[x] = fa , dep[x] = dep[fa] + 1 , vis[x] = 1;
  for (int i = pre[x] ; ~i ;i = e[i].next)
    if (!vis[e[i].x])
      e[i].f = e[i ^ 1].f = 1 , dfs(e[i].x , x);
}

bool cmp(pair<int , int> x, pair<int , int> y)
{
  if (dep[x.se] == dep[y.se])
    return dep[x.fi] > dep[y.fi];
  return dep[x.se] > dep[y.se];
}

void work()
{
  int i , j , x , y , ans = 0;

  memset(pre , -1 , sizeof(pre));
  mcnt = 0;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d",&x,&y);
    a[i] = make_pair(x , y);
  }
  for (i = m ; i > 0 ; -- i)
  {
    x = a[i].fi , y = a[i].se;
    e[mcnt] = (edge) {y , 0 , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge) {x , 0 , pre[y]} , pre[y] = mcnt ++;
  }
  memset(vis , 0 , sizeof(vis));
  dfs(1 , 0);
  m = 0;
  for (x = 1 ; x <= n ; ++ x)
    for (i = pre[x] ; ~i ; i = e[i].next)
      if ((i & 1) && !e[i].f)
      {
        y = e[i].x;
        a[++ m] = make_pair(x , y);
        if (dep[a[m].fi] < dep[a[m].se])
          swap(a[m].fi , a[m].se);
      }
  sort(a + 1 , a + m + 1 , cmp);
  memset(vis , 0 , sizeof(vis));
  for (i = 1 ; i <= m ; ++ i)
  {
    x = a[i].fi , y = a[i].se;
    //cout << x <<' '<< y << endl;
    while (f[x] != y)
      if (vis[x])
        break;
      else x = f[x];
    if (!vis[x])
      vis[x] = 1 , ++ ans;
  }
  printf("%d\n" , ans);
}

int main()
{
  while (scanf("%d%d",&n,&m) , n || m)
    work();
  return 0;
}