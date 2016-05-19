#include<stdio.h>
#include<math.h>
int main(void){
int t;
double a,b,h,m,s,th;
while(scanf("%d",&t)!=EOF){
    while(t--){
        scanf("%lf%lf%lf",&h,&m,&s);
        if(h>12.0)h-=12.0;
        a=h+m/60.0+s/3600.0;
        b=m+s/60.0;
        th=fabs(a*30.0-b*6.0);
        if(th>180.0)th=360-th;
        th=floor(th);
        printf("%.0f\n",th);
    }
}
return 0;
}