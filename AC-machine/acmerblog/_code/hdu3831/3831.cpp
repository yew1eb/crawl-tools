#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
#define mod 1000000007
#define inf 0x7f7f7f7f
#define N 505
int dp[N][N][55];//dp[i][j][k] 表示前i个字符与前j个字符匹配 最后一次使用后缀修改为字符k的状态需要最小的次数
//52表示没有使用过后缀修改
//dp[i][j][k] 可以从删除 dp[i-1][j][k]+1
//dp[i][j][k] 从插入	 dp[i][j-1][k]+1
//dp[i][j][k] 替换       dp[i-1][j-1][k]+1
//dp[i][j][k] 修改后缀	 dp[i-1][j-1][any]+1 if(k==p[j]) dp[i][j][k]=min(dp[i-1][j-1][k]);
char s[N],p[N];
int  a[N],b[N];
int la, lb;
//把s->p最少需要修改s几步
int main()
{
	int i, j, k, u, v;
	while(scanf("%s",s+1),s[1]!='#'){
		scanf("%s",p+1);
		for(i=1;s[i];i++)if(islower(s[i]))a[i] = s[i]-'a';else a[i] = s[i]-'A'+26;
		for(i=1;p[i];i++)if(islower(p[i]))b[i] = p[i]-'a';else b[i] = p[i]-'A'+26;
		memset(dp, inf, sizeof dp);
		la = strlen(s+1), lb = strlen(p+1);

		dp[0][0][52] = 0;
		for(i = 1; i <= la; i++)dp[0][i][52]=dp[i][0][52] = i;
		for(i = 1; i <= la; i++)
		{
			for(j = 1; j <= lb; j++)
			{
				for(k = 0; k < 52; k++)
				{
					u = inf;
					if(b[j]==k)
						u = dp[i-1][j-1][k];
					else 
					{
					u = min(u, dp[i-1][j][k]+1);
					u = min(u, dp[i][j-1][k]+1);
					u = min(u, dp[i-1][j-1][k] +1);
					dp[i][j][b[j]] = min(dp[i][j][b[j]],dp[i-1][j-1][k]+1);
					}
					dp[i][j][k] = min(u, dp[i][j][k]);
				}
				u = inf;
				if(a[i]==b[j])
					u = dp[i-1][j-1][52];
				else {
					u = min(u, dp[i-1][j][52]+1);
					u = min(u, dp[i][j-1][52]+1);
					u = min(u, dp[i-1][j-1][52] +1);
					dp[i][j][b[j]] = min(dp[i][j][b[j]], dp[i-1][j-1][52]+1);
				}
				dp[i][j][52] = min(dp[i][j][52], u);
			}
		}

		int ans = 1000000000;
		for(i = 0; i <= 52; i++)ans = min(ans, dp[la][lb][i]);
		printf("%d\n",ans);	
    }
	return 0;
}