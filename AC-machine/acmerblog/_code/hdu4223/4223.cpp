#include"stdio.h"
#include"string.h"
#define N 1101

int abs(int a)
{
	if(a>0)return a;
	return -a;
}

int main()
{
	int T;
	int n;
	int A[N];
	int dp[N];
	int i,j,t;
	int ans,cnt;

	scanf("%d",&T);
	cnt=1;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d",&A[0]);
		ans=dp[0]=abs(A[0]);
		for(i=1;i<n;i++)
		{
			scanf("%d",&A[i]);
			dp[i]=abs(A[i]);
			t=A[i];
			//因为要求是连续的，所以得从i-1开始
			for(j=i-1;j>=0;j--)
			{
				t+=A[j];
				if(abs(t)<dp[i])
					dp[i]=abs(t);
			}
			if(dp[i]<ans)ans=dp[i];
		}
		printf("Case %d: %d\n",cnt++,ans);
	}
	return 0;
}
		