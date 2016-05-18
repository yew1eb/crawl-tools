#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 55;
const double eps = 1e-10;
int n;
double a[N] , b[N] , k[N];
vector <double> inter;
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
double sqr (double d) {
    return d * d;
}
void check (double d) {
    if (dcmp (d) >= 0 && dcmp (d - 100) <= 0)
        inter.push_back (d);
}
void get_inter () {
    for (int i = 0 ; i < n ; i ++) {
        if (dcmp (b[i] - 100) > 0) continue;
        double x1 = sqrt ((100 - b[i]) / k[i]) + a[i];
        double x2 = -sqrt ((100 - b[i]) / k[i]) + a[i];
        check (x1) ; check (x2);
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = i + 1 ; j < n ; j ++) {
            double A = (k[i] - k[j]);
            double B = -(2 * k[i] * a[i] - 2 * k[j] * a[j]);
            double C = k[i] * a[i] * a[i] + b[i] - k[j] * a[j] * a[j] - b[j];
            if (dcmp (A) == 0) {
                if (dcmp (B)) check (-C / B);
                continue;
            }
            if (B * B - 4 * A * C < 0) continue;
            if (dcmp (B * B - 4 * A * C) == 0) check (-B / 2 / A);
            else {
                double delta = sqrt (B * B - 4 * A * C);
                double x1 = (-B + delta) / 2 / A , x2 = (-B - delta) / 2 / A;
                check (x1); check (x2);
            }
        }
    }
}

double Function (double x , int i) {
    return k[i] * sqr (x - a[i]) + b[i];
}
int best;
double function (double x) {
    return sqrt (1 + sqr (2 * k[best] * (x - a[best])));
}
double simpson (double l , double r ) {  
    return (function (l ) + 4 * function ((l + r) / 2.0 ) + function (r )) * (r - l) / 6.0;  
}  
double simpson (double l , double r , double all , double eps) {
    double m = (l + r) / 2.0;
    double L = simpson (l , m) , R = simpson (m , r);
    if (fabs (L + R - all) <= 15 * eps) return L + R + (L + R - all) / 15;
    return simpson (l , m , L , eps / 2.0) + simpson (m , r , R , eps / 2.0);
}
double simpson (double l , double r , double eps) {
    return simpson (l , r , simpson (l , r) , eps);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        inter.clear ();
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%lf %lf %lf" , &k[i] , &a[i] , &b[i]);
        }
        get_inter ();
        inter.push_back (0); inter.push_back (100);
        sort (inter.begin () , inter.end ());
        int size = inter.size() ;
        double ans = 0;
        for (int i = 1 ; i < size ; i ++) {
            double x1 = inter[i - 1] , x2 = inter[i];
            if (dcmp (x1 - x2) >= 0) continue;
            double m = (x1 + x2) / 2.0;
            best = 0;
            for (int j = 1 ; j < n ; j ++) {
                if (dcmp (Function (m , j) - Function (m , best)) < 0)
                    best = j;
            }
            if (dcmp (Function (m , best) - 100) >= 0) {
                ans += (x2 - x1);
                continue;
            }
            ans += simpson (x1 , x2  , 1e-8);
        }
        printf ("%.2f\n" , ans);
    }
    return 0;
}