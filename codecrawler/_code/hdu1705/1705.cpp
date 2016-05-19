#include<iostream>
using namespace std;
#include<math.h>
struct point
{
  int x,y;  
}p[3];
struct node
{
 int fx,fy;  
}m[3];
int gcd(int a,int b)
{
 if(b==0) return a;
 return gcd(b,a%b);  
}
int ABS(int x)
{
 return x>0?x:-x;  
}
int AREA(point p1,point p2,point p0)
{
  return ABS((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));  
}
int main()
{
 int sum,area,ans;
 while(scanf("%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)!=EOF)
 {
  if(p[0].x==0&&p[0].y==0&&p[1].x==0&&p[1].y==0&&p[2].x==0&&p[2].y==0) break;
  m[0].fx=ABS(p[0].x-p[1].x);    m[0].fy=ABS(p[0].y-p[1].y);
  m[1].fx=ABS(p[1].x-p[2].x);    m[1].fy=ABS(p[1].y-p[2].y);
  m[2].fx=ABS(p[0].x-p[2].x);    m[2].fy=ABS(p[0].y-p[2].y);
  sum=gcd(m[0].fx,m[0].fy)+gcd(m[1].fx,m[1].fy)+gcd(m[2].fx,m[2].fy);//求a
  area=AREA(p[1],p[2],p[0]);//求S
  ans=(area-sum+2)/2;
  printf("%d\n",ans);
 }  
}