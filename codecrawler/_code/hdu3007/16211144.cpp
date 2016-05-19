#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm> 
using namespace std;
const double eps=1e-8;
struct Point{
    double x,y; 
}p[505];
double dis(const Point &a,const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
} 
Point circumcenter(const Point &a,const Point &b,const Point &c)
{ //è¿åä¸è§å½¢çå¤å¿ 
    Point ret; 
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    ret.x=a.x+(c1*b2-c2*b1)/d;
    ret.y=a.y+(a1*c2-a2*c1)/d;
    return ret; 
} 
void min_cover_circle(Point *p,int n,Point &c,double &r){ //cä¸ºåå¿ï¼rä¸ºåå¾ 
    random_shuffle(p,p+n); // 
    c=p[0]; r=0;
    for(int i=1;i<n;i++)
    {
        if(dis(p[i],c)>r+eps)  //ç¬¬ä¸ä¸ªç¹
        { 
            c=p[i]; r=0;
            for(int j=0;j<i;j++)
                if(dis(p[j],c)>r+eps) //ç¬¬äºä¸ªç¹
                {
                    c.x=(p[i].x+p[j].x)/2;
                    c.y=(p[i].y+p[j].y)/2;
                    r=dis(p[j],c);
                    for(int k=0;k<j;k++)
                        if(dis(p[k],c)>r+eps) //ç¬¬ä¸ä¸ªç¹
                        {//æ±å¤æ¥ååå¿ï¼ä¸ç¹å¿ä¸å±çº¿ 
                            c=circumcenter(p[i],p[j],p[k]); 
                            r=dis(p[i],c); 
                        } 
                }  
        }    
    } 
} 
int main(){
    int n;
    Point c;
    double r; 
    while(scanf("%d",&n)==1 && n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        min_cover_circle(p,n,c,r);                    
        printf("%.2lf %.2lf %.2lf\n",c.x,c.y,r);                   
    } 
    return 0;
}