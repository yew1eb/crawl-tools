#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define len 0x7fffffff
using namespace std;
struct node
{
   __int64 num;
   int p;
};
node q1[1000010];
//int p[1000010];
int main()
{
   __int64  a,b;
   int  n,i,t;
   while(~scanf("%d%I64d%I64d",&n,&a,&b))
   {
       __int64 ti=1;
         __int64  s=1;

       int head=0,r=0;
    for(i=1;i<=n;i++)
       {
           s=(s*a)%b;
            while(head<r&&q1[r].num>=s) r--;
            q1[++r].num=s;
             q1[r].p=i;
        while(q1[head+1].p<i-a)
                  head++;
            ti=(ti*q1[head+1].num)%b;
         
        }
       printf("%I64d\n",ti);
   }
   return 0;
}