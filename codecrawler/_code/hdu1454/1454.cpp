#include<stdio.h>
#define eps 1e-8
struct point{
    double x,y;
}p[23],left,right,tp;
double a1,b1,c1,a2,b2,c2;
void get_line1(struct point p1,struct point p2)
{
    a1=p1.y-p2.y;
    b1=p2.x-p1.x;
    c1=p1.x*p2.y-p2.x*p1.y;
}
void get_line2(struct point p1,struct point p2)
{
    a2=p1.y-p2.y;
    b2=p2.x-p1.x;
    c2=p1.x*p2.y-p2.x*p1.y;
}
void get_line3(struct point p1,struct point p2)
{
    p1.y--,p2.y--;
    a2=p1.y-p2.y;
    b2=p2.x-p1.x;
    c2=p1.x*p2.y-p2.x*p1.y;
}
double get_intersectx()
{
    double d=a1*b2-a2*b1;
    return (b1*c2-b2*c1)/d;
}
int main()
{
    int i,j,k,n;
    double ans,temp,tmp;

    while(scanf("%d",&n)>0)
    {
        if(!n) break;
        for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(ans=-0xffffff,i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                left=p[i];
                right=p[j]; right.y--;
                get_line1(left,right);
                for(temp=-0xffffff,k=0;k<n;k++)
                {
                    tp.x=p[k].x;
                    tp.y=left.y-(left.x-tp.x)*(right.y-left.y)/(right.x-left.x);
                    if(p[k].y+eps>tp.y&&tp.y>p[k].y-1-eps) temp=p[k].x;
                    else
                    {
                        if(k>0)
                        {
                            if(tp.y>p[k].y) get_line2(p[k-1],p[k]);
                            else get_line3(p[k-1],p[k]);
                            tmp=get_intersectx();
                            if(p[k-1].x-eps<tmp&&tmp<p[k].x+eps) temp=tmp;
                        }
                        break;
                    }
                }
                if(temp>ans) ans=temp;
            }
        }
        if(ans<p[n-1].x) printf("%.2lf\n",ans);
        else printf("Through all the pipe.\n");
    }

    return 0;
}