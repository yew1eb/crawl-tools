#define _CRT_SECURE_NO_WARNINGS
 #include<iostream>
 #include<cstdio>
 #include<cmath>
 using namespace std;
 
 int main(){
     double h,u,d,f;
     while(~scanf("%lf",&h)&&h){
         scanf("%lf%lf%lf",&u,&d,&f);
         int day=0;
         bool flag=true;
         double dist=0,s=u*f/100;
         while(1){
             day++;
             dist+=u;
             if(dist>h)break;
             dist-=d;
             if(dist<0){flag=false;break;};
             u-=s;
             if(u<0)u=0;
         }
         if(flag){
             printf("success on day %d\n",day);
         }else 
             printf("failure on day %d\n",day);
     }
     return 0;
 }