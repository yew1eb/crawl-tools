#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>

using namespace std;

const double Pi=3.14159265358979323846;

double Rad2Deg(double rad){
    return (rad*180.0/Pi);
}

double Deg2Rad(double deg){
    return (deg*Pi/180.0);
}

double ArcCos(double val){
    return Rad2Deg(acos(val));
}

double Sin(double deg){
    return sin(Deg2Rad(deg));
}

struct CIRCLE{
    double x;
    double y;
    double r;
    CIRCLE(){}
    CIRCLE(double xx,double yy,double rr){
        x=xx; y=yy; r=rr;
    }
};

struct POINT{
    double x;
    double y;
    POINT():x(0),y(0){};
    POINT(double xx,double yy):x(xx),y(yy){    }
};

double Distance(const POINT& a,const POINT& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

POINT Center(const CIRCLE& circle){
    return POINT(circle.x,circle.y);
}

double Area(const CIRCLE& circle){
    return Pi*circle.r*circle.r;
}

double CommonArea(const CIRCLE& A,const CIRCLE &B){
    double area=0.0;
    const CIRCLE& M=(A.r>B.r)?A:B;
    const CIRCLE& N=(A.r>B.r)?B:A;
    double D=Distance(Center(M),Center(N));
    if((D<M.r+N.r)&&(D>M.r-N.r)){
        double cosM=(M.r*M.r+D*D-N.r*N.r)/(2.0*M.r*D);
        double cosN=(N.r*N.r+D*D-M.r*M.r)/(2.0*N.r*D);
        double alpha=2.0*ArcCos(cosM);
        double beta=2.0*ArcCos(cosN);
        
        double TM=0.5*M.r*M.r*Sin(alpha);
        double TN=0.5*N.r*N.r*Sin(beta);
        double FM=(alpha/360.0)*Area(M);
        double FN=(beta/360.0)*Area(N);
        area=FM+FN-TM-TN;
    }else if(D<=M.r-N.r){
        area=Area(N);
    }
    return area;
}


int main(){
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        double r,R;
        double x1,y1;
        double x2,y2;
        //cin>>r>>R>>x1>>y1>>x2>>y2;
        scanf("%lf%lf%lf%lf%lf%lf",&r,&R,&x1,&y1,&x2,&y2);
        CIRCLE cr1(x1,y1,r);
        CIRCLE cr2(x2,y2,r);
        
        CIRCLE cR1(x1,y1,R);
        CIRCLE cR2(x2,y2,R);
        double ans=CommonArea(cR1,cR2)+CommonArea(cr1,cr2);
        ans-=CommonArea(cr1,cR2);
        ans-=CommonArea(cR1,cr2);
        printf("Case #%d: %.6lf\n",cas,ans);
    }
    return 0;
}
