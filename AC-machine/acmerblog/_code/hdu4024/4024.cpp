#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// X1, Y1, X2, Y2, Lx, Ly, vD , vB and L

const double eps=1e-7;
double X1,Y1,X2,Y2,lx,ly,vd,vb,L;

double getdis(double ax,double ay,double bx,double by){
    return sqrt ( (ax-bx)*(ax-bx)+(ay-by)*(ay-by) );
}

double getmin(double ans1,double ans2){
    if(ans1<-eps) return ans2;
    if(ans2<-eps) return ans1;
    return min(ans1,ans2);
}

void solve(){
    double l=L/vb,r=1e9;
    while(r-l>eps){
        double mid=(l+r)/2;
        double X0=X1+mid*lx,Y0=Y1+mid*ly;
        double dis0=getdis(X0,Y0,X2,Y2);
        double disd=vd*(mid-L/vb);
        if(dis0<=L){
            if(disd+dis0<=L) l=mid;
            else r=mid;
        }else{
            if(disd+L>=dis0) r=mid;
            else l=mid;
        }
    }
    printf("%.3lf %.3lf\n",L,(r+l)/2);
}

int main(){
    while(cin>>X1>>Y1>>X2>>Y2>>lx>>ly>>vd>>vb>>L){
        if( fabs(X1)<eps && fabs(X2)<eps && fabs(Y1)<eps && fabs(Y2)<eps ){
            if( fabs(lx)<eps && fabs(ly)<eps && fabs(vd)<eps && fabs(vb)<eps && fabs(L)<eps ) break;
        }
        solve();
    }
    return 0;
}
