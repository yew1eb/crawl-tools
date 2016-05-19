#include <stdio.h>
#define s(x)  ((x)*(x))
#define ss(x) ((x)*(x)*(x))
int main() {
    int T;
    double x1, x2, x3, y1, y2, y3, area, a, b, c, k, d;
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--) {
        scanf("%lf%lf",&x1,&y1);
        scanf("%lf%lf",&x2,&y2);
        scanf("%lf%lf",&x3,&y3);
        a = (y2-y1)/ s(x2-x1);
        b = -2*a*x1;
        c = y1+s(b)/(4*a);
        k = (y3-y2)/(x3-x2);
        d = y3-x3*k;
        //printf("a=%.5lf b=%.5lf c=%.5lf k=%.5lf d=%.5lf\n",a,b,c,k,d);
        area = a*ss(x3)/3 + 0.5*(b-k)*s(x3)+(c-d)*x3
               - a*ss(x2)/3 - 0.5*(b-k)*s(x2) - (c-d)*x2;
        printf("%.2lf\n",area);
    }
    return 0;
}
