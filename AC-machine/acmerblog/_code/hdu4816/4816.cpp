#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define Maxn 200100
#define eps 1e-8

inline double getarea(double hk,double hy,double tk,double ty,double len){
    return (ty+ty+len*tk)*len/2.0-(hy+hy+len*hk)*len/2.0;
}

void work(double nowarea,double hk,double hy,double tk,double ty,double tlen,double &ans){
    double l=0,r=tlen,ll,rr,tmp,al,ar;
    while(r-l>eps){
        ll=(l+l+r)/3.0;
        rr=(l+r+r)/3.0;
        al=getarea(hk,hy,tk,ty,ll);
        ar=getarea(hk,hy,tk,ty,rr);
        if (al<ar) l=ll;
        else r=rr;
    }
    tmp=getarea(hk,hy,tk,ty,l);
    if (nowarea+tmp>ans) ans=nowarea+tmp;
}

int x[Maxn],y[Maxn];
double area[Maxn];

int main(){
    //freopen("din.txt","r",stdin);
    int cas,n,l,may,d,i;
    int nh,nt;
    double headx,heady,tailx,taily,kh,kt,tmpl,nowarea,ans;
    double len1,len2;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&l);
        may=0;
        for(i=1;i<=n;++i){
            scanf("%d%d",&x[i],&y[i]);
            if (y[i]>may) may=y[i];
        }
        x[n+1]=l+1;
        y[n+1]=y[n]+1;
        scanf("%d",&d);
        if (d==0) {printf("%.3lf\n",may);continue;}
        d=2*d;
        area[0]=area[1]=0;
        for(i=2;i<=n;++i){
            area[i]=area[i-1]+((double)y[i-1]+y[i])*((double)x[i]-x[i-1])/2.0;
        }
        for(i=1;i<=n;++i){
            if (d>=x[i]&&d<x[i+1]) {break;}
        }
        nh=2;nt=i+1;
        kh=((double)y[2]-y[1])/((double)x[2]-x[1]);
        kt=((double)y[nt]-y[nt-1])/((double)x[nt]-x[nt-1]);
        headx=x[1],heady=y[1];
        tailx=d;taily=y[nt-1]+kt*(d-x[nt-1]);
        nowarea=ans=area[nt-1]+(d-x[nt-1])/2.0*(y[nt-1]+y[nt-1]+kt*(d-x[nt-1]));
        while(1){
            if (tailx+eps>=l) break;
            len1=x[nh]-headx;
            len2=x[nt]-tailx;
            if (len1<len2) tmpl=len1;
            else tmpl=len2;
            work(nowarea,kh,heady,kt,taily,tmpl,ans);
            nowarea=nowarea+getarea(kh,heady,kt,taily,tmpl);
            if (len1<len2){
                headx=x[nh];
                heady=y[nh];
                tailx+=tmpl;
                taily+=kt*tmpl;
                nh+=1;
                kh=((double)y[nh]-y[nh-1])/((double)x[nh]-x[nh-1]);

            }
            else{
                headx+=tmpl;
                heady+=kh*tmpl;
                tailx=x[nt];
                taily=y[nt];
                nt+=1;
                kt=((double)y[nt]-y[nt-1])/((double)x[nt]-x[nt-1]);
            }
        }
        printf("%.3lf\n",ans/(1.0*d));
    }
    return 0;
}


