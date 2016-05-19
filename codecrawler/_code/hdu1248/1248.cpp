#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	int n;
	int arr[3] = {150, 200, 350};
	int i, j;
	int dp[10002];
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(i = 0; i < 3; i ++){
			for(j = arr[i]; j <= n; j ++){
				dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
			}
		}
		printf("%d\n", n - dp[n]);
	}
	return 0;
}