#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max(a,b) a>b?a:b
#define Size 100005
int c[2*Size],w[2*Size],dp[200005];
int main()
{
	int sum,i,num[7],no = 1,len,j,k,tem;
	while (1)
	{
		sum = 0;
		for (i=1;i<=6;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i]*i;
		}
		if(!sum)
			break;
		if(sum&1)
		else
		{
			len = 0;
			for (i=1;i<=6;i++)
			{
				/*二进制划分,转成01背包做*/
				if(num[i])
				{
					k =(int)(log(num[i]+1)/log(2))-1;
					for (j=0;j<=k;j++)
					{
						c[len] = w[len] = (int)(pow(2.0,j)*i);
						len++;
					}
					tem = (int)(pow(2.0,k+1))-1;
					if(num[i]!=tem)
					{
						c[len] = w[len] = (num[i]-tem)*i;
						len++;
					}
				}
			}
			for(i=0;i<=sum;i++)
				dp[i] = 0;
			for (i=0;i<len;i++)
			{
				for (j = sum/2;j>=c[i];j--)
				{
					dp[j] = Max(dp[j],dp[j-c[i]]+w[i]);
				}
			}
			if(dp[sum/2] == sum/2)
				printf("Collection #%d:/nCan be divided./n/n",no++);
			else
				printf("Collection #%d:/nCan't be divided./n/n",no++);
		}
	}
	return 0;
}