#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
#define FF first
#define SS second
#define x FF
#define y SS
typedef pair<LL,LL> pll;
typedef pair<double,double> pdd;

const double eps = 1e-8;

LL n,m;
pll p1,p2;
pll v1,v2;
pdd ans;
LL t1,t2;

pdd intersect(LL V1,LL Xs1,LL Ys1,LL V2,LL Xs2,LL Ys2){
    if(V1==V2){
        return make_pair((double)(Xs1+Xs2)/2.0,(double)(Ys1+Ys2)/2.0);
    }else{
        double tmp = (double)((V1*Xs1-V2*Xs2)-(Ys1-Ys2))/(V1-V2);
        return make_pair(tmp,(double)(V1*(tmp-Xs1) + Ys1));
    }
}

bool solve(LL &T1,pll &v1,LL &Xs1,LL &Ys1,
           LL &T2,pll &v2,LL &Xs2,LL &Ys2){

    LL V1 = v1.x*v1.y, V2 = v2.x*v2.y;

    if(V1==V2 && (v1==v2 || (v1!=v2&&Ys1-V1*Xs1!=Ys2-V2*Xs2))){
    }else{
        pdd c = intersect(V1,Xs1,Ys1,V2,Xs2,Ys2);
        double cx = c.x;
        double cy = c.y;

        if(-eps <= cx && cx <= n+eps && -eps <= cy && cy <= m+eps
        && abs(abs(cx-Xs1)-abs(cx-Xs2))<eps
        && ((v1.x==1)?(cx+eps>=Xs1):(cx<=Xs1+eps)) && ((v1.y==1)?(cy+eps>=Ys1):(cy<=Ys1+eps))
        && ((v2.x==1)?(cx+eps>=Xs2):(cx<=Xs2+eps)) && ((v2.y==1)?(cy+eps>=Ys2):(cy<=Ys2+eps))
        ){
            ans = make_pair(cx,cy);
            return true;
        }
    }

    LL t1,t2,t3,t4;
    if(v1.x==1) t1 = n-Xs1;
    else t1 = Xs1;
    if(v1.y==1) t2 = m-Ys1;
    else t2 = Ys1;
    if(v2.x==1) t3 = n-Xs2;
    else t3 = Xs2;
    if(v2.y==1) t4 = m-Ys2;
    else t4 = Ys2;
    LL t = min(t1,min(t2,min(t3,t4)));

    LL k1=0,k2=0,k3=0,k4=0;
    if(v1.x==1 && Xs1+t>=n) k1=1;
    else if(v1.x==-1 && Xs1-t<=0) k1=1;
    if(v1.y==1 && Ys1+t>=m) k2=1;
    else if(v1.y==-1 && Ys1-t<=0) k2=1;

    if(v2.x==1 && Xs2+t>=n) k3=1;
    else if(v2.x==-1 && Xs2-t<=0) k3=1;
    if(v2.y==1 && Ys2+t>=m) k4=1;
    else if(v2.y==-1 && Ys2-t<=0) k4=1;

    T1+=t;
    T2+=t;
    Xs1+=v1.x*t;
    Ys1+=v1.y*t;
    Xs2+=v2.x*t;
    Ys2+=v2.y*t;

    if(k1) v1.x=0-v1.x;
    if(k2) v1.y=0-v1.y;
    if(k3) v2.x=0-v2.x;
    if(k4) v2.y=0-v2.y;

    return false;
}

int main()
{
//    freopen("data.in","r",stdin);
    int T;
    bool ok;

    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%I64d%I64d",&n,&m);
        scanf("%I64d%I64d%I64d%I64d",&p1.x,&p1.y,&p2.x,&p2.y);
        ok=0;
        LL lim = 2*n*m+max(n,m);
        LL xs1=p1.x,ys1=p1.y,xs2=p2.x,ys2=p2.y;
        v1.x=v1.y=v2.x=v2.y=1;
        t1=t2=0;
        while(true){
            if((ok = solve(t1,v1,xs1,ys1,t2,v2,xs2,ys2))) break;
            if(t1>lim && t2>lim) break;
        }
        printf("Case #%d:\n",cas);
        if(ok) printf("%.1lf %.1lf\n",ans.FF,ans.SS);
        else puts("Collision will not happen.");
    }
    return 0;
}
