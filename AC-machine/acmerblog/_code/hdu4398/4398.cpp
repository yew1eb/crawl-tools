#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<list>
#include<queue>
#define eps 1e-6
#define INF (1<<30)
#define PI acos(-1.0)
using namespace std;

int dp[10][82][82][82];
int pos[15];

int dfs(int cur,int lastf,int lastx,int mod,int flag)
{
   if(!cur)
   {
      if(lastx==0&&lastf==mod)
         return 1;
      return 0;
   }

   if(!flag&&dp[cur][lastf][lastx][mod]!=-1)
      return dp[cur][lastf][lastx][mod];

   int Max=flag?pos[cur]:9;
   int ans=0;

   for(int i=0;i<=Max;i++)
   {
      ans+=dfs(cur-1,lastf+i,(lastx*10+i)%mod,mod,flag&&i==Max);
   }
   if(!flag)
      dp[cur][lastf][lastx][mod]=ans;

   return ans;
}

int Cal(int n)
{
   int tt=0;

   while(n)
   {
      ++tt;
      pos[tt]=n%10;
      n/=10;
   }

   int temp=0;
   for(int i=1;i<=81;i++)
      temp+=dfs(tt,0,0,i,1);  //把各位数之和为i的满足题意数的个数全部找出来，简化的关键
   return temp;
}

int main()
{
   int t,a,b;

   scanf("%d",&t);
   memset(dp,-1,sizeof(dp));
   for(int ca=1;ca<=t;ca++)
   {
      scanf("%d%d",&a,&b);
      printf("Case %d: %d\n",ca,Cal(b)-Cal(a-1));
   }

   return 0;
}

