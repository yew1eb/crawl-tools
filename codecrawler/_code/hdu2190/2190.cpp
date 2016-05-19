#include "stdio.h"
#include "string.h"

void main(){
	int c, n, i;
	int dp[31][2];  //方式0，以1*1的地砖结束；方式1，以2*2的地板结束

	memset(dp, 0, sizeof(dp));

	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 2;

	for(i=3; i<=30; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];  //以方式0结束，即第i列全是1*1的地砖，就等于第i-1列的所有情况
		dp[i][1] = (dp[i-2][0] + dp[i-2][1])*2;  //以方式1结束，即第i列和第i-1列有2*2的地砖，就等于第i-2列的所有情况*2，因为2*2的地砖可以在上面或者下面，两种情况
	}

	freopen("in.txt", "r", stdin);
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		printf("%d\n", dp[n][0]+dp[n][1]);
	}
}