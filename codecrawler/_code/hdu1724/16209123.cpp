#include <cstdio>
#include <cmath>

const double eps = 1e-6;  //ç§¯åç²¾åº¦

double a,b , l, r;
// simpsonå¬å¼ç¨å°çå½æ°
double F (double x){//ä¹å°±æ¯è¢«ç§¯å½æ°,æ¬é¢æ¯æ¤­å
     return sqrt(b*b*(1-x*x/(a*a)));
}

// ä¸ç¹simpsonæ³. è¿éè¦æ±Fæ¯ä¸ä¸ªå¨å±å½æ°
double simpson (double a,double b){
    double c =  a+(b-a)/2;
    return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}
// èªéåºSimpsonå¬å¼ï¼éå½è¿ç¨ï¼ãå·²ç¥æ´ä¸ªåºé´[a,b]ä¸çä¸ç¹simpsonå¼A
double asr(double a , double b ,double eps ,double A){
    double c = a+ (b-a)/2;
    double L = simpson(a,c) ,R = simpson(c,b);
    if (fabs(A-L-R)<=15*eps) return L + R +(A-L-R)/15;
    return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
// èªéåºSimpsonå¬å¼ï¼ä¸»è¿ç¨ï¼  
double asr(double a, double b, double eps) {  
    return asr(a, b, eps, simpson(a, b));  
}

int main ()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        double ans = asr(l,r,eps);
        ans *= 2;//ç§¯ååªè®¡ç®äºxè½´ä¸åé¨å
        printf("%.3f\n",ans);
    }
    return 0;
}
