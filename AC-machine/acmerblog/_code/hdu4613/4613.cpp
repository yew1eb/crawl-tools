 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <cstring>
 #include <cmath>
 #include <complex>
 using namespace std;
 const int maxn = 25010;
 typedef complex<double> point;
 #define X real()
 #define Y imag()
 point p[maxn],s[maxn], tp[maxn],ts[maxn];
 double ang;
 int cnttp,cntts;
 int n,m,M,T;
 const double eps = 1e-9;
 int sign(double x)
 {
     if(x>eps)return 1;
     if( fabs(x)>eps )return -1;
     return 0;
 }
 
 bool cmp(const point& p1,const point& p2)
 {
     if( sign(p1.X-p2.X)==0 ) return ( sign( p1.Y-p2.Y)<0 );
     return sign( p1.X-p2.X)<0;
 }
 
 double det(const point &p1,const point& p2,const point& org)
 {
     return (p1.X - org.X) * (p2.Y - org.Y) - (p1.Y - org.Y) * (p2.X - org.X);
 }
 
 void graham(int n,point *p,int& s,point *ch)
 {
     sort(p,p + n,cmp);
     int i,s2;
     ch[0] = p[0];s = 1;
     for(i = 1;i < n;i++) {
         while(s > 1 && det(p[i],ch[s - 1],ch[s - 2])<eps)s--;
         ch[s++] = p[i];
     }
     s2 = s;
     for(int i = n - 2;i>=0;i--) {
         while(s>s2 && det(p[i],ch[s - 1],ch[s - 2])<eps)s--;
         ch[s++] = p[i];
     }
     s--;
 }
 
 double getAngle(const point& p1,const point& p2)
 {
     double dot = p1.X * p2.X + p1.Y * p2.Y;
     dot /= abs(p1) * abs(p2);
     return dot;
 }
 
 bool check(const point& org,const point& trans)
 {
     for(int i = 0;i<m;i++) {
         if(!binary_search(p,p + n,(s[i] - org) * trans + tp[0],cmp))return false;
     }
     return true;
 }
 
 void gao()
 {
     scanf("%d",&m);
     for(int i = 0 ;i<m;i++) {
         scanf("%lf%lf",&s[i].X,&s[i].Y);
     }
     if(n!=m) {puts("No");return;}
     if(n<=2){puts("Yes");return;}
     graham(m,s,cntts,ts);
     double sang;
     point org,trans;
     point A,B,C;
     for(int k=1; k<=2; ++ k){
         for(int i = 0;i<m;i++)
             s[i].X = -s[i].X;
         for(int i = 0;i<cntts;i++)
             ts[i].X = -ts[i].X;
         for(int i = 0;i<cntts;i++) {
             B = ts[i];
             A = ts[(cntts + i - 1) % cntts];
             C = ts[(i + 1) % cntts];
             sang = getAngle(A - B,C - B);
             if(fabs(sang - ang)<eps) {
                 org = B;
                 trans =  (tp[1] - tp[0]) / (A - B);
                 if(check(org,trans)) {
                     puts("Yes");
                     return;
                 }
                 trans = (tp[1] - tp[0]) / (C - B);
                 if(check(org,trans)) {
                     puts("Yes");
                     return;
                 }
             }
         }
     }
     puts("No");
     return;
 }
 
 int main()
 {
     scanf("%d",&T);
     while(T--) {
         scanf("%d",&n);
         for(int i =0;i<n;i++) {
             scanf("%lf%lf", &p[i].X, &p[i].Y);
         }
         if(n>2) {
             graham(n,p,cnttp,tp);
             ang = getAngle(tp[1] - tp[0],tp[cnttp - 1] - tp[0]);
         }
         scanf("%d",&M);
         for(int i =0 ;i<M;i++)
             gao();
         puts("");
     }
     return 0;
 }
