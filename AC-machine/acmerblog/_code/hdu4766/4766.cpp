#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define inf 1e12
#define eps 1e-8
#define maxn 1500
const double PI=acos(-1.0);
struct point{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){}
}po[maxn],cir,temp,na;
int n;
double r,LL;
double dis(point &a,point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool is_ok(){
    double re=r*2,t=0,p;
    point pp;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        p=dis(po[i],po[j]);
        if(p>t){
            t=p;
            pp=point((po[i].x+po[j].x)/2,(po[i].y+po[j].y)/2);
            LL=dis(pp,cir);
        }
    }
    if(t>re) return false;
    return true;
}
int get_max_point(point &a){
    int num=0,i;
    double m=-1,re;
    for(i=1;i<=n;i++){
        re=dis(a,po[i]);
        if(re>m) m=re,num=i;
    }
    return num;
}
bool solve(double left,double right,double R){//三分枚举
    double ans,mid;
    int num;
    while(left<=right){
        mid=(left+right)/2;
        temp.x=cir.x+R*cos(mid);
        temp.y=cir.y+R*sin(mid);
        num=get_max_point(temp);
        ans=dis(temp,po[num]);
        if(ans<=r) return true;
        mid+=eps;
        temp.x=cir.x+R*cos(mid);
        temp.y=cir.y+R*sin(mid);
        mid-=eps;
        if(dis(temp,po[num]) > ans)
        right=mid-eps;
        else left=mid+eps;
    }
    return false;
}
int find_ans(){
    double left=0,right=LL,ans=LL,mid,th,th1,a,b;
    int num,num1;
    point t,t1;
    while(left<=right){
        mid=(left+right)/2;
        if(solve(0,PI,mid) || solve(PI,PI*2,mid)) ans=MIN(ans,mid),right=mid-eps;
        else left=mid+eps;
    }
    printf("%.2f\n",ans);
    return 0;
}
#define MAXN 2000
struct POINTSET{
    double x, y;
};
const double precison=1.0e-8;
POINTSET maxcic, point[MAXN];
double radius;
int curset[MAXN], posset[3];
int set_cnt, pos_cnt;
inline double dis_2(POINTSET &from, POINTSET& to){
    return ((from.x-to.x)*(from.x-to.x)+(from.y-to.y)*(from.y-to.y));
}
int in_cic(int pt){
    if(sqrt(dis_2(maxcic, point[pt]))<radius+precison) return 1;
    return 0;
}
int cal_mincic(){
    if(pos_cnt==1 || pos_cnt==0)
        return 0;
    else if(pos_cnt==3){
        double A1, B1, C1, A2, B2, C2;
        int t0=posset[0], t1=posset[1], t2=posset[2];
        A1=2*(point[t1].x-point[t0].x);
        B1=2*(point[t1].y-point[t0].y);
        C1=point[t1].x*point[t1].x-point[t0].x*point[t0].x+
            point[t1].y*point[t1].y-point[t0].y*point[t0].y;
        A2=2*(point[t2].x-point[t0].x);
        B2=2*(point[t2].y-point[t0].y);
        C2=point[t2].x*point[t2].x-point[t0].x*point[t0].x+
            point[t2].y*point[t2].y-point[t0].y*point[t0].y;
        maxcic.y=(C1*A2-C2*A1)/(A2*B1-A1*B2);
        maxcic.x=(C1*B2-C2*B1)/(A1*B2-A2*B1);
        radius=sqrt(dis_2(maxcic, point[t0]));
    }
    else if(pos_cnt==2){
        maxcic.x=(point[posset[0]].x+point[posset[1]].x)/2;
        maxcic.y=(point[posset[0]].y+point[posset[1]].y)/2;
        radius=sqrt(dis_2(point[posset[0]], point[posset[1]]))/2;
    }
    return 1;
}
int mindisk(){
    if(set_cnt==0 || pos_cnt==3){
        return cal_mincic();
    }
    int tt=curset[--set_cnt];
    int res=mindisk();
    set_cnt++;
    if(!res || !in_cic(tt)){
        set_cnt--;
        posset[pos_cnt++]=curset[set_cnt];
        res=mindisk();
        pos_cnt--;
        curset[set_cnt++]=curset[0];
        curset[0]=tt;
    }
    return res;
}
int main1(int n){
        int i;
        for(i=0; i<n; i++)
        point[i].x=po[i+1].x, point[i].y=po[i+1].y;
            if(n==1){
                maxcic.x=point[0].x;
                maxcic.y=point[0].y;
                radius=0;
            }
            set_cnt=n; pos_cnt=0;
            for(i=0 ;i<n ;i++)  curset[i]=i;
            mindisk();
    return 0;
}
int main(){
    int i,j,k;
    while(scanf("%lf%lf%lf",&cir.x,&cir.y,&r)!=EOF){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%lf%lf",&po[i].x,&po[i].y);
        if(n==1){
            printf("%.2lf\n",dis(cir,po[1])-r);
            continue;
        }
        main1(n);
        if(radius>r){
            printf("X\n");continue;
        }
        na.x=maxcic.x,na.y=maxcic.y;
        LL=dis(cir,na);
        find_ans();
    }
    return 0;
}
