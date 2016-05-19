#include<stdio.h>
int main(){
    int t;
    double x1,x2,x3,y1,y2,y3;
    while(scanf("%d",&t),t){
        while(t--){
            scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
            printf("%.1lf %.1lf\n",(x1+x2+x3)/3,(y1+y2+y3)/3);
        }
    }
    return 0;
} 