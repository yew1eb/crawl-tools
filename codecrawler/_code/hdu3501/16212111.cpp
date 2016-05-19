#include<iostream>
#include<cmath>
using namespace std;
const int MM=1000000007;
__int64 euler(__int64 x)
{
        __int64 i,res=x;
        for(i=2;i<(__int64)sqrt(x*1.0)+1;i++)
            if(x%i==0)
            {
                 res=res/i*(i-1);
                 while(x%i==0)
                     x/=i; 
            }
            if(x>1) 
                res=res/x*(x-1);
        return res;
}
int main()
{
    __int64 n,sum,ans;
    while(scanf("%I64d",&n)!=EOF && n)
    {
         sum=n*(n+1)/2-n;
         ans=sum-euler(n)*n/2;
         printf("%I64d\n",ans%MM);
    }
    return 0;
}
