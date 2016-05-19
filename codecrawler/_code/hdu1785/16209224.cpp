#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct point{
    double x,y;
    bool  operator < (const  point&rhs) const {
        return atan2(y,x) < atan2(rhs.y,rhs.x);
    }
}a[110];
  int   main(void)
  {
      int n;
      while(scanf("%d",&n)&&n>=0){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        sort(a,a+n);
        printf("%.1lf %.1lf",a[0].x,a[0].y);
        for(int i=1;i<n;i++) printf(" %.1lf %.1lf",a[i].x,a[i].y);
        printf("\n");
      }

  }
