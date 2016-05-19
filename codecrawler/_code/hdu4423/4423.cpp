#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define EPS 1e-6

int compare_real(double d){
    if (d > EPS)
        return 1;
    else if (d < -EPS)
        return -1;
    else
        return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int A, B, C, D, E;
        scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
        B = B - A*D;
        C = C - A*E;
        double AA = A;

        if (B == 0){
            if (C == 0)
                printf("[%.4f, %.4f]\n", AA, AA);
            else{
                double m = -D*D/4.0 + E;
                if (compare_real(m) > 0){
                    if (C > 0)
                        printf("(%.4f, %.4f]\n", AA, C / m + AA);
                    else
                        printf("[%.4f, %.4f)\n", C / m + AA, AA);
                }
                else if (compare_real(m) == 0){
                    if (C > 0)
                        printf("(%.4f, INF)\n", AA);
                    else
                        printf("(-INF, %.4f)\n", AA);
                }
                else{
                    if (C > 0)
                        printf("(-INF, %.4f] U (%.4f, INF)\n", C / m + AA, AA);
                    else
                        printf("(-INF, %.4f) U [%.4f, INF)\n", AA, C / m + AA);
                }
            }
        }
        else{
            double x1 = -1.0*C/B;
            if (compare_real(x1*x1+D*x1+E) == 0){
                double x2 = -D - x1;
                if (compare_real(x1-x2) == 0)
                    printf("(-INF, %.4f) U (%.4f, INF)\n", AA, AA);
                else{
                    double py = B / (x1 - x2);
                    if (compare_real(py) < 0)
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", py+AA, py+AA, AA, AA);
                    else
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", AA, AA, py+AA, py+AA);
                }
            }
            else{
                double D2 = D - 2.0*C/B;
                double E2 = 1.0*C*C/B/B - 1.0*C*D/B + E;
                if (compare_real(E2) < 0)
                    printf("(-INF, INF)\n");
                else{
                    double p = D2 + 2 * sqrt(E2);
                    double q = D2 - 2 * sqrt(E2);
                    if (B > 0){
                        if (compare_real(p)>0 && compare_real(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                        else if (compare_real(q) == 0)
                            printf("(-INF, %.4f]\n", B/p + AA);
                        else if (compare_real(p)>0 && compare_real(q) < 0)
                            printf("[%.4f, %.4f]\n", B/q + AA, B/p + AA);
                        else if (compare_real(p) == 0)
                            printf("[%.4f, INF)\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                    }
                    else{
                        if (compare_real(p)>0 && compare_real(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                        else if (compare_real(q) == 0)
                            printf("[%.4f, INF)\n", B/p + AA);
                        else if (compare_real(p)>0 && compare_real(q) < 0)
                            printf("[%.4f, %.4f]\n", B/p + AA, B/q + AA);
                        else if (compare_real(p) == 0)
                            printf("(-INF, %.4f]\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                    }
                }
            }
        }
    }
    return 0;
}