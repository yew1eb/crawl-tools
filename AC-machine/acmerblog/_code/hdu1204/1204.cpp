1.#include <stdio.h> 
2.#include <math.h> 
3.const double EPS = 1e-12; 
4.
5.inline void solve(int n, int m, double p, double q) { 
6.    if(n==0) { 
7.        printf("0.00\n"); 
8.    } 
9.    else if(m==0) { 
10.        printf("1.00\n"); 
11.    } 
12.    else if(p==0.0||q==1.0) { 
13.        printf("0.00\n"); 
14.    } 
15.    else { 
16.        double lamda = q*(1-p)/(p*(1-q)); 
17.        if(fabs(lamda-1.0)<EPS) { 
18.            printf("%.2lf\n", double(n)/(m+n)); 
19.        } 
20.        else { 
21.            double res = (1-pow(lamda, n))/(1-pow(lamda, m+n)); 
22.            printf("%.2lf\n", res); 
23.        } 
24.    } 
25.} 
26.
27.int main() 
28.{ 
29.    int n, m; 
30.    double p, q; 
31.    while(scanf("%d%d%lf%lf", &n, &m, &p, &q)!=EOF) { 
32.        solve(n, m, p, q); 
33.    } 
34.    return 0; 
35.}