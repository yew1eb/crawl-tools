#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define eps 1e-8
#define MAXN 333
#define INF 1111111111
using namespace std;
typedef double TYPE;
struct POINT
{
    TYPE x;
    TYPE y;
    POINT() : x(0), y(0) {};
    POINT(TYPE _x_, TYPE _y_) : x(_x_), y(_y_) {};
    bool operator == (const POINT &p)const
    {
        return (fabs(x - p.x) < eps && fabs(y - p.y) < eps);
    }
}p[MAXN];
TYPE Distance(const POINT & a, const POINT & b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct SEG
{
    POINT a; //èµ·ç¹
    POINT b; //ç»ç¹
    SEG() {};
    SEG(POINT _a_, POINT _b_):a(_a_),b(_b_) {};
    bool operator == (const SEG &p)const
    {
        return (p.a == a && p.b == b) || (p.b == a && p.a == b);
    }
}seg[MAXN];
TYPE Cross(const POINT & a, const POINT & b, const POINT & o)
{
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
bool IsIntersect(const SEG & u, const SEG & v)
{
    return (Cross(v.a, u.b, u.a) * Cross(u.b, v.b, u.a) > 0) &&
           (Cross(u.a, v.b, v.a) * Cross(v.b, u.b, v.a) > 0) &&
           (max(u.a.x, u.b.x) > min(v.a.x, v.b.x)) &&
           (max(v.a.x, v.b.x) > min(u.a.x, u.b.x)) &&
           (max(u.a.y, u.b.y) > min(v.a.y, v.b.y)) &&
           (max(v.a.y, v.b.y) > min(u.a.y, u.b.y));
}
int seq[MAXN];
struct node
{
    int v, next;
}edge[MAXN * MAXN];
int e, head[MAXN], mark[MAXN], cx[MAXN], cy[MAXN], n, m, so;
double dis[MAXN][MAXN];
void insert(int x, int y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
}
int path(int u)
{
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!mark[v])
        {
            mark[v] = 1;
            if(cy[v] == -1 || path(cy[v]))
            {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int gao()
{
    int ans = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(int i = 1; i <= n; i++)
    {
        memset(mark, 0, sizeof(mark));
        ans += path(i);
    }
    return ans;
}
void floyd(int n)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}
bool ok(double mid)
{
    e = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(dis[seq[i]][seq[j]] <= mid)
                insert(seq[i], seq[j] + n);
    int x = gao();
    if(n - x <= so) return true;
    return false;
}
void slove()
{
    double l = 0, r = INF;
    double ans = -1;
    while(r - l > eps)
    {
        double mid = (l + r) / 2;
        if(ok(mid)) {ans = mid; r = mid;}
        else l = mid;
    }
    printf("%.2f\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &so);
        for(int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        for(int i = 1; i <= m; i++)
        {
            scanf("%lf%lf%lf%lf", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
            p[n + i * 2 - 1] = seg[i].a;
            p[n + i * 2] = seg[i].b;
        }
        for(int i = 1; i <= n; i++) scanf("%d", &seq[i]);
        for(int i = 1; i <= n + m * 2; i++)
            for(int j = 1; j <= n + m * 2; j++)
            {
                if(i == j) {dis[i][j] = 0; continue;}
                int flag = false;
                for(int k = 1; k <= m; k++)
                {
                    if(seg[k] == SEG(p[i], p[j])) continue;
                    if(IsIntersect(seg[k], SEG(p[i], p[j])))
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag) dis[i][j] = INF;
                else dis[i][j] = Distance(p[i], p[j]);
            }

        floyd(n + m * 2);
        slove();
    }
    return 0;
}