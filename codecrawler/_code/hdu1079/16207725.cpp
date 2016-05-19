#include<iostream>
#include<string.h>
using namespace std;
int sg[500][20][40];
int day[400];
int mm[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int g(int y , int m , int d)
{
    if(sg[y][m][d]!=-1) return sg[y][m][d];
    int flag=0;
    if(y>101) return sg[y][m][d]=0;
    if(m==2 && d==day[y] || m<12 && mm[m]==d && mm[m+1]>=d)
    {
        int a=g(y,m+1,d) , b=g(y,m+1,1);
        if(a==0 || b==0) return sg[y][m][d]=1;
        else if(a && b)  return sg[y][m][d]=0;
    }
    else if(m<12 && mm[m]==d && mm[m+1]<d)
    { 
        int a=g(y,m+1,1); 
        if(a==0)  return sg[y][m][d]=1;
        else return sg[y][m][d]=0;
    }
    else if(m==2 && d<day[y] || m<12 && d<mm[m] || m==12 && d<mm[12])
    { //cout<<"**************"<<endl; 
        int a=g(y,m,d+1) , b=g(y , m+1 , d);// cout<<"a= "<<a<<"  b= "<<b<<endl;
        if(a==0 || b==0 ) return sg[y][m][d]=1;
        else if(a && b) return sg[y][m][d]=0;
    }
    else if(m==12 && d==mm[12])
    {
        int a=g(y+1 ,1 ,1) , b=g(y+1 ,1, d);
        if(a==0 || b==0) return sg[y][m][d]=1;
        else if(a && b) return sg[y][m][d]=0;
    }
}

int main()
{
   int y,m,d;
   int t;
   memset(sg,-1,sizeof(sg));
   for(int i=1900;i<=2001;i++)
   if(i%4==0&&i%100!=0 || i%400==0) day[i-1900+1]=29; 
   else day[i-1900+1]=28;  
   sg[101][11][4]=0;
   for(int i=5;i<=mm[11];i++) sg[101][11][i]=1;
   for(int i=1;i<=mm[12];i++) sg[101][12][i]=1;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d%d",&y,&m,&d);
       y-=1900; 
       g(y,m,d);// cout<<"**= "<<sg[101][11][4]<<"   "<<sg[101][11][3]<<endl;
       if(sg[y][m][d]==1) printf("YES\n");
       else printf("NO\n");
   }
   return 0;
}
