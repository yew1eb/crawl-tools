 #include <iostream>
 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 
 using namespace std;
 
 #define eps 1e-9
 #define INF 1e15
 
 struct Nod
 {
     double a,b,c;
 }node[10010];
 
 int n;
 
 double func(double a,double b,double c,double x)
 {
     return a*x*x+b*x+c;
 }
 
 double getMins(double x)
 {
     int i;
     double maks = -INF;
     for(i=0;i<n;i++)
     {
         double temp = func(node[i].a,node[i].b,node[i].c,x);
         if(maks<temp)
         {
             maks = temp;
         }
     }
     return maks;
 }
 
 void sanfen()
 {
     double l=0,r=1000,mid,ans = INF;
     while(l<=r)
     {
         mid = (l+r)/2;
         double temp1 = getMins(mid);
         double temp2 = getMins(mid-eps);
         if(temp1<temp2)
         {
             l = mid + eps;
         }
         else
         {
             r = mid - eps;
         }
         if(ans>temp1)
         {
             ans=temp1;
         }
     }
     printf("%.4lf\n",ans);
 }
 
 int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d",&n);
         int i;
         for(i=0;i<n;i++)
         {
             scanf("%lf%lf%lf",&node[i].a,&node[i].b,&node[i].c);
         }
         sanfen();
     }
     return 0;
 }
