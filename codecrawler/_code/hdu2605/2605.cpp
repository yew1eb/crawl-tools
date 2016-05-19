#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int cal(int x,int y)  
{  
   int ans=1;  
   while(y)  
   {  
     if(y&1)  
       ans=(ans*x)%100;  
     y>>=1;  
    x=(x*x)%100;  
   }  
   return ans;  
} 
int rr[25];
int main()
{
    __int64 n,nn;
    for(int i=1; i<=20; ++i)
    {
      rr[i]=cal(2,i+20-1);
      rr[i]=rr[i]*rr[i]+rr[i];
      rr[i]%=100;
    }
    while(scanf("%I64d",&n)&&n!=0)
    {
      long long count=0;
      while(n--)
      {
        count++;
        scanf("%I64d",&nn);
        printf("Case %d: ",count);
        if(nn==1) printf("2\n");
        else if(nn==2) printf("6\n");
        else 
        {
          nn=(nn+19)%20+1;
          printf("%d\n",rr[nn]);
        }
      }
      printf("\n");
    }
    return 0;
}