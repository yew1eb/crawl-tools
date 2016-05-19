#include <stdio.h>
__int64 map[105][105];
__int64 dp[105][105];
__int64 cnt[105][105];
void Test(__int64 n,__int64 m)
{
	__int64 i,j;
	printf("/n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			printf("%I64d ",cnt[i][j]);
		}
		printf("/n");
	}
}
int Dis(int x1,int y1,int x2,int y2)
{
	return y2-y1+x2-x1;
}
int main()
{
	__int64 i,j,T,n,m,k;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&n,&m);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				scanf("%I64d",&map[i][j]);
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				dp[i][j]=0;
				cnt[i][j]=0;
			}
		}
		dp[0][0]=1;
		cnt[0][0]=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (dp[i][j]==0 || map[i][j]==0) continue;
				for (k=0;k<=map[i][j];k++)
				{
					if (i+k<n && j+map[i][j]-k<m) 
					{
						if (cnt[i+k][j+map[i][j]-k]<cnt[i][j]+1) 
						{
							dp[i+k][j+map[i][j]-k]=dp[i][j];
							cnt[i+k][j+map[i][j]-k]=cnt[i][j]+1;
						} 
						else if (cnt[i+k][j+map[i][j]-k]==cnt[i][j]+1)
						{
							dp[i+k][j+map[i][j]-k]+=dp[i][j];
						}		
					}
				//	Test(n,m);
				}
			}
		}
		__int64 s=0;
		__int64 p=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (s<cnt[i][j] && (map[i][j]!=0 || (i==n-1 && j==m-1)) && Dis(i,j,n-1,m-1)<=map[i][j]) 
				{
					s=cnt[i][j];
					p=dp[i][j];
				}
				else if (s==cnt[i][j] && (map[i][j]!=0 || (i==n-1 && j==m-1)) && Dis(i,j,n-1,m-1)<=map[i][j])
				{
					p=p+dp[i][j];
				}
			}
		}
		printf("%I64d %I64d/n",s,p);
	}
	return 0;
}