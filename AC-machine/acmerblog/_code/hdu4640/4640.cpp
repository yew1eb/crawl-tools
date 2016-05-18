#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <cstdio>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f

int n, m, cnt;
int head[17], next[17 * 17 * 2 + 3][3], dp[1 << 17][17], dis[1 << 17], num[1 << 17];

void add (int u, int v, int w)
{
	next[cnt][1] = v;
	next[cnt][2] = w;
	next[cnt][0] = head[u];
	head[u] = cnt++;
}

void bfs ()
{
	queue<pair<int, int> > q;
	q.push(make_pair(0, 1));
	dp[1][0] = 0;
	while (!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int su = p.second;
		int u = p.first;
		for (int i = head[u]; i != -1; i = next[i][0]){
			int v = next[i][1];
			int w = next[i][2];
			int sv = su|(1 << v);
			if(dp[sv][v] > dp[su][u] + w){
				dp[sv][v] = dp[su][u] + w;
				q.push(make_pair(v, sv));
			}
		}
	}
}

int main ()
{
	//freopen ("in.txt", "r", stdin);
	int t, count = 0;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d %d", &n, &m);
		int u, v, w;
		for (int i = 0; i < n; ++i) head[i] = -1;
		for (int i = (1 << n) - 1; i >= 0; --i){
			dis[i] = inf;
			num[i] = inf;
			for (int j = 0; j < n; ++j) dp[i][j] = inf;
		}
		cnt = 0;
		for (int i = 0; i < m; ++i){
			scanf ("%d %d %d", &u, &v, &w);
			add (u - 1, v - 1, w);
			add (v - 1, u - 1, w);
		}
		scanf ("%d", &m);
		v = 0;
		for (int i = 0; i < m; ++i){
			scanf ("%d", &u);
			v |= (1 << (u - 1));
		}
		v >>= 1;
		if (!m || (m == 1 && u == 1)){
			printf("Case %d: 0\n", ++count);
			continue;
		}
		bfs ();
		u = inf;
		w = (1 << (n-1)) - 1;
		for(int i = 1; i < (1 << n); ++i)
			for(int j = 0; j < n; ++j) 
				dis[i >> 1] = min(dis[i >> 1], dp[i][j]);		
		for (int i = 1; i <= w; ++i)
			for (int j = i; j; j = (j - 1) & i)
				num[i] = min(num[i], max(dis[j], dis[i ^ j]));
		for (int i = 1; i <= w; ++i)
			for(int j = i; j; j = (j - 1) & i)
			if((i & v) == v) u = min(u, max(num[j], dis[i ^ j]));
		if (u == inf) u = -1;
		printf("Case %d: %d\n", ++count, u);
	}
	return 0;
}