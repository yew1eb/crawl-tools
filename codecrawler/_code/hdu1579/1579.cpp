#include<stdio.h>
int dp[25][25][25];
int main()
{
	int a,b,c,k;
	for(a=0;a<=20;a++)
		for(b=0;b<=20;b++)
			for(c=0;c<=20;c++)
			{
				if(a<=0||b<=0||c<=0)
					dp[a][b][c]=1;
				else if(a<b&&b<c)
						dp[a][b][c]=dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
				else
					dp[a][b][c]=dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
			}
			while(scanf("%d%d%d",&a,&b,&c),a!=-1||b!=-1||c!=-1)
			{
				if(a<=0||b<=0||c<=0)
                    k=dp[0][0][0];
				else if(a>20||b>20||c>20)
					k=dp[20][20][20];
				else k=dp[a][b][c];
				printf("w(%d, %d, %d) = %d\n",a,b,c,k);
			}
			return 0;
}