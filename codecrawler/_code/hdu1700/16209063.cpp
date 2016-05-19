#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    double x,y,x2,y2,r;
    double ax,ay,bx,by,k,m,l,A,B,C;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&x,&y);
        r = x*x+y*y;
        A = r;
        B = y*r;
        C = r*r/4-r*x*x;
        ay = (-B-sqrt(B*B-4*A*C))/(2*A);
        by = (-B+sqrt(B*B-4*A*C))/(2*A);
        if(fabs(x-0)<1e-7)//é²æ­¢é¤æ°åºç°0çæåµ
        {
            ax=-sqrt(r-ay*ay);
            bx=sqrt(r-by*by);
        }
        else
        {
            ax=(-r/2-ay*y)/x;//ç±äºayå¿å®å°äºbyï¼æä»¥axä¹å¿å®å°äºbxï¼æä»¥æ éè¿è¡å¤§å°å¤å®
            bx=(-r/2-by*y)/x;
        }
        printf("%.3lf %.3lf %.3lf %.3lf\n",ax,ay,bx,by);
    }
    return 0;
}
