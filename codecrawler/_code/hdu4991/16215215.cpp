#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int mod=123456789;
using namespace std;
ll a[10100],b[10100],c[10100],dp[10100][110];
int  n,m;
int lowbit(int t)
{
 return t&(-t);
}
void modify(int t,ll d)
{
  while(t<=n)
  {
   c[t]+=d;
   t+=lowbit(t);
  }
}
ll getsum(int t)
{
  ll ans=0;
  while(t>0)
  {
    ans=(ans+c[t])%mod;
    t-=lowbit(t);
  }
  return ans;
}

int main()
{
        while(scanf("%d%d",&n,&m)!=EOF)
        {
          for(int i=1;i<=n;i++)
          {
            scanf("%I64d",&a[i]);
            b[i]=a[i];
          }
          sort(b+1,b+1+n);
          memset(dp,0,sizeof(dp));
          for(int i=1;i<=n;i++)dp[i][1]=1;
          for(int j=2;j<=m;j++)
          {
            memset(c,0,sizeof(c));
            for(int i=1;i<=n;i++)
            {
             int indx=lower_bound(b+1,b+1+n,a[i])-b;
             dp[i][j]=getsum(indx-1);
             modify(indx,dp[i][j-1]);
            }
          }
          ll cnt=0;
          for(int i=1;i<=n;i++)
          {
           cnt=(cnt+dp[i][m])%mod;
          }
          printf("%I64d\n",cnt%mod);
        }

        return 0;
}
