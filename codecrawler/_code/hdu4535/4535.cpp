#include<cstdio>
#include<cstring>
typedef __int64 LL;
const LL mod=1e9+7;
const int MAXN=100+10;
LL dp[MAXN];

int main()
{
   memset(dp,0,sizeof(dp));
   dp[1]=0;dp[2]=1;
   for(int i=3;i<=100;i++)         //错排公式  
		dp[i]=(i-1)*((dp[i-1]+dp[i-2]))%mod;
 
   int T;
   scanf("%d",&T);
    while(T--)
   {
   		int n;
   		scanf("%d",&n);
   		printf("%I64d\n",dp[n]);
   }
   	return 0;
}
