#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXNODE = 505;

typedef int Type;
const Type INF = 0x3f3f3f3f;

struct KM {
	int n, m;
	Type g[MAXNODE][MAXNODE];
	Type Lx[MAXNODE], Ly[MAXNODE], slack[MAXNODE];
	int left[MAXNODE], right[MAXNODE];
	bool S[MAXNODE], T[MAXNODE];

	void init(int n, int m) {
		this->n = n;
		this->m = m;
		memset(g, 0, sizeof(g));
	}

	void add_Edge(int u, int v, Type val) {
		g[u][v] += val;
	}

	bool dfs(int i) {
		S[i] = true;
		for (int j = 0; j < m; j++) {
			if (T[j]) continue;
			Type tmp = Lx[i] + Ly[j] - g[i][j];
			if (!tmp) {
				T[j] = true;
				if (left[j] == -1 || dfs(left[j])) {
					left[j] = i;
					right[i] = j;
					return true;
				}
			} else slack[j] = min(slack[j], tmp);
		}
		return false;
	}

	void update() {
		Type a = INF;
		for (int i = 0; i < m; i++)
			if (!T[i]) a = min(a, slack[i]);
		for (int i = 0; i < n; i++)
			if (S[i]) Lx[i] -= a;
		for (int i = 0; i < m; i++)
			if (T[i]) Ly[i] += a;
	}

	Type km() {
		memset(left, -1, sizeof(left));
		memset(right, -1, sizeof(right));
		memset(Ly, 0, sizeof(Ly));
		for (int i = 0; i < n; i++) {
			Lx[i] = -INF;
			for (int j = 0; j < m; j++)
				Lx[i] = max(Lx[i], g[i][j]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) slack[j] = INF;
			while (1) {
				memset(S, false, sizeof(S));
				memset(T, false, sizeof(T));
				if (dfs(i)) break;
				else update();
			}
		}
		Type ans = 0;
		for (int i = 0; i < n; i++) {
			//if (right[i] == -1) return -1;
			//if (g[i][right[i]] == -INF) return -1;
			ans += g[i][right[i]];
		}
		return -ans;
	}
} gao;

int t, n, m;

int main() {
	int cas = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		gao.init(n, n);
		int tmp;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &tmp);
				for (int k = 0; k < n; k++)
					gao.add_Edge(k, j, -abs(tmp - k - 1));
			}
		}
		printf("Case #%d: %d\n", ++cas, gao.km());
	}
	return 0;
}