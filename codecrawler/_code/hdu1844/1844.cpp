/*状态方程为dp[j]=max(dp[j],dp[j-1]+money[i]);
即报销j个发票所得到的最大经费，可以第j个是报销的，
也可以是第j个不报销而最大经费是由前j-1个发票加上另外第i个发票的报销数额*/
#include <stdio.h>
#include <string.h>

int main()
{
	double sum,Q,asum,bsum,csum,price,ans;
	double dp[35],money[35];
	int n,m,num,i,j,flag;
	char ch;
	while(scanf("%lf %d",&Q,&n)&&n)
	{
		num=0;
		memset(dp,0,sizeof(dp));
		memset(money,0,sizeof(money));
		for (i=0;i<n;i++)
		{
			flag=1;
			sum=asum=bsum=csum=0.0;
			scanf("%d",&m);
			for (j=0;j<m;j++)
			{
				getchar();
				scanf("%c:%lf",&ch,&price);
				if(ch!='A'&&ch!='B'&&ch!='C'||price>600.0)
				{
					flag=0;
					break;
				}
				else if(ch=='A')
				    asum+=price;
				else if(ch=='B')
					bsum+=price;
				else
					csum+=price;
			}
			sum=asum+bsum+csum;
			if(flag&&sum<=1000.0&&asum<=600.0&&bsum<=600.0&&csum<=600.0)
			{
				money[num]=sum;
				num++;
			}
		}
		for (i=0;i<=num;i++)
		{
			for(j=num;j>=1;j--)
				if(j==1||dp[j-1]>0&&dp[j-1]+money[i]<=Q)
					dp[j]=dp[j]>(dp[j-1]+money[i])?dp[j]:(dp[j-1]+money[i]);
		}
		ans=0.0;
		for(i=0;i<=num;i++)
			if(ans<dp[i])
				ans=dp[i];
		printf("%.2lf\n",ans);
	}
	return 0;
}