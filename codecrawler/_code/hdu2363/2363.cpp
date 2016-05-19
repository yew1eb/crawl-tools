#include <cstdio>

int Min(int a,int b){return a<b?a:b;}

const int INF = 0x3f3f3f3f;
int n,e,d,ans;
int dp[21][101][101];

int main()
{
	while (scanf("%d%d%d",&n,&e,&d)==3)
	{
		ans=INF;
		for (int i=0;i<=n;i++)
			for (int j=0;j<=e;j++)
				for (int k=0;k<=d;k++)
					dp[i][j][k]=INF;
		dp[n][e][0]=0;
		for (int k=0;k<=d;k++)
			for (int i=n;i>=1;i--)
				for (int j=e;j>=0;j--)
				{
					if (dp[i][j][k]==INF) continue;
					if (k==d) ans=Min(ans,dp[i][j][k]);
					for (int x=1;x+k<=d;x++)
					{
						if (j>=x*x)
							dp[i][j-x*x][k+x]=Min(dp[i][j-x*x][k+x],dp[i][j][k]+1);
						if (i>=2 && e-k-x*x>=0)
							dp[i-1][e-k-x*x][k+x]=Min(dp[i-1][e-k-x*x][k+x],dp[i][j][k]+1);
					}
				}
		if (ans==INF) puts("0");
		else printf("%d\n",ans);
	}
	return 0;
}