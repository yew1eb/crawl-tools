#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
 long long sums=0;
void  z1(int x,int y)
{
    for(int  i=1;i<x;i++)
    {
        if(i+x-i>y&&i+y>x-i&&x-i+y>i)
        sums++;
    }
    for(int  i=1;i<y;i++)
    {
        if(i+y-i>x&&i+x>y-i&&y-i+x>i)
        sums++;
    }
}
void z2(int x)
{
    if(x%2==0)
    {
        //if(x<6)return ;
        long long ss=0;
      for(int i=1;i<x;i++)
       {
           if(i+i>x-i-i&&i+x-i-i>i)ss++;
       }
    long long ts=0;
      double xx=(1.0*x*x)/48.0;
      if(xx-(long long)xx>=0.5)ts=(long long)xx+1;
      else ts=(long long)xx;
       sums+=(ts-ss)*6;
       if(x%3==0){sums+=1;ss--;}
       ss=ss*3;
       sums+=ss;
    }
    else
    {
       // if(x<5)return ;
        long long ss=0;
         long long ts=0;
       for(int i=1;i<x;i++)
       {
           if(i+i>x-i-i&&i+x-i-i>i)ss++;
       }
        double xx=(x+3.0)*(3.0+x)/48.0;
        if(xx-(long long)xx>=0.5)ts=(long long)xx+1;
      else ts=(long long)xx;
       sums+=(ts-ss)*6;
       if(x%3==0){sums+=1;ss--;}
       ss=ss*3;
       sums+=ss;
    }
}
int main()
{

   int n,m;
   while(~scanf("%d%d",&n,&m))
   {
       int tx;
       int ll=n,rr=0;
       for(int i=0;i<m;i++)
       {
           scanf("%d",&tx);
           if(tx<=ll)ll=tx;
           if(tx>=rr)rr=tx;
       }
       int l=ll-1;int r=rr+1;
      sums=0;
       if(l>=1&&r<=n)
       {
           z1(l,n-r+1);
       }
       else
       {

           if(l<1&&r<=n)
           {
               z2(n-r+1);
           }
           else if(r>n&&l>=1)
           {
               z2(l);
           }
       }
       printf("%I64d\n",sums);
   }
    return 0;
}
