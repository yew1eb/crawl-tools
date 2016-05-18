const int N = 222;
const double eps = 1e-10;

int vis[N][N];//这个状态求过
double res[N][N];
double to[N][2];//向左向右距离边缘的距离
double dd[N][N];//两线段相交，后一个线段距离交点的距离
bool lx[N][N];
int n;
double a, b;
double MAX;

struct Point {
    double x, y;

    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator -(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    double xMul(const Point &p) const {
        return x * p.y - y * p.x;
    }
} p[N];

inline double dis(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Line {
    Point u, v;
    double w;

    Line() {}
    Line(const Point &_u, const Point &_v) : u(_u), v(_v) {
        w = dis(_u, _v);
    }
} line[N];

inline bool parallel(const Line &a, const Line &b) {
    return ZERO((a.v - a.u).xMul(b.v - b.u));
}

inline Point inter(const Line &a, const Line &b) {
    double s1 = (b.v - a.u).xMul(b.u - a.u), s2 = (b.u - a.v).xMul(b.v - a.v);
    return Point((a.u.x * s2 + a.v.x * s1) / (s2 + s1), (a.u.y * s2 + a.v.y * s1) / (s2 + s1));
}

void init(){
    int i, j;
    Point o, q[] = {Point(0, 0), Point(a, 0), Point(a, b), Point(0, b), Point(0, 0)};
    double l, r;

    for (i = 0; i < 2*n ; ++i) {
        for (j = 0; j < 2*n ; ++j) {
            if (j == i) continue;
            if (parallel(line[i], line[j])) {
                lx[i][j] = true; dd[i][j] = MAX;
            } else {
                o = inter(line[i], line[j]);
                l = dis(o, p[i]); r = dis(o, p[i + 1]);
                if (l < r) {
                    lx[i][j] = true; dd[i][j] = l;
                } else {
                    lx[i][j] = false; dd[i][j] = r;
                }
            }
        }
    }
    for (i = 0; i < 2*n; ++i) {
        to[i][0] = to[i][1] = MAX;
        for (j = 0; j < 4; ++j) {
            if (parallel(line[i], Line(q[j], q[j + 1]))) continue;
            o = inter(line[i], Line(q[j], q[j + 1]));
            l = dis(o, p[i]); r = dis(o, p[i + 1]);
            if (l < r) to[i][0] = min(to[i][0], l);
            else to[i][1] = min(to[i][1], r);
        }
            //cout<<i<<' '<<p[i].x<<' '<<p[i].y<<' '<<to[i][0]<<' '<<to[i][1]<<endl;
    }
}

double DP(int i, int j){
    if(i==j) return 0;
    if(vis[i][j]) return res[i][j];
    vis[i][j] = 1;
    double ans = MAX;
    for(int k=i; k<j; ++k){
        double ll = to[k][0];//点k到边界的距离
        double rr = to[k][1];//点k+1到边界的距离
        if(lx[k][i-1]) ll = min(ll, dd[k][i-1]);//如果k这头与i-1这条线段有交点
        else rr = min(rr, dd[k][i-1]);
        if (lx[k][j]) ll = min(ll, dd[k][j]);
        else rr = min(rr, dd[k][j]);

        ans = min(ans, DP(i, k) + DP(k+1, j) + ll + rr + line[k].w );
    }
    return res[i][j] = ans;
}

int main(){
    while(scanf("%d%lf%lf", &n, &a, &b)!=EOF){
        for (int i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
        for (int i = n; i <= 2 * n; ++i) p[i] = p[i - n];
        for (int i = 0; i < 2 * n; ++i) line[i] = Line(p[i], p[i + 1]);
        MAX = (a+b)*1000.0;
        init();

        memset(vis, 0, sizeof(vis));
        double ans = MAX;
        for (int i = 1; i <= n; ++i) {//枚举第一刀
            ans = min(ans, DP(i, i + n - 1) + to[i - 1][0] + to[i - 1][1] + line[i - 1].w);
        }
        printf("%lf\n", ans);
    }
    return 0;
}
