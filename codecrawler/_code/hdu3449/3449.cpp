#include<stdio.h>
#include<string.h>
#define wsize 100010
#define nsize 65
#define msize 11
int dp[nsize][wsize];
int n,t,box,num;
int max(int a,int b)
{
	return a>b?a:b;
}
int main ()
{
	int i,j,k;
	while(scanf("%d %d",&n,&t)!=EOF)
	{
		memset(dp,-1,sizeof(dp));   //有依赖关系，要赋初值-1
		memset(dp[0],0,sizeof(dp[0]));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&box,&num);
			for(k=box;k<=t;k++)
				dp[i][k]=dp[i-1][k-box];  //先让i层买盒子，因为盒子没有价值，所以直接等于上一层的花费+盒子钱
			for(j=0;j<num;j++)             //在已花费盒子钱的基础上，此时再对dp[i]层做01背包，即i层一个盒子多种物品的最大价值       
			{
				int c,w;
				scanf("%d %d",&c,&w); 
				for(k=t;k>=c;k--)    
				{
					if(dp[i][k-c]!=-1)  //注意依赖背包有不可能的情况，这里即k买不到盒子和这个物品，不能装物品
						dp[i][k]=max(dp[i][k],dp[i][k-c]+w);  // 这里不能dp[i][k]=max(dp[i][j],dp[i][k-box-c]+w) 因为已经										买过盒子了，这个表达式代表一个盒子基础上一个物品带一个盒子
				}
			}
			for(j=0;j<=t;j++)
			{               // 不买这组    买这组
				dp[i][j]=max(dp[i-1][j],dp[i][j]);  //不要忘了考虑不选当前组的情况（不是必选）
			}
		}
		printf("%d\n",dp[n][t]);
	}
	return 0;
}