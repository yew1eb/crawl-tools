#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, l, r) for(int i = (l); i < (r); i++)
#define foreach(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define MP make_pair
#define PB push_back
#define X real()
#define Y imag()
#define F first
#define S second
#define Sqr(x) ((x) * (x))
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef complex<double> Point;
typedef pair<Point, Point> Line;

const int N = 55;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1.0);

struct Matrix{
    int n, m;
    double v[N][N];
    void init(int _n, int _m){
        n = _n;
        m = _m;
        rep(i, n){
            rep(j, m){
                v[i][j] = 0;
            }
        }
    }
}tmp, ret, c;

Matrix operator *(const Matrix &a, const Matrix &b){
    c.n = a.n, c.m = b.m;
    rep(i, c.n){
        rep(j, c.m){
            c.v[i][j] = 0;
            rep(k, a.m){
                c.v[i][j] = c.v[i][j] + a.v[i][k] * b.v[k][j];
            }
        }
    }
    return c;
}

int n, m, d;
vector<int> E[N];

void print(const Matrix &a){
    rep(i, a.n){
        rep(j, a.m){
            cout << a.v[i][j] << ' ';
        }
        cout << endl;
    }
}

void work(int now){
    ret.init(n, 1);
    tmp.init(n, n);
    rep(i, n){
        ret.v[i][0] = 1.0 / n;
    }
    ret.v[now][0] = 0;
    rep(i, n){
        if (i == now) continue;
        int x = i;
        bool have = false;
        rep(j, E[x].size()){
            int y = E[x][j];
            tmp.v[y][x] = 1.0 / E[x].size();
        }
        tmp.v[now][x] = 0;
    }
    int dd = d;
    while(d){
        if (d & 1) ret = tmp * ret;
        tmp = tmp * tmp;
        d >>= 1;
    }
    d = dd;
    double ans = 0;
    rep(i, n) ans += ret.v[i][0];
    printf("%.15f\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    rep(cas, T){
        scanf("%d%d%d", &n, &m, &d);
        rep(i, n){
            E[i].clear();
        }
        if (n == 1){
            printf("%.12f\n", 0.0);
            continue;
        }
        rep(i, m){
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            E[x].PB(y);
            E[y].PB(x);
        }
        rep(i, n){
            work(i);
        }
//        rep(i, n){
//            printf("%.12f\n", ret.v[i][0]);
//        }
    }
    return 0;
}