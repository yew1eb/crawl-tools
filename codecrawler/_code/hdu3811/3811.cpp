#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,m;
__int64 fac[18];
int ban[18][18];
__int64 dp[1<<17];
void ini()
{
	int i;
	fac[0]=1;
	for(i=1;i<=17;i++)	fac[i]=fac[i-1]*i;
}
void getban()
{
	int a,b;
	memset(ban,0,sizeof(ban));
	while(m--)
	{
		scanf("%d%d",&a,&b);
		a--;b--;
		ban[a][b]=1;
	}
}
void getdp()
{
	int i,j,k;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=0;i<n;i++)                //对位枚举
	for(j=(1<<n)-1;j>=0;j--)        //注意，j的二进制位中的每一位数字表示的是：该数字是否已被用
	{
		if(!dp[j])	continue;
		for(k=0;k<n;k++)            //当前位如果为空的情况下，枚举填入数字
		{
			if(j&(1<<k))	continue;   //当前位不为空
			if(ban[i][k])	continue;
			dp[j|(1<<k)]+=dp[j];
		}
	}
}
int main()
{
	int T,Case;
	ini();
	scanf("%d",&T);
	for(Case=1;Case<=T;Case++)
	{
		scanf("%d%d",&n,&m);
		getban();
		getdp();
		printf("Case %d: %I64d\n",Case,fac[n]-dp[(1<<n)-1]);
	}
	return 0;
}