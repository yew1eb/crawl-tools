#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
   int a[102],m,i,sum,s,count;
   while(scanf("%d",&m)!=EOF&&m)
   {
       sum=count=0;
      for(i=0;i<m;i++)
      {
         scanf("%d",&a[i]);
         sum=sum^a[i];
      }
      for(i=0;i<m;i++)
      {
         s=sum^a[i];
         if(s<a[i])
             count++;
      }
      printf("%d\n",count);
   }
   return 0;
}