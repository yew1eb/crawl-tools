#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=int(a);i<b____;++i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define DO(n) while(n--)
#define DO_C(n) int n____ = n; while(n____--)

template<class T> inline void RD(T &x){char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';}
inline int RD(){ int x; RD(x); return x;}
template<class T0, class T1> inline void RD(T0 &x0, T1 &x1){RD(x0), RD(x1);}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2);}
template<class T> inline void OT(const T &x){printf("%d\n", x);}
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}

/*--------*/

const int N = 300009, M = 2 * N;

int l[N], r[N], p[N], w0[N], w1[N], delay[N], rev[N]; 
bool rt[N];
// Link-cut tree
int hd[N], nxt[M], a[M], b[M];
// Adjacent list
int n;

#define lx l[x]
#define rx r[x]

// private:

inline void Inc(int x, int d){
	if (x == 0) return;
	w0[x] += d, w1[x] += d, delay[x] += d;
}

inline void Release(int x){
	if (x == 0) return;

	if (rev[x]){
		swap(lx, rx);
		rev[lx] ^=1, rev[rx] ^=1;
		rev[x] = 0;
	}

	if (delay[x]){
		Inc(lx, delay[x]), Inc(rx, delay[x]);
		delay[x] = 0;
	}
}

inline void Update(int x){
	w1[x] = max(w0[x], w1[lx], w1[rx]);
}

inline void Set(int l[], int y, int x){
	l[y] = x, p[x] = y;
}

#define z p[y]
inline void Rotate(int x){
	int y = p[x];

	if (!rt[y]) Release(z), Set(y == l[z] ? l : r, z, x);
	else p[x] = z;

	Release(y), Release(x);

	if (x == l[y]) Set(l, y, rx), Set(r, x, y);
	else Set(r, y, lx), Set(l, x, y);

	if (rt[y]) rt[y] = false, rt[x] = true;
	Update(y);
}

inline void Splay(int x){
	while (!rt[x]) Rotate(x);
}

inline int Access(int x){
	int y = 0; do{
		Splay(x), Release(x);
		rt[rx] = true, rt[rx = y] = false, Update(x);
		x = p[y = x];
	} while (x);
	return y;
}

inline int Root(int x){
	for (x = Access(x); Release(x), lx; x = lx);
	return x;
}

inline void Evert(int x){
	rev[Access(x)] ^= 1;
}

// public:

void Query(int x, int y){
	if (Root(x) != Root(y))
		puts("-1");
	else {
		Access(y); y = 0; do{
			Splay(x), Release(x); if (!p[x]) OT(max(w1[rx], w0[x], w1[y]));
			rt[rx] = true, rt[rx = y] = false, Update(x);
			x = p[y = x];
		} while (x);
	}
}

void Link(int x, int y){
	if (Root(x) == Root(y))
		puts("-1");
	else {
		Evert(x), Splay(x), p[x] = y, Access(x);
	}
}

// Set y as a root, Cut the connection between x and p[x] ..
void Cut(int y, int x){
	if (x == y || Root(x) != Root(y))
		puts("-1");
	else {
		Evert(y), Splay(y), Access(x), Splay(x);
		p[lx] = p[x], rt[lx] = true, p[x] = lx = 0;
	}
}

void Modify(int x, int y, int w){
	if (Root(x) != Root(y))
		puts("-1");
	else {
		Access(y); y = 0; do{
			Splay(x), Release(x); if (!p[x]) Inc(rx, w), w0[x] += w, Inc(y, w);
			rt[rx] = true, rt[rx = y] = false, Update(x);
			x = p[y = x];
		} while (x);
	}
}

#define v b[i]
inline void dfs(int u = 1){
	for(int i=hd[u];i;i=nxt[i]) if (!p[v]){
		p[v] = u, dfs(v);
	}
}

int main(){

	while (scanf("%d", &n) != EOF){
		// Initializing Phase
		FOR_C(i, 2, n << 1){
			RD(a[i], b[i]), a[i|1] = b[i], b[i|1] = a[i];
			nxt[i] = hd[a[i]], hd[a[i]] = i; ++i;
			nxt[i] = hd[a[i]], hd[a[i]] = i;
		}

		REP_1(i, n) RD(w0[i]), rt[i] = true;
		p[1] = -1, dfs(), p[1] = 0;

		//Interaction Phase
		int a, b, cmd; DO_C(RD()){
			RD(cmd, a, b); if (cmd == 1) Link(a, b);
			else if (cmd == 2) Cut(a, b);
			else if (cmd == 3) Modify(b, RD(), a);
			else Query(a, b);
		}

		puts("");

		// Rececling ...
		RST(hd, p, l, r, delay, rev);
	}
}