#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
typedef __int64 ll;
#define MOD 65536
int dp[20][1<<17],sum_dp[20][1<<17];
int calc_dp()
{
	int k,vk;
 for(k=16;k>=2;k--)
	{
		for(vk=0;vk<(1<<k);vk++)
			dp[k-1][vk%(1<<(k-1))]+=dp[k][vk];
	}
 memset(sum_dp,0,sizeof(sum_dp));
	for(k=1;k<=16;k++)
	{
		sum_dp[k][0]=dp[k][0];
		for(vk=1;vk<(1<<k);vk++)
			sum_dp[k][vk]=sum_dp[k][vk-1]+dp[k][vk];
	}
	return 0;
}
int main()
{
 int n,i,j,x,c,cc,ans,cas=0;
 char query[100];
 int q;
 while(scanf("%d",&n)!=EOF)
 {
	 if (n==-1) break;
	 memset(dp,0,sizeof(dp));
	 for(i=1;i<=n;i++)
	 {
		 scanf("%d",&x);
		 dp[16][x%MOD]++;
	 }
	 calc_dp();
	 c=0;
	 ll ans=0;
 while(scanf("%s",query)!=EOF)
	 {
		 if (query[0]=='E') break;
		 if (query[0]=='C') {scanf("%d",&q);c=(c+q)%MOD;}
		 if (query[0]=='Q') 
		 {
			 scanf("%d",&q);
			 q++;
			 int flag=((1<<(q-1))&c);
			 cc=c%(1<<(q-1));
			 if (flag==0)
			 {
			 ans+=sum_dp[q][(1<<(q-1))-1]-sum_dp[q][(1<<(q-1))-cc-1];
			 ans+=sum_dp[q][(1<<(q-1))+(1<<(q-1))-1-cc]-sum_dp[q][(1<<(q-1))-1];
			 }
			 else
			 {
				ans+=sum_dp[q][(1<<(q-1))+(1<<(q-1))-1]-sum_dp[q][(1<<(q-1))+(1<<(q-1))-cc-1];
			 ans+=sum_dp[q][(1<<(q-1))-1-cc];
			 }
			 // printf("%I64d\n",ans);
		 }
	 }
 printf("Case %d: %I64d\n",++cas,ans);
 }
}
/*
16
1
2
4
8
16
32
64
128
256
512
1024
2048
4096
8192
16384
32768
Q 0
C 1
Q 0
*/