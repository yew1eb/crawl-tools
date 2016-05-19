#include <cstdio>
 #include <cmath>
 #include <iostream>
 
 using namespace std;
 
 typedef struct point
 {
     double x,y,z;
 }point;
 
 point a[10];
 
 double judge(double x,double y,double z,point q)
 {
     double sum = (x-q.x)*(x-q.x) + (y-q.y)*(y-q.y) +(z-q.z)*(z-q.z);
     sum = sqrt(sum);
     return sum;
 }
 
 int main()
 {
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int i = 0;
         for(i = 0; i < 8; i++)
             scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
         point b;
         double r1;
         scanf("%lf%lf%lf%lf",&b.x,&b.y,&b.z,&r1);
         double flag = 0;
         double kk;
         double xmin,xmax,ymin,ymax,zmin,zmax;
         double x,y,z;
 
         xmin = a[0].x;xmax = a[0].x;
         ymin = a[0].y;ymax = a[0].y;
         zmin = a[0].z;zmax = a[0].z;
 
         for(i = 1; i < 8; i++)
         {
             if(a[i].x < xmin) xmin = a[i].x;
             if(a[i].x > xmax) xmax = a[i].x;
             if(a[i].y < ymin) ymin = a[i].y;
             if(a[i].y > ymax) ymax = a[i].y;
             if(a[i].z < zmin) zmin = a[i].z;
             if(a[i].z > zmax) zmax = a[i].z;
 
         }
         if(b.x < xmin) x = xmin;
         else if(b.x > xmax) x= xmax;
         else x = b.x;
 
         if(b.y < ymin) y = ymin;
         else if(b.y > ymax) y= ymax;
         else y = b.y;
 
         if(b.z < zmin) z = zmin;
         else if(b.z > zmax) z= zmax;
         else z = b.z;
 
     if( judge(x,y,z,b) > r1)
         printf("No\n");
     else
         printf("Yes\n");
     }
     return 0;
 }