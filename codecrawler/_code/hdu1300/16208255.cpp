#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define PF(x) (scanf("%d",&x))
#define PT(x,y) (scanf("%d%d",&x,&y))
#define PR(x) (printf("%d\n",x))
#define PRT(x,y)(printf("%d %d\n",x,y))
#define PB(x)(scanf("%I64d",&x))
#define PRB(x)(printf("%I64d\n",(x)))
typedef __int64 LL;
#define N 105
#define M 105
#define Mod 1000
#define Inf 0x7fffffff

int a[N],p[N],sum[N],sp[N];
int dp[N];

void init()
{
    int test;
    PF(test);
    while(test--)
    {
       int n;
       PF(n);
       int var = 0,sv=0;
       for(int i=0;i<n;i++)
       {
           PT(a[i],p[i]);
           sp[i] = sv+a[i];
           sv = sp[i];
           sum[i] = (sp[i]+10)*p[i];
       }
       for(int i=0;i<n;i++)
       {
           if(i)
           {
               dp[i] = sum[i];
               for(int j=0;j<=i;j++)
                   if(dp[i]>dp[j]+(sp[i]-sp[j]+10)*p[i])
                       dp[i] = dp[j]+(sp[i]-sp[j]+10)*p[i];
           }
           else
           {
               dp[i] = (a[i]+10)*p[i];
           }
       }
       PR(dp[n-1]);
    }
    return ;
}

int main()
{
    init();
    return 0;
}