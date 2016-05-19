#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 1000000007
using namespace std;
#define bug puts("bugbugubgbugbug");
long long l,r;
int main()
{
    long long t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=-1;
         scanf("%lld%lld",&l,&r);
         while(l%11!=3)
            l++;
         for(long long i=l;i<=r;i+=11)
         {
             long long sum1=0;
             long long ii=i;
             while(ii)
             {
                 sum1=sum1+ii%10;
                 ii=ii/10;
                 sum1=sum1-ii%10;
                 ii=ii/10;
             }
             if(sum1!=3)
                {
                    ans=i;
                break;
                }
         }
         printf("%lld\n",ans);

    }
}
