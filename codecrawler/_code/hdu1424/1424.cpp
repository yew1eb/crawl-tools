#include<cstdio>
#include<algorithm>
using namespace std;
#define min(x,y) (x)<(y)?(x):(y)
int a[2005];
int dp[2005][2005/2];
void work(int n,int k)
{
	int i,j;
	dp[0][0] = 0;//当取0件的时候所耗费的精力为0
	for(i = 2; i <= n; i++)
	{
		dp[i][0] = 0;
		for(j = 1; j <= i/2 ; j++)
			if(i -1 >= j*2)//当i-1>= j*2的时候
				dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]));
			else//当i-1< j*2的时候
				dp[i][j] = dp[i-2][j-1] + (a[i-1]-a[i])*(a[i-1]-a[i]);
	}
	printf("%d\n",dp[n][k]);//输出最小的疲劳度。
}
int main()
{
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		for(i = 1; i <= n; i++)//输入数据，输入从1开始。
			scanf("%d",a+i);
		sort(a+1,a+n+1);//将元素从小到大进行排序。
		work(n,k);
	}
	return 0;
}