#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=155555;
int dp[2][3][N];		//0跳过去，1升、2降
int max(int a,int b){
	return a>b?a:b;
}
int main()
{
	int i,l,j;
	int n,time,temp;
	while(scanf("%d",&n)!=-1)
	{
		time=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			//不吃
			for(l=0;l<3;l++)
			{
				dp[0][0][i]=max(dp[0][0][i],dp[0][l][i-1]);
				dp[1][0][i]=max(dp[1][0][i],dp[1][l][i-1]);
			}
			//奇数吃升高
			for(l=0;l<3;l++)	dp[1][1][i]=max(dp[1][1][i],dp[0][l][i-1]+temp);
			//偶数吃降低
			for(l=0;l<3;l++)	dp[0][0][i]=max(dp[0][0][i],dp[1][l][i-1]-temp);
		}

		int ans=0;
		for(l=0;l<3;l++)
		for(j=0;j<2;j++)
			if(dp[j][l][n]>ans)	ans=dp[j][l][n];
		cout<<ans<<endl;
	}
	return 0;
}