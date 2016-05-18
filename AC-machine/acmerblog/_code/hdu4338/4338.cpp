#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#define Set(a) (memset(a, 0, sizeof(a)))

using namespace std;

typedef pair<int, int> Pair;
const int MAXN=100005, MAXLOG=20;

int n, dfn[MAXN], low[MAXN], bccno[MAXN];
bool cut[MAXN];
vector<Pair> S;

int sz[MAXN*2], ssz[MAXN*2], conno[MAXN*2], fa[MAXN*2][MAXLOG], Deep[MAXN*2];
bool vis[MAXN*2];

struct NewGraph {
	int n;
	vector<int> E[MAXN*2];
	void AddEdge(int x, int y)
	{
		E[x].push_back(y);
		E[y].push_back(x);
	}
	void BFS(int start, int ncon)
	{
		static int q[MAXN*2];
		int l, r, x, y, i;
		q[l=r=1] = start;
		while (l <= r) {
			x = q[l++];
			conno[x] = ncon;
			ssz[x] = sz[x]+ssz[fa[x][0]];
			Deep[x] = Deep[fa[x][0]]+1;
			for (i=0; i<E[x].size(); i++) {
				y = E[x][i];
				if (y==fa[x][0]) continue;
				fa[y][0] = x;
				q[++r] = y;
			}
		}
	}
	void Work()
	{
		int i, j, ncon=0;
		Set(vis), Set(fa), Set(conno);
		for (i=1; i<=n; i++)
			if (!conno[i])
				BFS(i, ++ncon);
		for (j=1; j<MAXLOG; j++)
			for (i=1; i<=n; i++)
				fa[i][j] = fa[fa[i][j-1]][j-1];
	}
	int LCA(int x, int y)
	{
		int j;
		if (Deep[x] < Deep[y])
			swap(x, y);
		for (j=MAXLOG-1; j>=0; j--)
			if (Deep[x]-(1<<j) >= Deep[y])
				x = fa[x][j];
		if (x == y)
			return x;
		for (j=MAXLOG-1; j>=0; j--)
			if (fa[x][j] != fa[y][j])
				x=fa[x][j], y=fa[y][j];
		return fa[x][0];
	}
	int Query(int x, int y, bool cut1, bool cut2)
	{
		if (!x || !y || conno[x]!=conno[y])
			return ::n;
		int lca=LCA(x,y), num=ssz[x]+ssz[y]-(ssz[lca]<<1)+sz[lca]+cut1+cut2;
		return ::n-num;
	}
};

struct Rec {
	int i, x, y, fa;
	bool flag;
};

struct Solver {
	int ndfn, nbcc;
	vector<int> E[MAXN], bcc[MAXN];
	void Init()
	{
		ndfn = nbcc = 0;
		Set(dfn), Set(bccno), Set(cut);
		int m, x, y;
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d", &x, &y);
			E[x].push_back(y);
			E[y].push_back(x);
		}
	}
	void DFS(int start)
	{
		static Rec stk[MAXN];
		int top, x, y, u, v, rtson=0;
		stk[top=1].i=-1, stk[1].x=start, stk[1].y=stk[1].fa=-1, stk[1].flag=false;
		while (top) {
			x = stk[top].x;
			if (stk[top].i == -1) {
				dfn[x] = low[x] = ++ndfn;
				stk[top].i = 0;
			}
			for (int &i=stk[top].i; i<E[x].size(); ++i) {
				if (stk[top].y != -1) {
					y = stk[top].y;
					low[x] = min(low[x], low[y]);
					if (low[y] >= dfn[x]) {
						cut[x] = true;
						++nbcc;
						do {
							u=S.back().first, v=S.back().second;
							if (bccno[u] != nbcc)
								bcc[nbcc].push_back(u);
							if (bccno[v] != nbcc)
								bcc[nbcc].push_back(v);
							bccno[u] = bccno[v] = nbcc;
							S.pop_back();
						} while (u!=x || v!=y);
					}
					stk[top].y = -1;
					continue;
				}
				y = E[x][i];
				if (y==stk[top].fa && !stk[top].flag) {
					stk[top].flag = true;
					continue;
				}
				if (!dfn[y]) {
					S.push_back(Pair(x, y));
					if (stk[top].fa == -1)
						rtson++;
					stk[top].y = y;
					stk[++top].i=-1, stk[top].x=y, stk[top].y=-1, stk[top].fa=x, stk[top].flag=false;
					break;
				}
				if (dfn[y] < dfn[x]) {
					S.push_back(Pair(x, y));
					low[x] = min(low[x], dfn[y]);
				}
			}
			if (stk[top].x == x)
				top--;
		}
		cut[start] = (rtson>1);
	}
	void Work()
	{
		static int newno[MAXN];
		int i, q, x, y;
		for (i=0; i<n; i++)
			if (!dfn[i])
				DFS(i);
		NewGraph *a=new NewGraph;
		a->n=0, Set(newno);
		for (i=0; i<n; i++)
			if (cut[i]) {
				newno[i] = ++(a->n);
				sz[newno[i]] = -1;
			}
		for (x=1; x<=nbcc; x++) {
			sz[++(a->n)] = bcc[x].size();
			for (i=0; i<bcc[x].size(); i++) {
				y = bcc[x][i];
				if (cut[y])
					a->AddEdge(newno[y], a->n);
				else
					newno[y] = a->n;
			}
		}
		a->Work();
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &x, &y);
			printf("%d\n", (x==y ? n-1 : a->Query(newno[x],newno[y], cut[x], cut[y])));
		}
	}
};

int main()
{
	///freopen("out.txt", "w", stdout);
	for (int cas=1; scanf("%d",&n)==1; cas++) {
		Solver *a=new Solver;
		a->Init();
		printf("Case #%d:\n", cas);
		a->Work();
		putchar('\n');
	}
	return 0;
}