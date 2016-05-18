#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=1<<17;

int dp[17][maxn];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,m,i,j;
	while(scanf("%d",&n)&&n){
		scanf("%d",&m);
		memset(dp,0,sizeof(dp));
		int s,e;
		for(int i=0;i<m;i++){
            scanf("%d%d",&s,&e);
            dp[0][s]=e;
        }
        for(i=1;i<=n;i++){
            for(j=0;j<maxn;j++){
                if(j&(1<<(i-1))){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-(1<<(i-1))];
                }else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
		int ans=-1<<30;
        for(i=0; i<(1<<n);i++) {
            ans = max(ans, dp[n][i]);
        }
		printf("%d\n",ans);
	}
	return 0;
}