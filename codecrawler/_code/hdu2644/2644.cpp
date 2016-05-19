#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 121111
#define M 600000
#define inf 0x7fffffff
char map[20][20];

struct node {
	int to, next, c;
} edge[M];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int edgehead[N], now[N], dis[N];
int que[M];
int n, m, s, t, cnt, d, w;
int door, pos;

struct node2 {
	int x, y;
} p[800], q[800];

void addedge(int u, int v, int c) {
	edge[cnt].to = v, edge[cnt].c = c, edge[cnt].next = edgehead[u];
	edgehead[u] = cnt++;
	edge[cnt].to = u, edge[cnt].c = 0, edge[cnt].next = edgehead[v];
	edgehead[v] = cnt++;
}

void init() {
	memset(edgehead, -1, sizeof (edgehead));
	cnt = 0;
}

bool find_path(int s, int t) {
	for (int i = 0; i <= t; i++) {
		dis[i] = inf;
		now[i] = -1;
	}
	int head = 0, tail = 1;
	que[head] = s;
	dis[s] = 0;
	while (head <= tail) {
		int cur = que[head++];
		if (dis[t] <= dis[cur])break;
		for (int i = edgehead[cur]; i != -1; i = edge[i].next)if (edge[i].c > 0) {
				int v = edge[i].to;
				if (now[cur] == -1)
					now[cur] = i;
				if (dis[v] == inf) {
					dis[v] = dis[cur] + 1;
					que[tail++] = v;
				}
			}
	}
	return dis[t] != inf;
}

int dfs(int s, int t, int nowflow) {
	if (s == t) return nowflow;
	int flow = 0;
	int i;
	for (i = now[s]; i != -1; i = edge[i].next)if (edge[i].c > 0 && dis[edge[i].to] == dis[s] + 1) {
			int temp = dfs(edge[i].to, t, min(nowflow - flow, edge[i].c));
			edge[i].c -= temp;
			edge[i^1].c += temp;
			flow += temp;
			if (flow == nowflow)
				break;
		}
	now[s] = i;
	return flow;
}

int maxflow(int s, int t) {
	int flow = 0;
	while (find_path(s, t))flow += dfs(s, t, inf);
	return flow;
}

int getid(int x, int y) {
	return (x - 1)*m + y;
}

int getid1(int num, int time) {
	return n * m * time * 2 + 2 * num - 1;
}

int getid2(int num, int time) {
	return (n * m)*time * 2 + 2 * num;
}

bool isok(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] != '#')
		return 1;
	return 0;
}

void build(int mid) {
	s = 0, t = 2 * (n * m)*(mid + 5) + 5;
	for (int i = 1; i <= pos; i++) {
		int id = getid(q[i].x, q[i].y);
		int id1 = getid1(id, 0);
		addedge(s, id1, 1);
	}
	for (int i = 1; i <= door; i++)
		for (int time = 0; time <=mid; time++) {
			int id = getid(p[i].x, p[i].y);
			int id2 = getid2(id, time);
			addedge(id2, t, 1);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != '#')
				for (int time = 0; time <= mid; time++) {
					int id = getid(i, j);
					int id1 = getid1(id, time);
					int id2 = getid2(id, time);
					addedge(id1, id2, 1);
				}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != '#')
				for (int de = 0; de < 4; de++) {
					int newx = i + dx[de];
					int newy = j + dy[de];
					if (isok(newx, newy)) {
						for (int time = 0; time < mid; time++) {
							int id = getid(i, j);
							int id1 = getid(newx, newy);
							int id3 = getid2(id, time);
							int id4 = getid1(id1, time + 1);
							int id5=getid1(id,time+1);
							addedge(id3, id4, inf);
							addedge(id3,id5,inf);
						}
					}
				}
		}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++)
			scanf("%s", &map[i][1]);
		door = 1, pos = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '@') {
					p[door].x = i;
					p[door].y = j;
					door++;
				}
				if (map[i][j] == 'X') {
					q[pos].x = i;
					q[pos].y = j;
					pos++;
				}
			}
		door--, pos--;
		int l = 1, r = n*m+1, ans = -1;
		while (l <= r) {
			init();
			int mid = (l + r) / 2;
			build(mid);
			int cur = maxflow(s, t);
			if (cur == pos) {
				r = mid - 1;
				ans = mid;
			}
			else
				l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}