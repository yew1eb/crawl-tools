/*
 *  凸包
 *  注意：给出的点为整点数，不要设某一精度值！ 
 */
 
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <iostream>
 
 using namespace std;
 
 const int N = 1005;
 const double PI = 3.1415927;
 
 struct point {
     double x;
     double y;
 }p[N], stack[N];
 
 double dis(point A, point B) {
     return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
 }
 
 double crossProd(point A, point B, point C) {
     return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
 }
 
 //以最左下的点为基准点，其他各点（逆时针方向）以极角从小到大的排序规则
 int cmp(const void *a, const void *b) {
     point *c = (point *)a;
     point *d = (point *)b;
     double k = crossProd(p[0], *c, *d);//极角大小转化为求叉乘
     if (k<0 || !k && dis(p[0], *c)>dis(p[0], *d)) return 1;
     return -1;
 }
 
 double Graham(int n) {
     double x = p[0].x;
     double y = p[0].y;
     int mi = 0;
     for (int i=1; i<n; ++i) {//找到最左下的一个点
         if (p[i].x<x || (p[i].x==x && p[i].y<y)) {
             x = p[i].x;
             y = p[i].y;
             mi = i;
         }
     }
     point tmp = p[mi];
     p[mi] = p[0];
     p[0] = tmp;
     qsort(p+1, n-1, sizeof(point), cmp);
     p[n] = p[0];
     stack[0] = p[0];
     stack[1] = p[1];
     stack[2] = p[2];
     int top = 2;
     for (int i=3; i<=n; ++i) {//加入一个点后,向右偏拐或共线，则上一个点不在凸包内，则--top，该过程直到不向右偏拐或没有三点共线的点 
         while (crossProd(stack[top-1], stack[top], p[i])<=0 && top>=2) --top;
         stack[++top] = p[i];//在当前情况下符合凸包的点，入栈
     }
     double len = 0;
     for (int i=0; i<top; ++i) len += dis(stack[i], stack[i+1]);
     return len;
 }
 
 int main() {
     int t;
     while (scanf("%d", &t) != EOF) {
         while (t--) {
             int n, l;
             scanf ("%d%d", &n, &l);
             for (int i=0; i<n; ++i) scanf ("%lf%lf", &p[i].x, &p[i].y);
             double ans = Graham(n);
             ans += PI * (l + l);
             printf ("%.0lf\n", ans);
             if (t) printf ("\n");
         }
     }
     return 0;
 }