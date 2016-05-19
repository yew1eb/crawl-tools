#include <stdio.h>

int main()
{
	int i,j,k,g,tem,val,length,n,locate;
	const int size = 201;
	int dp[21][size];
	int len[21]={0,0,2,3};
	bool flag;
	dp[2][0] = 0,dp[2][1] = 1;
	dp[3][0] = 0,dp[3][1] = 2,dp[3][2] = 3;
	/*打表*/
	for (i=4;i<=20;i++)
	{
		dp[i][0] = 0;/*N根线都平行，则交点为0*/
		dp[i][1] = i-1;/*有N根线，N-1条线平行，剩下的一条线，则肯定跟这N-1条线有N-1个交点*/
		dp[i][2] = i*(i-1)/2;/*N根线最多有这么多的交点*/
		len[i] = 3;
	}
	for (i=4;i<=20;i++)
	{
		for (j=i-2;j>=2;j--)
		{
			tem = (i-j)*j;/*i-j条边平行，j条边自由*/
			for (k=0;k<len[j];k++)
			{
				val = tem+dp[j][k];/*某种交点个数*/
				/*插入排序*/
				locate = len[i]-1;
				flag = true;
				for (g=0;g<len[i];g++)
				{
					if (dp[i][g]>val)
					{
						locate = g;
						break;
					}
					else if(dp[i][g] == val)
					{
						flag = false;/*标记当前交点个数已经在表中*/
						break;
					}
				}
				if(!flag)/*表中已存在该值，则不插入*/
					continue;
				if(locate==len[i]-1)/*如果val是当前表中最大的，则插入到表末尾*/
				{
					dp[i][len[i]] = dp[i][locate];
					dp[i][locate] = val;
				}
				else/*插入表中央*/
				{
					for (g=len[i]-1;g!=locate-1;g--)
						dp[i][g+1] = dp[i][g];
					dp[i][locate] = val;
				}				
				len[i]++;/*更新长度*/
			}
		}
	}
	while (scanf("%d",&n)!=EOF)
	{
		length = len[n];
		for (i=0;i<length;i++)
		{
			if(i)
				printf(" ");
			printf("%d",dp[n][i]);
		}
		printf("/n");
	}
	return 0;
}