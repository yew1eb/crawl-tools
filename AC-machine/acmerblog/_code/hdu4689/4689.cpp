#include<cstdio>
#include<cstring>
typedef long long LL;
using namespace std;
int main()
{
	LL i,j,n;
	LL dp[22][22];
	char str[22];
	while(scanf("%s",str)!=EOF){
		n=strlen(str);
		if(str[0]=='-'){  
			puts("0");
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(i=2;i<=n;i++){
			if(str[i-1]=='+'){
				for(j=1;j<=i;j++){
					dp[i][j]+=dp[i-1][j-1];
					dp[i][j]+=dp[i-1][j]*j;
				}
			}
			else{
				for(j=1;j<=i;j++){
					dp[i][j-1]+=dp[i-1][j]*j*j;
					dp[i][j]+=dp[i-1][j]*j;
				}
			}
		}
		printf("%I64d\n",dp[n][0]);
	}
}