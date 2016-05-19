#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #define MAXN 100005
 #define INF (1LL<<62)
 using namespace std;
 typedef long long LL;
 struct point{
     int x,y;
 }p[MAXN],p2[MAXN];
 bool dv[MAXN];
 bool cmpx(const point& p1,const point& p2){
     return p1.x<p2.x;
 }
 bool cmpy(const point& p1,const point& p2){
     return p1.y<p2.y;
 }
 LL getdis(point p1,point p2){
     return (LL)(p1.x-p2.x)*(p1.x-p2.x)+(LL)(p1.y-p2.y)*(p1.y-p2.y);
 }
 void buildKD(int l,int r,point p[]){
     if(l==r)return;
     int mid=(l+r)>>1;
     //按照坐标范围选择建树轴
     int minx=min_element(p+l,p+r,cmpx)->x;
     int miny=min_element(p+l,p+r,cmpy)->y;
     int maxx=max_element(p+l,p+r,cmpx)->x;
     int maxy=max_element(p+l,p+r,cmpy)->y;
     dv[mid]=(maxx-minx>=maxy-miny);
     //dv[mid]=(step&1);也可以按照层数交替建树,貌似效率略慢
     nth_element(p+l,p+mid,p+r,dv[mid]?cmpx:cmpy);
     buildKD(l,mid,p);
     buildKD(mid+1,r,p);
 }
 LL res=0;
 void find(int l,int r,point a,point p[]){
     if(l==r)return;
     int mid=(l+r)>>1;
     LL dist=getdis(a,p[mid]);
     if(dist>0)res=min(res,dist);
     LL d=dv[mid]?(a.x-p[mid].x):(a.y-p[mid].y);
     int l1=l,l2=mid+1,r1=mid,r2=r;
     if(d>0)swap(l1,l2),swap(r1,r2);
     find(l1,r1,a,p);
     if(d*d<res)find(l2,r2,a,p);
 }
 int n,cas;
 int main(){
     freopen("test.in","r",stdin);
     scanf("%d",&cas);
     while(cas--){
         scanf("%d",&n);
         for(int i=0;i<n;i++)
             scanf("%d%d",&p[i].x,&p[i].y),p2[i]=p[i];
         buildKD(0,n,p);
         for(int i=0;i<n;i++){
             res=INF;
             find(0,n,p2[i],p);
             printf("%I64d\n",res);
         }
 
 
     }
     return 0;
 }