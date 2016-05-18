#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")

using namespace std;

const int MAX = 100010;
const int MAX_N = 15;
int dp[MAX_N][MAX];
int tt[MAX_N][MAX];
int main()
{
	int n,x,t;
	while( ~scanf("%d",&n) && n )
	{
		memset(dp, 0, sizeof(dp));
		memset(tt, 0, sizeof(tt));
		int max_t = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&x,&t);
			max_t = max(max_t, t);
			tt[x][t]++;
		}	
		
		int ans = 0;
		
		for(int i=1; i<=max_t; i++)
			for(int k=0; k<=10; k++)
			{
				int t = dp[k][i-1];
				if( k >= 1 ) t = max(t, dp[k-1][i-1]);
				if( k <= 9 ) t = max(t, dp[k+1][i-1]);
				
				dp[k][i] = t;
				
				if( tt[k][i] && i >= abs(k-5) )
					dp[k][i] += tt[k][i];
				
				ans = max(ans, dp[k][i]);
			}

		printf("%d\n",ans);
	}
	
return 0;
}