#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const double O=1e-6;
struct point{ double x,y;
 point(double x0=0,double y0=0){ x=x0; y=y0;}
 point operator +(point b){ return point(x+b.x,y+b.y);}
 point operator *(double k){ return point(k*x,k*y);}
 point operator -(point b){ return point(b.x-x,b.y-y);}
 double operator %(point b){ return x*b.y-y*b.x;}
}p[3000];
double s,wx,wy,y[3000];
int n,m;

void put(point o,point a,point b){
 s+=(o-a)%(o-b);
 wx+=(o-a)%(o-b)*(o.x+a.x+b.x)/3;
 wy+=(o-a)%(o-b)*(o.y+a.y+b.y)/3;
}

int check(double y){
 point lp,rp;
 s=0; wx=0; wy=0;
 for (int j=1;j<=n;j++){
 if ( p[j+1].y>y+O ){
 lp=p[j]+(p[j]-p[j+1])*((y-p[j].y)/(p[j+1].y-p[j].y));
 put(p[1],p[j],lp);
 break;
 }
 put(p[1],p[j],p[j+1]);
 }
 for (int j=n+1;j<=n+m;j++){
 if ( p[j+1].y>y+O ){
 rp=p[j]+(p[j]-p[j+1])*((y-p[j].y)/(p[j+1].y-p[j].y));
 put(p[1],rp,p[j]);
 break;
 }
 put(p[1],p[j+1],p[j]);
 }
 put(p[1],lp,rp);
 double mx=wx/s;
 if ( mx<p[1].x-O || mx>p[n+1].x+O )
 return false;
 else return true;
}

int main(){
int test;
scanf("%d",&test);
while ( test-- ){
 scanf("%d%d",&n,&m);
 for (int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
 for (int i=1;i<=m;i++) scanf("%lf%lf",&p[i+n].x,&p[i+n].y);
 for (int i=1;i<=n+m;i++) p[i].y-=p[1].y;
 for (int i=1;i<=n+m;i++) y[i]=p[i].y;
 sort(y+1,y+n+m+1);
 int k=n+m;
 for (int i=1;i<=n+m;i++){
 if ( !check(y[i]) || y[i+1]>p[n].y+O || y[i+1]>p[n+m].y+O ){
 k=i;
 break;
 }
 }
 double l=y[k-1],r=y[k];
// printf("%d\n",k);
 while ( l+O<r ){
 double mid=(l+r)/2;
 if ( check(mid) )
 l=mid;
 else r=mid;
 }
 printf("%.3lf\n",l);
}
}