#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int N = 5005;
#define LL __int64


int main()
{
   LL n;
   int a[100],T;
   scanf("%d",&T);
   while(T--)
   {
       scanf("%I64d",&n);
       int k=0,flag=0;
       while(n){
            if(n&1){
                if(flag==0)k++; flag=1;
            }
            else flag=0;
            n/=2;
       }
       printf("%d\n",k);
   }
    return 0;
}
