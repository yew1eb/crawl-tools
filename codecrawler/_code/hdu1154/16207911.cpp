/******************************************************************
é¢æï¼
å¤è¾¹å½¢ænä¸ªé¡¶ç¹ï¼è¾å¥mæ¡ç´çº¿ï¼åå«è¾åºå®ä»¬å¨å¤è¾¹å½¢åçé¿åº¦ï¼è¾¹çä¹ç®
ç®æ³ï¼
æ±åºç´çº¿ä¸å¤è¾¹å½¢çææäº¤ç¹ï¼
æåºåï¼å¤æ­æ¯ä¸æ®µçº¿æ®µæ¯å¦å¨å¤è¾¹å½¢åï¼å¤æ­ä¸­ç¹æ¯å¦å¨å¤è¾¹å½¢åï¼ï¼æ±åã
*******************************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point
{
    double x;
    double y;
} p[1001], px[10001];
int n;
double eps=1e-8;

int cmp(Point a, Point b)
{
    if(abs(a.x-b.x)<eps)
        return a.y<b.y;
    return a.x<b.x;
}

double dist(Point a,Point b)//æ±è·ç¦»
{
    return sqrt((a.x - b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double direction(Point pi,Point pj,Point pk)
{
    return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

bool on_segment(Point pi,Point pj,Point pk)//å¤æ­ç¹pkæ¶åå¨çº¿æ®µpi, pjä¸
{
    if(direction(pi, pj, pk)==0)
    {
        if(pk.x>=min(pi.x,pj.x)&&pk.x<=max(pi.x,pj.x)&&pk.y>=min(pi.y,pj.y)&&pk.y<=max(pi.y,pj.y))
            return true;
    }
    return false;
}

bool segments_intersect(Point p1,Point p2,Point p3,Point p4)//å¤æ­çº¿æ®µæ¯å¦ç¸äº¤
{
    double d1=direction(p3,p4,p1);
    double d2=direction(p3,p4,p2);
    double d3=direction(p1,p2,p3);
    double d4=direction(p1,p2,p4);
    if(d1*d2<0&&d3*d4<0)
        return true;
    else if(d1==0&&on_segment(p3,p4,p1))
        return true;
    else if(d2==0&&on_segment(p3,p4,p2))
        return true;
    else if(d3==0&&on_segment(p1,p2,p3))
        return true;
    else if(d4==0&&on_segment(p1,p2,p4))
        return true;
    return false;
}

Point intersection(Point a1, Point a2, Point b1, Point b2)//è®¡ç®çº¿æ®µäº¤ç¹
{
    Point ret = a1;
    double t = ((a1.x - b1.x) * (b1.y - b2.y) - (a1.y - b1.y) * (b1.x - b2.x))
               / ((a1.x - a2.x) * (b1.y - b2.y) - (a1.y - a2.y) * (b1.x - b2.x));
    ret.x += (a2.x - a1.x) * t;
    ret.y += (a2.y - a1.y) * t;
    return ret;
}

int InPolygon(Point a)//å¤æ­ç¹æ¯å¦å¨å¤è¾¹å½¢çåé¨
{
    int i;
    Point b,c,d;
    b.y=a.y;
    b.x=1e15;//å®ä¹å°çº¿
    int flag=0;
    int count=0;
    for(i=0; i<n; i++)
    {
        c = p[i];
        d = p[i + 1];
        if(on_segment(c,d,a))//è¯¥ç¹å¨å¤è¾¹å½¢çä¸æ¡è¾¹ä¸
            return 1;
        if(abs(c.y-d.y)<eps)
            continue;
        if(on_segment(a,b,c))//åé¡¶ç¹ç¸äº¤çæåµï¼å¦æyå¼è¾å¤§åå
        {
            if(c.y>d.y)
                count++;
        }
        else if(on_segment(a,b,d))//åé¡¶ç¹ç¸äº¤çæåµï¼å¦æyå¼è¾å¤§åå
        {
            if(d.y>c.y)
                count++;
        }
        else if(segments_intersect(a,b,c,d))//åè¾¹ç¸äº¤
            count++;
    }
    return count%2;//å½Låå¤è¾¹å½¢çäº¤ç¹æ°ç®Cæ¯å¥æ°çæ¶åï¼På¨å¤è¾¹å½¢åï¼æ¯å¶æ°çè¯På¨å¤è¾¹å½¢å¤ã
}

bool Intersect(Point s,Point e,Point a,Point b)
{
    return direction(e,a,s)*direction(e,b,s)<=0;
}//æå¨ç´çº¿ç¸äº¤

double calculate(Point s,Point e)
{
    int i,j,k=0;
    double sum;
    Point a,b,temp;
    for(i=0; i<n; i++) //éåææç¹è®¡ç®äº¤ç¹
    {
        a=p[i];
        b=p[i+1];
        if(abs(direction(e,a,s))<eps&&abs(direction(e,b,s))<eps)
        {
            px[k++]=a;
            px[k++]=b;
        }
        else if(Intersect(s,e,a,b))//ä¸¤ç´çº¿ç¸äº¤
        {
            px[k++]=intersection(s,e,a,b);//ä¸¤ç´çº¿äº¤ç¹
        }
    }
    if(k==0)
        return 0.0;
    sort(px,px+k,cmp); // æåºï¼ç±äºå²çº¿æ¯ç´çº¿ï¼æä»¥äº¤ç¹å¿å®çº¿æ§åå¸
    px[k]=px[0];
    sum=0;
    for(i=0; i<k-1; i++)
    {
        a=px[i];
        b=px[i+1];
        temp.x=(a.x+b.x)/2.0;
        temp.y=(a.y+b.y)/2.0;
        if(InPolygon(temp))//å¦æä¸¤ç¹çä¸­ç¹å¨å¤è¾¹å½¢å¤é¨ï¼è¯´æç´çº¿å¨å¤é¨
            sum+=dist(a,b);
    }
    return sum;
}

int main()
{
    int q,i,j;
    double sum;
    Point s,e;
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    while(~scanf("%d%d",&n,&q))
    {
        if(q==0&&n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n]=p[0];
        for(j=0; j<q; j++)
        {
            scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);
            sum=calculate(s,e);
            printf("%.3f\n",sum);
        }
    }
    return 0;
}
