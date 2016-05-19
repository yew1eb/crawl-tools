#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
//FFT copy from kuangbin
const double pi = acos (-1.0);
// Complex  z = a + b * i  
struct Complex {
    double a, b;
    Complex(double _a=0.0,double _b=0.0):a(_a),b(_b){}
    Complex operator + (const Complex &c) const {
        return Complex(a + c.a , b + c.b);
    }
    Complex operator - (const Complex &c) const {
        return Complex(a - c.a , b - c.b);
    }
    Complex operator * (const Complex &c) const {
        return Complex(a * c.a - b * c.b , a * c.b + b * c.a);
    }
};
//len = 2 ^ k
void change (Complex y[] , int len) {
    for (int i = 1 , j = len / 2 ; i < len -1 ; i ++) {
        if (i < j) swap(y[i] , y[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    } 
}
// FFT 
// len = 2 ^ k
// on = 1  DFT    on = -1 IDFT
void FFT (Complex y[], int len , int on) {
    change (y , len);
    for (int h = 2 ; h <= len ; h <<= 1) {
        Complex wn(cos (-on * 2 * pi / h), sin (-on * 2 * pi / h));
        for (int j = 0 ; j < len ; j += h) {
            Complex w(1 , 0);
            for (int k = j ; k < j + h / 2 ; k ++) {
                Complex u = y[k];
                Complex t = w * y [k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0 ; i < len ; i ++) {
            y[i].a /= len;
        }
    }
}
const int N = 100005;
typedef long long LL;
int n , a[N];
LL sum[N << 2] , num[N << 2];
Complex x1[N << 2];
int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d", &t);
    while (t --) {
        memset (num , 0 , sizeof(num));
        scanf ("%d", &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d", &a[i]);
            num[a[i]] ++;
        }
        sort (a , a + n);
        int len = a[n - 1] + 1;
        int l = 1;
        while (l < len * 2) l <<= 1;
        for (int i = 0 ; i < len ; i ++) {
            x1[i] = Complex (num[i] , 0);
        }
        for (int i = len ; i < l ; i ++) {
            x1[i] = Complex (0 , 0);
        }
        FFT(x1 , l , 1);
        for (int i = 0 ; i < l ; i ++) {
            x1[i] = x1[i] * x1[i];
        }
        FFT(x1 , l , -1);
        for (int i = 0 ; i < l ; i ++) {
            num[i] = (LL)(x1[i].a + 0.5);
        }
        l = 2 * a[n - 1];
        for (int i = 0 ; i < n ; i ++) {
            num[a[i] << 1] --;
        }
        for (int i = 1 ; i <= l ; i ++) {
            num[i] /= 2;
        }
        sum[0] = 0;
        for (int i = 1 ; i <= l ; i ++) {
            sum[i] = sum[i - 1] + num[i];
        }
        double ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            ans += sum[l] - sum[a[i]];
            ans -= n - 1;
            ans -= (double)i * (n - 1 - i);
            ans -= (double)(n - i - 1) * (n - i - 2) / 2;
        }
        printf ("%.7f\n", ans * 6.0 / n / (n - 1.0) / (n - 2.0));
    }
    return 0;
}