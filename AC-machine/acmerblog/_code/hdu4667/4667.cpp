#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(array) memset(array, 0, sizeof(array))
#define eps 1e-10
#define INF (int)1e7
#define PI acos(-1.0)
#define MAX (int)222
using namespace std;
inline int sgn(const double &x){return x > eps ? 1 : (x < -eps ? -1 : 0);}
inline double sqr(const double &x){return x * x;}
struct Point {
    double x, y;
    Point() {}
    Point(const double &xx, const double &yy):x(xx), y(yy) {}
    friend Point operator + (const Point &b, const Point &a) {
        return Point(b.x + a.x, b.y + a.y);
    }
    friend Point operator - (const Point &b, const Point &a) {
        return Point(b.x - a.x, b.y - a.y);
    }
    Point operator * (const double &a)const{
        return Point(x * a, y * a);
    }
    Point operator / (const double &a) const{
        return Point(x / a, y / a);
    }
    friend double dot(const Point &a, const Point &b) {
        return a.x *b.x + a.y * b.y;
    }
    friend double det(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }
    double len( )const {
        return sqrt(dot(*this, *this));
    }
    bool operator < (const Point &a)const {
        return sgn(x - a.x) < 0 || (sgn(x - a.x) == 0 && sgn(y - a.y) < 0);
    }
    bool operator == (const Point &a)const {
        return sgn(x - a.x ) == 0 && sgn(y - a.y) == 0;
    }
    Point rotate(double angle){
        double x1 = x * cos(angle) - y * sin(angle);
        double y1 = x * sin(angle)  + y * cos(angle);
        return Point(x1, y1);
    }
    Point rotate2(const double &cosa,const double &sina){
        double x1 = x * cosa - y * sina;
        double y1 = x * sina + y * cosa;
        return Point(x1, y1);
    }
    Point norm()const{
        return Point(x / len(), y / len());
    }
    void in(){
        scanf("%lf %lf", &x, &y);
    }
    void out()const {
        printf("%.4f    %.4f\n", x, y);
    }
};
int n, m;
struct CirPoint{
    Point p;
    int id;//属于某个圆形
    void in(){ p.in(); }
    bool operator < (const CirPoint &a)const {
        return p < a.p;
    }
}cp[MAX * MAX], tubao[MAX *  MAX];
int ncp, ntb;
struct Cir{
    Point p;
    double r;
    friend vector<Point> pointQieCir(const Point &p, const Cir &cir){
        Point va = (p - cir.p).norm() * cir.r;
        double angle = acos(cir.r / (p - cir.p).len());
//        double cosa = cir.r / (p - cir.p).len();
//        double sina = sqrt(1 + sqr(cosa));
        vector<Point>res;
//        res.push_back( cir.p + va.rotate2(cosa, sina));
//        res.push_back( cir.p + va.rotate2(cosa, -sina));
        res.push_back( cir.p + va.rotate(angle));
        res.push_back( cir.p + va.rotate(-angle));
        return res;
    }
    friend void cirWgCir(const Cir &cir1, const int &id1, const Cir &cir2, const int &id2){
        Point vn = (cir2.p - cir1.p).norm();
        double angle = acos( (cir1.r - cir2.r)/(cir1.p -cir2.p).len() );
//        double cosa = cir1.r - cir2.r/(cir1.p -cir2.p).len(), sina = sqrt(1 - sqr(cosa));
        Point  vc1 = vn * cir1.r, vc2 = vn * cir2.r;
//        Point a = cir1.p + vc1.rotate2(cosa, sina), b = cir1.p + vc1.rotate2(cosa, -sina);
        Point a = cir1.p + vc1.rotate(angle), b = cir1.p + vc1.rotate(-angle);
        cp[ncp].p = a; cp[ncp++].id = id1;
        cp[ncp].p = b; cp[ncp++].id = id1;

//        a = cir2.p + vc2.rotate2(cosa, sina); b = cir2.p + vc2.rotate2(cosa, -sina);
        a = cir2.p + vc2.rotate(angle); b = cir2.p + vc2.rotate(-angle);
        cp[ncp].p = a; cp[ncp++].id = id2;
        cp[ncp].p = b; cp[ncp++].id = id2;
    }
    void in(){
        p.in();
        scanf("%lf", &r);
    }
}cir[MAX];
void input(){
    for(int i = 0; i < n; i++){
        cir[i].in();
    }
    ncp = 0;
    for(int i =0; i < m; i++){
        for(int j = 0; j < 3; j++){
            cp[ncp].in();
            cp[ncp++].id = -1;//三角形顶点
        }
    }
}
void getCirPoint(){
    //point to cir
    int tn = ncp;
    vector<Point>res;
    for(int i = 0; i < tn; i++){
        for(int j = 0; j < n; j++){
            res = pointQieCir(cp[i].p, cir[j]);
            cp[ncp].p = res[0]; cp[ncp++].id = j;
            cp[ncp].p = res[1]; cp[ncp++].id = j;
        }
    }
    //cir to cir
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cirWgCir(cir[i], i, cir[j], j);
        }
    }
}

void hull(){
    ntb = 0;
    sort(cp, cp + ncp);
    for(int i = 0; i < ncp; i++){
        while(ntb > 1 && sgn(det(tubao[ntb - 1].p - tubao[ntb - 2].p,  cp[i].p - tubao[ntb - 2].p)) <= 0)ntb--;
        tubao[ntb++] = cp[i];
    }
    int k = ntb;
    for(int i = ncp - 2; i >= 0; i--){
        while(ntb > k && sgn(det(tubao[ntb -1].p - tubao[ntb - 2].p, cp[i].p - tubao[ntb - 2].p)) <= 0)ntb--;
        tubao[ntb++] = cp[i];
    }
}
void getLen(){
    double ans = 0;
    for(int i  = 0 ; i < ntb - 1; i++){
        if(tubao[i].id != -1 && (tubao[i].id == tubao[(i + 1) ].id)){
            Point va = tubao[i].p - cir[tubao[i].id].p;
            Point vb = tubao[(i + 1)].p - cir[tubao[i].id].p;
            double angle = acos(dot(va, vb)/ va.len() / vb.len());
            int res = sgn(det(va, vb));
            if(res < 0)angle = 2 * PI - angle;
            double t = cir[tubao[i].id].r * angle;
            ans += t;
        }else {
            double t = (tubao[i].p - tubao[(i + 1)].p).len();
            ans += t;
        }
    }
    printf("%.10f\n",ans);
}
int main()
{
    while(cin>>n>>m){
        input();
        if(m == 0 && n == 1){//trick
            printf("%.10f\n", 2 * PI * cir[0].r);
            continue;
        }
        getCirPoint();
        hull();
        getLen();
    }
    return 0;
}
/*
*/
