#include <stdio.h>
#include <math.h>
double L, R, M;
int T;
double Y;
double f(double x){
    return (8*pow(x, 4.0) + 7*pow(x,3.0)+ 2*pow(x, 2.0) + 3*x + 6 );
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%lf", &Y);
        if(f(0) <= Y && Y<= f(100)) {
             L = 0; R = 100;
             while(R - L >1e-10) {
                M = (L +R)/2;
                double ans = f(M);
                if(ans > Y) {
                    R = M - 1e-12;
                }else
                    L = M + 1e-12;
             }
             printf("%.4lf\n", (L + R)/2);
        }else
            printf("No solution!\n");
    }
    return 0;
}
