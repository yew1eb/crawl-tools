#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double EP=1e-8;
const double Pi=acos(-1.0);
int n;
struct Point{
    double x, y, r, loc, s, e;
}p[1005];
bool cmp(Point p1, Point p2){
    return p1.e<p2.e;
}
bool inside(double t1, double st, double end){
    if(st<end) return t1>=st&&t1<=end;
    else return t1>=st||t1<=end;
}
int main(){
    //freopen("1.txt", "r", stdin);
    int T, i, j, k, ans, cnt;
    double t, d;
    scanf("%d", &T);
    while(T–){
        scanf("%d", &n);
        ans=n;
        for(i=0; i<n; i++){
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].r);
            d=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
            t=asin(p[i].r/d);
            if(fabs(p[i].x)<EP){
                if(p[i].y>0)p[i].loc=Pi*0.5;
                else p[i].loc=Pi*1.5;
            }
            else {
                p[i].loc=atan(fabs(p[i].y/p[i].x));
                if(p[i].x<0&&p[i].y>=0)p[i].loc=Pi-p[i].loc;
                else if(p[i].x>0&&p[i].y<0)p[i].loc=2*Pi-p[i].loc;
                else if(p[i].x<0&&p[i].y<0)p[i].loc+=Pi;
            }
            p[i].s=p[i].loc-t;
            if(p[i].s<-EP)p[i].s+=2*Pi;
            p[i].e=p[i].loc+t;
            if(p[i].e>=2*Pi-EP)p[i].e-=2*Pi;
        }
        sort(p, p+n, cmp);
        for(i=0; i<n; i++){
            cnt=1;
            double t2=p[i].e;
            for(j=1; j<n; j++){
                if(!inside(t2, p[(i+j)%n].s, p[(i+j)%n].e)){
                    t2=p[(i+j)%n].e;
                    cnt++;
                }
            }
            if(cnt<ans)
            ans=cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
