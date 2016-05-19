 #include<cstdio>
 #include<cstring>
 #include<cstdlib>
 #include<iostream>
 #include<algorithm>
 #include<cmath>
 #include<vector>
 using namespace std;
 const int N = 100+10;
 const double eps = 1e-8;
 const double pi = acos(-1.0);
 inline int dcmp(double x) {
     return x < -eps ? -1 : x > eps;
 }
 inline double sqr(double x) {
     return x * x;
 }
 
 struct Point{
     double x,y;
     Point(){}
     Point(double _x,double _y):x(_x),y(_y){}
     bool operator == (const Point &p) const{
         return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
     }
     Point operator + (const Point &p) const{
         return Point(x + p.x, y + p.y);
     }
     Point operator - (const Point &p) const{
         return Point (x - p.x, y - p.y);
     }
     Point operator * (const double &k) const{
         return Point (x * k, y * k);
     }
     Point operator / (const double &k) const{
         return Point (x / k, y / k);
     }
     double operator * (const Point &p) const{
         return x * p.y - y * p.x;
     }
     double operator / (const Point &p) const{
         return x * p.x + y * p.y;
     }
     double len2() {
         return x * x + y * y;
     }
     double len() {
         return sqrt(len2());
     }
     Point scale(const double &k) {
         return dcmp( len() ) ? (*this) * (k / len()) : (*this);
     }
     Point turnLeft() {
         return Point(-y,x);
     }
     Point turnRight(){
         return Point(y,-x);
     }
     double Distance(const Point &p) {
         return sqrt(sqr(x - p.x) + sqr(y - p.y));
     }
     Point rotate(const Point &p,double angle, double k = 1) {
         Point vec = (*this) - p;
         double c = cos(angle * k)  , s =sin(angle * k) ;
         return p + Point(vec.x * c - vec.y * s, vec.x * s + vec.y * c);
     }
     void input(){
         scanf("%lf%lf",&x,&y);
     }
     void ot() {
         printf("%.3lf %.3lf\n",x,y);
     }
 };
 double Angle(Point a,Point b) {
     return (a/b) / a.len() / b.len();
 }
 struct Line{
     Point a,b;
     Line(){}
     Line(Point a,Point b):a(a),b(b){}
     double operator * (const Point &p) const{
         return (b - a) * (p - a);
     }
     double operator / (const Point &p) const{
         return (p - a) / (p - b);
     }
     bool IsPointOnSeg(const Point &p) {
         return dcmp( (a - p) * (b - p) ) == 0 && dcmp( (p - a) / (p - b) ) <= 0;
     }
     int LineCrossSeg(const Line &v) {//2jiao, 1 dian ,0 wu
         int d1 = dcmp( (*this) * v.a), d2 = dcmp((*this) * v.b);
         if ((d1 ^ d2) == -2) return 2;
         return (d1 == 0 || d2 == 0);
     }
     Point CrossPoint(const Line &v) {
         double s1 = v * a, s2 = v * b;
         return ( a * s2 - b * s1 ) / (s2 - s1);
     }
 };
 Line li[3];
 int d[3];
 Point a[3],b[3],c[3];
 Point st,en;
 
 double u;
 int check(int i) {
     if (dcmp( (li[i].b - li[i].a) * (a[d[i]] - li[i].a) ) > 0) {
         return 1;
     }
     return 0;
 }
 void init(){
     for (int i = 0; i < 3; i++) {
         if (check(i)) {
             b[i] = (li[i].b - li[i].a).turnLeft();
             c[i] = (li[i].b - li[i].a).turnRight();
         }else {
             b[i] = (li[i].b - li[i].a).turnRight();
             c[i] = (li[i].b - li[i].a).turnLeft();
         }
     }
 }
 int ond(Point a,Point b,Point p) {
     if (dcmp((p - a) / (b - a)) >= 0) return 1;
     return 0;
 }
 int step1() {
     int fg = 0;
     Line line = Line(st,en);
     for (int i = 0; i < 3; i++) {
         if (line.LineCrossSeg(li[i]) == 2) {
             Point p = line.CrossPoint(li[i]);
             if (ond(st,en,p)) fg = 1;
         }
     }
     if (fg == 0) {
 
         Point p = line.CrossPoint(Line(Point(0,0),Point(1,0)));
         if (ond(st,en,p)) printf("%.3lf\n",p.x+eps);
         else printf("Error\n");
         return 0;
     }
     return 1;
 
 }
 void findPoint(Point &p,int &id) {
     Line line = Line(st,en);
     double dis = 1e50;
     for (int i = 0; i < 3; i++) {
         if (line.LineCrossSeg(li[i])) {
             Point tp = line.CrossPoint(li[i]);
             if (!ond(st,en,tp)) continue;
             double tdis = tp.Distance(st);
             if (tdis < dis && dcmp(tdis) != 0) {
                 dis = tdis;
                 p = tp;
                 id = i;
             }
         }
     }
 }
 void step2() {
     Point p;
     int id = -1;
     findPoint(p,id);
     Point vec = en - st;
     double cs = Angle(vec,b[id]);
     double sn1 = sqrt(1 - cs * cs);
     double sn2 = sn1 / u;
     double ag = asin(sn1) - asin(sn2);
     if (dcmp(vec * b[id]) <= 0) {
         vec = (p + vec).rotate(p,-ag);
     }else vec = (p + vec).rotate(p,ag);
     st = p; en = vec;
 }
 void step3() {
     Point p;
     int id = -1;
     findPoint(p,id);
     Point vec = en - st;
     double cs = Angle(vec,c[id]);
     double sn1 = sqrt(1 - cs * cs);
     double sn2 = sn1 * u;
     if (sn2 > 1) {
         if (dcmp(p.y) == 0) printf("%.3lf\n",p.x+eps);
         else printf("Error\n");
         return;
     }
     double ag = asin(sn2) - asin(sn1);
     if (dcmp(vec * c[id]) >= 0) {
         vec = (p + vec).rotate(p,-ag);
     }else vec = (p + vec).rotate(p,ag);
     st = p; en = vec;
     Point an = Line(st,en).CrossPoint(Line(Point(0,0),Point(1,0)));
     if (ond(st,en,an)) {
         printf("%.3lf\n",an.x+eps);
     }else printf("Error\n");
 }
 void solve(){
     init();
     if (!step1()) return;
     step2();
     step3();
 }
 int main(){
    // cout<<Line(Point(0,0),Point(1,0)).LineCrossSeg(Line(Point(0,0),Point(1,0)))<<endl;
     int T; scanf("%d",&T);
     while (T--) {
         st.input(); en.input();
         for (int i = 0; i < 3; i++) a[i].input();
         li[0] = Line(a[0],a[1]); d[0] = 2;
         li[1] = Line(a[1],a[2]); d[1] = 0;
         li[2] = Line(a[2],a[0]); d[2] = 1;
         scanf("%lf",&u);
         solve();
     }
     return 0;
 }
 /*
 3
 0 10
 0 20
 -1 3 1 2 -1 1
 1.325
 0 10
 0 0
 -1 3 1 2 -1 1
 1.325
 
 0 10 0 9
 0 0 0 1 1 0
 1.0
 */
