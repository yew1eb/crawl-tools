#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"algorithm"
using namespace std;
#define INF 1000010

int N,A,B;
int C[INF],dp[INF],sum[INF];	

int main(){
	while(scanf("%d%d%d",&N,&A,&B) != EOF){
		memset(dp,0,sizeof(dp));
		memset(C,0,sizeof(C));
		memset(sum,0,sizeof(sum));
		for(int i = 1 ; i <= N ; i++ )
			scanf("%d",&C[i]);
		int all = A+B;
		int flag = -1,temp = 0;
		for(int i = 1; i <= N ; i ++){
			sum[i] = sum[i-1]+C[i]; //前面所需的总和
			if(all < sum[i]){
				flag = i-1;
				break;
			}
		}
		if(flag == -1)
			flag = N;
		dp[flag] = C[flag];
		for(int i = flag-1; i >= 1 ; i--){
			dp[i] = min(dp[i+1]+C[i],all-sum[i-1]-dp[i+1]+1);
		}
		if(dp[1] > A)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}
	return 0;
}