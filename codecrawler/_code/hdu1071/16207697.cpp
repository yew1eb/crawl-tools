#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>


typedef struct Point{
    double x,y;
}Point;

double a,b,c,k,d,s;
Point p[4];

double gao(double x){
    return (a/3.0*pow(x,3.0)+b/2.0*pow(x,2.0)+c*x-k/2*pow(x,2.0)-d*x);
}

int main(){

    //freopen("in.txt","r",stdin);
    int t,i;
    scanf("%d",&t);
    while(t--){
        for(i=1;i<=3;++i){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
    
        a = (p[1].y-p[2].y)/(2*p[1].x*p[2].x-pow(p[2].x,2.0)-pow(p[1].x,2.0));
        b = -2*a*p[1].x;
        c = p[2].y+2*a*p[1].x*p[2].x-a*pow(p[2].x,2.0);
        k = (p[3].y-p[2].y)/(p[3].x-p[2].x);
        d = p[2].y-k*p[2].x;
        s = gao(p[3].x)-gao(p[2].x);
        printf("%0.2lf\n",s);
    }
    
    return 0;
}
