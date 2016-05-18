#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 400;

class Graph
{
private:
 int mate[N];
 bool inQ[N], inBlo[N];
 queue< int > Q;
 int start, newBase, prev[N], base[N];
 int lca(int , int);
 void trace(int);
 void contract(int, int);
 bool search();
 void augment(int);
public:
 int n;
 bool g[N][N];
 bool init();
 int match();
};

int Graph::lca(int u, int v)
{
 bool path[N] = { false };
 while ( true)
 {
 u = base[u];
 path[u] = true;
 if ( u == start) break;
 u = prev[ mate[u] ];
 }
 while (true )
 {
 v = base[v];
 if ( path[v] ) break;
 v = prev[ mate[v] ];
 }
 return v;
}

void Graph::trace(int u)
{
 while ( base[u] != newBase )
 {
 int v = mate[u];
 inBlo[ base[u]] = inBlo[ base[v]] = true;
 u = prev[v];
 if ( base[u] != newBase ) prev[u] = v;
 }
}

void Graph::contract(int u, int v)
{
 newBase = lca( u, v );
 memset(inBlo, false, sizeof(inBlo));
 trace(u);
 trace(v);
 if ( base[u] != newBase) prev[u]= v;
 if ( base[v] != newBase ) prev[v] = u;
 for (int i = 0; i < n; ++i)
 {
 if ( inBlo[ base[i] ] )
 {
 base[i] = newBase;
 if ( !inQ[i] )
 {
 Q.push(i);
 inQ[i] = true;
 }
 }
 }
}

bool Graph::search()
{
 memset(inQ, false, sizeof(inQ));
 memset(prev, -1, sizeof(prev));
 for (int i = 0; i < n; ++i) base[i] = i;
 while ( !Q.empty() ) Q.pop();
 Q.push(start);
 inQ[start] = true;
 while ( !Q.empty() )
 {
 int u = Q.front() ;
 Q.pop();
 for (int i = 0; i < n; ++i)
 {
 if ( g[u][i] && base[u] != base[i] && mate[u] != i)
 {
 if ( i == start || (mate[i] >= 0 && prev[mate[i]] >= 0 )) contract(u, i);
 else if ( prev[i] < 0 )
 {
 prev[i] = u;
 if ( mate[i] != -1 )
 {
 Q.push(mate[i] );
 inQ[mate[i] ] = true;
 }
 else
 {
 augment(i);
 return true;
 }
 }
 }
 }
 }
 return false;
}

void Graph::augment(int u)
{
 while ( u >= 0 )
 {
 int v = prev[u], w = mate[v];
 mate[v] = u;
 mate[u] = v;
 u = w;
 }
}

int Graph::match()
{
 memset(mate, -1, sizeof(mate));
 int mth = 0;
 for (int i = 0; i < n; ++i)
 {
 if ( mate[i] >= 0 ) continue;
 start = i;
 if ( search() ) mth++;
 }
// printf("%d\n", mth * 2);
// bool vis[N] = {false};
// for (int i = 0; i < n; ++i)
// {
// if (!vis[i] && mate[i] >= 0 )
// {
// vis[i] = true;
// vis[mate[i] ] = true;
// printf("%d %d\n", i + 1, mate[i] + 1);
// }
// }

 return mth;
}

struct point
{
 int x, y;
 point() {};
 point (int a, int b) : x(a), y(b) {};
} q[N];

Graph net;
int n, m;
char state[20][20];
int sx, sy;

int dx[] = {-2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2};
int dy[] = {-2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2};

int map[20][20];
bool vis[20][20];
int main()
{
 int cases;
 scanf("%d", &cases);
 int step = 1;
 while ( cases-- )
 {
 scanf("%d %d", &n, &m);
 for (int i = 0; i < n; ++i) scanf("%s", state[i]);
 for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if ( state[i][j] == 'K' ) sx = i, sy = j, state[i][j] = '#';

 memset(net.g, false, sizeof(net.g));
 for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if ( state[i][j] == '.' )
 {
 for (int l = 0; l < 20; ++l)
 {
 int x = i + dx[l];
 int y = j + dy[l];
 if ( 0 <= x && x < n && 0 <= y && y < m && state[x][y] == '.' )
 {
 net.g[ x * m + y ][ i * m + j ] = net.g[ i * m + j ][ x * m + y ] = true;
 }
 }
 }
 net.n = n * m;

 int ans1 = net.match();

 for (int l = 0; l < 20; ++l)
 {
 int x = sx + dx[l];
 int y = sy + dy[l];
 if ( 0 <= x && x < n && 0 <= y && y < m && state[x][y] == '.' )
 {
 net.g[ x * m + y ][ sx * m + sy ] = net.g[ sx * m + sy ][ x * m + y ] = true;
 }
 }
 net.n++;

 int ans2 = net.match();

 printf("Case #%d: ", step++);
 if ( ans1 == ans2 )printf("daizhenyang lose\n");
 else printf("daizhenyang win\n");
 }
 return 0;
}