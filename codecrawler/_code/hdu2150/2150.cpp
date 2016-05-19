/*
 *  题目要求：判断给出的一些折线段是否相交 
 *  解法：枚举每条折线段上的每段线段，判断其是否与其它折线段的线段相交 
 */
 
 #include <cstdio>
 #include <cstdlib>
 #include <iostream>
 
 using  namespace std;
 
 const int N = 35;
 const int M = 105;
 
 int num[N];
 struct point {
     double x;
     double y;
 }p[N][M];
 
 double crossProd(point A, point B, point C) {
     return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
 }
 
 bool segIntersect(point A, point B, point C, point D) {
     if (max(A.x, B.x) >= min(C.x, D.x) &&
         max(C.x, D.x) >= min(A.x, B.x) &&
         max(A.y, B.y) >= min(C.y, D.y) &&
         max(C.y, D.y) >= min(A.y, B.y) &&
         crossProd(A, B, C)*crossProd(A, D, B) > 0 &&
         crossProd(C, D, A)*crossProd(C, B, D) > 0) return true;
     return false;
 }
 
 bool solve(int n) {
     for (int i=0; i<n-1; ++i) {//枚举每条折线段 
         for (int j=1; j<num[i]; ++j) {
             for (int ii=i+1; ii<n; ++ii) {
                 for (int k=1; k<num[ii]; ++k) {
                     if (segIntersect(p[i][j-1], p[i][j], p[ii][k-1], p[ii][k])) return false;//判断线段相交 
                 }
             }
         }
     }
     return true;
 }
 
 int main() {
     int n;
     while (scanf("%d", &n) != EOF) {
         for (int i=0; i<n; ++i) {
             scanf ("%d", &num[i]);
             for (int j=0; j<num[i]; ++j) scanf ("%lf%lf", &p[i][j].x, &p[i][j].y);
         }
         if (n == 1) printf ("No\n");
         else {
             bool yes = solve(n);
             if (yes) printf ("No\n");
             else printf ("Yes\n");
         }    
     }
     return 0;
 }