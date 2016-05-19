/*****************************************
Author      :Crazy_AC(JamesQi)
Time        :2015
File Name   :
*****************************************/
// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;
#define MEM(x,y) memset(x, y,sizeof x)
#define pk push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const double eps = 1e-10;
const int inf = 1 << 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
/**********************Point*****************************/
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B){
    return Vector(A.x + B.x,A.y + B.y);
}
Vector operator - (Vector A,Vector B){//åéåæ³
    return Vector(A.x - B.x,A.y - B.y);
}
Vector operator * (Vector A,double p){//åéæ°ä¹
    return Vector(A.x * p,A.y * p);
}
Vector operator / (Vector A,double p){//åéé¤å®æ°
    return Vector(A.x / p,A.y / p);
}
int dcmp(double x){//ç²¾åº¦æ­£è´ã0çå¤æ­
    if (fabs(x) < eps) return 0;
    return x < 0?-1:1;
}
bool operator < (const Point& A,const Point& B){//å°äºç¬¦å·çéè½½
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}
bool operator == (const Point& A,const Point& B){//ç¹éçå¤æ­
    return dcmp(A.x - B.x) == 0&& dcmp(A.y - B.y) == 0;
}
double Dot(Vector A,Vector B){//åéçç¹ä¹
    return A.x * B.x + A.y * B.y;
}
double Length(Vector A){//åéçæ¨¡
    return sqrt(Dot(A,A));
}
double Angle(Vector A,Vector B){//åéçå¤¹è§
    return acos(Dot(A,B) / Length(A) / Length(B));
}
double Cross(Vector A,Vector B){//åéçåç§¯
    return A.x * B.y - A.y * B.x;
}
double Area2(Point A,Point B,Point C){//ä¸è§å½¢é¢ç§¯
    return Cross(B - A,C - A);
}
Vector Rotate(Vector A,double rad){//åéçæè½¬
    return Vector(A.x * cos(rad) - A.y * sin(rad),A.x * sin(rad) + A.y * cos(rad));
}
Vector Normal(Vector A){//æ³åé
    int L = Length(A);
    return Vector(-A.y / L,A.x / L);
}
double DistanceToLine(Point p,Point A,Point B){//på°ç´çº¿ABçè·ç¦»
    Vector v1 = B - A,v2 = p - A;
    return fabs(Cross(v1,v2)) / Length(v1);
}
double DistanceToSegment(Point p,Point A,Point B){//på°çº¿æ®µABçè·ç¦»
    if (A == B) return Length(p - A);
    Vector v1 = B - A, v2 = p - A,v3 = p - B;
    if (dcmp(Dot(v1,v2) < 0)) return Length(v2);
    else if (dcmp(Dot(v1,v3)) > 0) return Length(v3);
    else return DistanceToLine(p,A,B);
}
bool SegmentProperIntersection(Point A1,Point A2,Point B1,Point B2){//çº¿æ®µç¸äº¤
    double c1 = Cross(A2 - A1,B1 - A1),c2 = Cross(A2 - A1,B2 - A1);
    double c3 = Cross(B2 - B1,A1 - B1),c4 = Cross(B2 - B1,A2 - B1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
const int N = 1010;
Point p[N];
int A[N];
int Pre[N], Mark[N];
double Path[N][N], Dist[N];
double G[N][N];
int n, m;
double Prim() {
    double ret = 0.0;
    memset(Dist, INF,sizeof Dist);
    memset(Path, 0,sizeof Path);
    memset(Mark, 0,sizeof Mark);
    Dist[0] = 0;
    Mark[0] = true;
    for (int i = 1;i <= n;++i) {
        Dist[i] = G[0][i];
        Pre[i] = 0;
    }
    for (int i = 1;i < n;++i) {
        int u = -1;
        for (int j = 0;j < n;++j) {
            if (Mark[j]) continue;
            if (u == -1 || Dist[j] < Dist[u]) {
                u = j;
            }
        }
        if (u == -1) return -1;
        Mark[u] = true;
        ret += Dist[u];
        for (int j = 0;j < n;++j) {
            if (Mark[j] && j != u) Path[j][u] = Path[u][j] = max(Path[j][Pre[u]], Dist[u]);
            if (!Mark[j]) if (Dist[j] > G[u][j]) {
                Dist[j] = G[u][j];
                Pre[j] = u;
            }
        }
    }
    return ret;
}
void solve() {
    double ans = Prim();
    double answer = 0.0;
    for (int i = 0;i < n;++i) {
        for (int j = i + 1;j < n;++j) {
            answer = max(answer, (A[i] + A[j])*1.0 / (ans - Path[i][j]));
        }
    }
    printf("%.2lf\n", answer);
}
int main()
{    
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for (int i = 0;i < n;++i)
            scanf("%lf%lf%d",&p[i].x,&p[i].y,&A[i]);
        m = 0;
        memset(G, INF, sizeof G);
        for (int i = 0;i < n;++i) {
            G[i][i] = 0;
            for (int j = i + 1;j < n;++j) {
                G[i][j] = G[j][i] = Length(p[i] - p[j]);
            }
        }
        solve();
    }
    return 0;
}



