#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct point {
 double x,y;
}p[10];
#define sqr(x) ((x)*(x))
double dist(int i,int j){
 return sqrt(sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y));
}
double calc(int i,int j,int k){
 if (j==3){
 if (p[i].y*p[k].y<=0){
 return dist(i,k);
 }else {
 p[4] = p[i];
 p[4].y*=-1;
 return dist(4,k);
 }
 }else {
 if (p[i].x*p[k].x<=0){
 return dist(i,k);
 }else {
 p[4] = p[i];
 p[4].x*=-1;
 return dist(4,k);
 }
 }
}
double calcmove(int i,int j,bool dx,bool dy){
 p[4] = p[j];
 if (dx) p[4].y*=-1;
 if (dy) p[4].x*=-1;
 return dist(4,i);
}
int order[10];
int main(){
 int tt,i,j,k;
 scanf("%d",&tt);
 while(tt--){
 for (i=0;i<3;i++)
 scanf("%lf%lf",&p[i].x,&p[i].y);
 p[3].x=p[3].y = 0;
 order[1] = 0,order[2] = 1,order[3] = 3,order[4] =4;
 order[0] = order[5] = 2;
 double ans = 1e20;
 do{
 
 int now = 0;
 double tmp = 0;
 while(now<5){
 if (order[now+1]>=3){
 if (order[now+2]>=3){
 point a = p[order[now]],b = p[order[now+3]];
 bool dx = 0,dy = 0;
 if (a.y*b.y>0) dx = 1;
 if (a.x*b.x>0) dy = 1;
 tmp+=calcmove(order[now],order[now+3],dx,dy);
 now+=3;
 }
 else {
 tmp+=calc(order[now],order[now+1],order[now+2]);
 now+=2;
 }
 }else {
 tmp+=dist(order[now],order[now+1]);
 now++;
 }
 }
 if (tmp<ans) ans = tmp;
 }while(next_permutation(order+1,order+5));
 printf("%.2lf\n",ans); 
 }
}