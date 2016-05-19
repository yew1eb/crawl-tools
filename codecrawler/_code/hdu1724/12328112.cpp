#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a, b, l, r;

double F(double x){
    return (double)sqrt(b*b*(1-x*x/(a*a)));
}

double simpson(double a, double b){
    double c = a + (b-a)/2;
    return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}

double asr(double a, double b, double eps, double A){
    double c = a + (b-a)/2;
    double L = simpson(a,c), R = simpson(c,b);
    if(fabs(L+R-A) <= 15*eps) return L+R+(L+R-A)/15.0;
    return asr(a, c, eps/2, L) + asr(c, b, eps/2, R);
}

double asr(double a, double b, double eps){
    return asr(a, b, eps, simpson(a, b));
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &a, &b, &l, &r);
        double ans = asr(l, r, 1e-6)*2;
        printf("%.3f\n", ans);
    }
    return 0;
}
