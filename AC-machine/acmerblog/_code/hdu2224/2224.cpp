#include"stdio.h"
#include"string.h"
#include"math.h"
#define N 201
#define inf 99999999
struct node
{
	int x,y;
}A[N];

double D[N][N];
double dp[N][N];
double dis(int a,int b)
{
	return sqrt((double)(A[a].x-A[b].x)*(A[a].x-A[b].x)
		+(A[a].y-A[b].y)*(A[a].y-A[b].y));
}
int main()
{
	int n;
	int i,j;
	while(scanf("%d",&n)!=-1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				D[i][j]=inf;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&A[i].x,&A[i].y);
			for(j=0;j<i;j++)
				D[j][i]=dis(i,j);
		}
		dp[0][1]=D[0][1];
		for(j=2;j<n;j++)
		{
			for(i=0;i<=j-2;i++)//j-1在递增序列
				dp[i][j]=dp[i][j-1]+D[j-1][j];

			dp[j-1][j]=inf;
			for(i=0;i<=j-2;i++)//j-1在递减序列
				if(dp[i][j-1]+D[i][j]<dp[j-1][j])
					dp[j-1][j]=dp[i][j-1]+D[i][j];
		}
		dp[n-1][n-1]=dp[n-2][n-1]+D[n-2][n-1];
		printf("%.2f\n",dp[n-1][n-1]);
	}
	return 0;
}