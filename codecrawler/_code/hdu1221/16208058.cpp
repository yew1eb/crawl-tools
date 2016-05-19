#include <stdio.h>
#include <math.h>
#define judge(x,y) x<y||fabs(x-y)<0.00000001
double dis(int x,int y,int a,int b)
{
    return (x-a)*(x-a)+(y-b)*(y-b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double x,y,r,a,b,c,d,x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&r,&a,&b,&c,&d);
        x1=a<c?a:c;
        x2=a>=c?a:c;
        y1=b<d?b:d;
        y2=b>=d?b:d;
        if(judge(dis(x,y,x1,y1),r*r)&&judge(dis(x,y,x2,y1),r*r)&&judge(dis(x,y,x1,y2),r*r)&&judge(dis(x,y,x2,y2),r*r))//ç©å½¢å¨åå½¢åçæåµ
        {
        if(dis(x,y,x1,y1)<r*r&&dis(x,y,x2,y1)<r*r&&dis(x,y,x1,y2)<r*r&&dis(x,y,x2,y2)<r*r)
            printf("NO\n");
        else
            printf("YES\n");
        }
        else if(x<x1&&y<y1)//å·¦ä¸è§
        {
            double l=dis(x,y,x1,y1);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(x<x1&&y>y2)//å·¦ä¸è§
        {
            double l=dis(x,y,x1,y2);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(x>x2&&y>y2)//å³ä¸è§
        {
            double l=dis(x,y,x2,y2);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(x>x2&&y<y1)//å³ä¸è§
        {
            double l=dis(x,y,x2,y1);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(x<x1)//æ­£å·¦
        {
            double l=fabs(x-x1);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(y>y2)//æ­£ä¸
        {
            double l=fabs(y-y2);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(x>x2)//æ­£å³
        {
            double l=fabs(x-x2);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else if(y<y1)//æ­£ä¸
        {
            double l=fabs(y-y1);
            if(judge(l,r*r))printf("YES\n");
            else printf("NO\n");
        }
        else//åå¿å¨ç©å½¢å
        {
            double xx=judge((x-x1),(x2-x))?(x-x1):(x2-x);
            double yy=judge((y-y1),(y2-y))?(y-y1):(y2-y);
            double small=judge(xx,yy)?xx:yy;
            if(judge(small,r))printf("YES\n");
            else printf("NO\n");
        }
    }
    return  0;
}
