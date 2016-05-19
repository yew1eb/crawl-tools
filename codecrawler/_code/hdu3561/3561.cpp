#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;

struct point {
 double x,y;
 point(double a=0,double b=0) {x=a,y=b;};

 friend bool operator <(const point&a,const point&b) {
 if (fabs(a.x-b.x)>eps) return a.x<b.x;
 if (fabs(a.y-b.y)>eps) return a.y<b.y;
 return 0;
 }
}ia,ib;

struct cir {
 double x,y,r;
// vector<int> dot;
}c[1000];

double sqr(double x){ return x*x;}

double dist(double x1,double y1,double x2,double y2){
 return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int circle_intersect(cir A,cir B,point &ia,point &ib) {
 ia.x=A.x+A.r;
 ia.y=A.y;
 ib.x=A.x;
 ib.y=A.y+A.r;
 if ( fabs(A.x-B.x)<eps && fabs(A.y-B.y)<eps ){
 return 1; //���
 }
 double dd=dist(A.x,A.y,B.x,B.y);
 if (A.r+B.r+eps<dd) return 1; //����

 double k,a,b,d,aa,bb,cc,c,drt;
 k=A.r;
 a=B.x-A.x;
 b=B.y-A.y;
 c=B.r;
 d=sqr(c)-sqr(k)-sqr(a)-sqr(b);

 aa=4*sqr(a)+4*sqr(b);
 bb=4*b*d;
 cc=sqr(d)-4*sqr(a)*sqr(k);

 drt=sqr(bb)-4*aa*cc;
 if (drt<0) return 5; //���
 drt=sqrt(drt);
 ia.y=(-bb+drt)/2/aa;
 ib.y=(-bb-drt)/2/aa;
 if (abs(a)<eps) {
 ia.x=sqrt (sqr(k)-sqr(ia.y));
 ib.x=-ia.x;
 } else {
 ia.x=(2*b*ia.y+d)/-2/a;
 ib.x=(2*b*ib.y+d)/-2/a;
 }
 ia.x+=A.x,ia.y+=A.y;
 ib.x+=A.x,ib.y+=A.y;
 if (fabs(ia.y-ib.y)<eps) {
 if (fabs(A.r+B.r-dd)<eps) return 2; //����
 if (fabs(dd-(max(A.r,B.r)-min(A.r,B.r)))<eps) return 3; //����
 }
 return 4; //�ཻ
}
int n;

int inside(cir a,point b){
 if ( dist(a.x,a.y,b.x,b.y)<a.r+eps ) return true;
 else return false;
}

int main(){
while ( scanf("%d",&n)!=EOF ){
 for (int i=1;i<=n;i++) scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
 int ans=0;
 for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++){
 circle_intersect(c[i],c[j],ia,ib);
 int x=0;
 for (int k=1;k<=n;k++)
 if ( inside(c[k],ia) )x++;
 ans=max(ans,x);
 x=0;
 for (int k=1;k<=n;k++)
 if ( inside(c[k],ib) ) x++;
 ans=max(ans,x);
 }
 printf("%d\n",ans);
}
}