#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

#define MP(a,b) make_pair(a,b)
const int N = 10005;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int T, n;
typedef pair<int, int> pii;
map<pii, int> vi, vis;

int parent[N], sum[N], x[N], y[N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void init() {
    scanf("%d", &n);
    vi.clear();
    for (int i = 1; i <= n; i++) {
	parent[i] = i; sum[i] = 0;
	scanf("%d%d", &x[i], &y[i]);
    }
}

void del(int x, int y, int who) {
    queue<pii> Q;
    Q.push(MP(x, y));
    vis.clear();
    vis[MP(x,y)] = 1;
    while (!Q.empty()) {
	pii now = Q.front();
	parent[vi[now]] = vi[now];
	sum[vi[now]] = 0;
	vi.erase(now);
	Q.pop();
	for (int i = 0; i < 4; i++) {
	    int xx = now.first + d[i][0];
	    int yy = now.second + d[i][1];
	    if (xx <= 0 || yy <= 0 || vis[MP(xx,yy)]) continue;
	    int tmp = vi[MP(xx,yy)];
	    if ((tmp&1)^who == 0) {
		vis[MP(xx,yy)] = 1;
		Q.push(MP(xx, yy));
	    }
	    else {
		int pt = find(tmp);
		sum[pt]++;
	    }
	}
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
	vi[MP(x[i],y[i])] = i;
	int empty = 0;
	for (int j = 0; j < 4; j++) {
	    int xx = x[i] + d[j][0];
	    int yy = y[i] + d[j][1];
	    if (xx <= 0 || yy <= 0) continue;
	    if (vi.count(MP(xx,yy)) == 0) {
		empty++;
		continue;
	    }
	    int pv = find(vi[MP(xx,yy)]);
	    sum[pv]--;
	}
	sum[i] = empty;
	for (int j = 0; j < 4; j++) {
	    int xx = x[i] + d[j][0];
	    int yy = y[i] + d[j][1];
	    if (xx <= 0 || yy <= 0) continue;
	    if (vi.count(MP(xx,yy)) == 0) continue;
	    if (((vi[MP(xx,yy)]&1)^(i&1)) == 0) {
		int pa = find(i);
		int pb = find(vi[MP(xx,yy)]);
		if (pa != pb) {
		    parent[pa] = pb;
		    sum[pb] += sum[pa];
		}
	    }
	    else {
		int pv = find(vi[MP(xx,yy)]);
		if (sum[pv] == 0)
		    del(xx, yy, vi[MP(xx,yy)]&1);
	    }
	}
	int pv = find(i);
	if (sum[pv] == 0)
	    del(x[i], y[i], i&1);
    }
    int ansa = 0, ansb = 0;
    vis.clear();
    for (int i = n; i >= 1; i--) {
	if (vi.count(MP(x[i],y[i])) == 0 || vis[MP(x[i], y[i])]) continue;
	vis[MP(x[i],y[i])] = 1;
	if (vi[MP(x[i],y[i])]&1) ansa++;
	else {
	    ansb++;
	}
    }
    printf("%d %d\n", ansa, ansb);
}

int main() {
    scanf("%d", &T);
    while (T--) {
	init();
	solve();
    }
    return 0;
}