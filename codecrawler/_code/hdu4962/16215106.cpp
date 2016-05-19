#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
//åºç¡ç¹ååéè¿ç®
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p){return Vector(A.x/p,A.y/p);}
bool operator <(const Point& a, const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
const double eps=1e-10;
int dcmp(double x)//å¤æ­æ­£è´ï¼æèç­äº0
{
    if(fabs(x)<eps)return 0;else return x<0?-1:1;
}
bool operator==(const Point& a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}//ç¹ç§¯
double Length(Vector A){return sqrt(Dot(A,A));}//OAé¿
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}//OAåOBçå¤¹è§
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}//åç§¯

//ç¹åç´çº¿
//P+tvè¡¨ç¤ºä¸æ¡ç´çº¿ï¼Pä¸ºç¹ï¼tvä¸ºæ¹ååé
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)//æ±ç´çº¿äº¤ç¹ï¼ç¡®ä¿å­å¨äº¤ç¹ï¼å³Cross(v,w)é0
{
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}



const int maxn=1e3+10;
struct node{
    double x;
    int dir;
}e[maxn];
Point p[maxn],f[maxn];
int t;
int cmp(node a,node b)
{
    return a.x<b.x;
}
int cmp2(Point a,Point b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,tot=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n]=p[0];
        p[n+1]=p[1];
        Point x(1,0),out,O(0,0),c;
        t=0;
        for(i=1;i<=n;i++)
        {
            if(dcmp(p[i].y)==0)
            {
                //printf("*%d\n",i);
                if(dcmp(p[i-1].y)*dcmp(p[i+1].y)<0)
                {
                    e[t].dir=dcmp(p[i-1].y);
                    e[t++].x=p[i].x;
                }
                else
                {
                    e[t].dir=0;
                    e[t++].x=p[i].x;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(dcmp(p[i].y)==0&&dcmp(p[i+1].y)==0)
            {
                f[tot].x=min(p[i].x,p[i+1].x);
                f[tot++].y=max(p[i].x,p[i+1].x);
                continue;
            }
            if(dcmp(p[i].y)!=0&&dcmp(p[i+1].y)!=0)
            {
                if(dcmp(p[i].y*p[i+1].y)<0)
                {
                    out=GetLineIntersection(O,x,p[i],p[i+1]-p[i]);
                    //printf("out:%f %f %d %d\n",out.x,out.y,i,i+1);
                    e[t].x=out.x;
                    if(dcmp(p[i].y)>0)e[t++].dir=1;
                    else e[t++].dir=-1;
                }
            }
        }
        sort(e,e+t,cmp);
        sort(f,f+tot,cmp2);
        //for(i=0;i<t;i++)printf("**%d %f %d\n",i,e[i].x,e[i].dir);
        //for(i=0;i<tot;i++)printf("***%d %f %f\n",i,f[i].x,f[i].y);
        int ans=0,now=0;
        for(i=0,j=0;i<t-1;i++)
        {

            c.x=(e[i].x+e[i+1].x)/2;
            c.y=0;
            now+=e[i].dir;
            while(j<tot&&dcmp(e[i].x-f[j].y)>0)j++;
            if(j<tot&&dcmp(e[i].x-f[j].x)>=0)continue;
            ans=max(ans,now);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
10
5
1 1
-1 0
1 -1
0 1
0 -1
6
-1 1
-1 -1
1 -1
1 1
2 0
-2 0
*/
