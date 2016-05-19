#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
char s[maxn];
int main(){
	int t;
	int ca = 1;
	scanf("%d",&t);
	while(t --){
		scanf("%s",s);
		int len = strlen(s);
		for(int l = 0;l < len;l ++){
			for(int i = 0;i + l < len;i ++){
				if(l == 0)dp[i][i] = 1;
				else if(l == 1){
					if(s[i] == s[i + 1])dp[i][i + 1] = 3;
					else dp[i][i + 1] = 2;
				}
				else {
					dp[i][i + l] = dp[i + 1][i + l] + dp[i][i + l - 1] - dp[i + 1][i + l - 1];
					if(s[i] == s[i + l])dp[i][i + l] += dp[i + 1][i + l - 1] + 1;
					dp[i][i + l] = (dp[i][i + l] + 10007) % 10007;
				}
				//printf("i = %d j = %d dp = %d\n",i,i + l,dp[i][i + l]);
			}
		}
		printf("Case %d: %d\n",ca ++,dp[0][len - 1]);
	}
	return 0;
}