#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e6+100;
int n,m,test;
int a[maxn];
ll dp[44][maxn];

ll solve()
{
   memset(dp,0,sizeof(dp));
   dp[1][0]=dp[1][a[1]]=1;
   for(int i=2;i<=n;i++)
   {
      for(int j=0;j<maxn;j++)dp[i][j]+=dp[i-1][j];
      for(int j=0;j<maxn;j++)dp[i][a[i]^j]+=dp[i-1][j];
   }
   ll ans=0;
   for(int i=m;i<maxn;i++)
    ans+=dp[n][i];
   return ans;
}

int main()
{
   int T,test=1;
   scanf("%d",&T);
   while( T-- )
   {
       scanf("%d%d",&n,&m);
       for(int i=1;i<=n;i++)
         scanf("%d",&a[i]);

       ll ans=solve();
       printf("Case #%d: %lld\n",test++,ans);
   }
   return 0;
}
