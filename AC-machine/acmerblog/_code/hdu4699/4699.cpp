#include<stdio.h>
#include<string.h>
#define INF -10000000
int s1[1000001],s2[1000001],dp[1000001],pos1,pos2;
int sum[1000001];
int Max(int a,int b){
	return a>b?a:b;
}
int main(){
	int cas;
	while(scanf("%d",&cas)!=EOF){
		pos1=0;pos2=0;
		dp[0]=-INF;  //注意初始为 负很大
		sum[0]=0;
		while(cas--){
			char it[5];
			scanf("%s",it);
			if(it[0]=='I'){
				scanf("%d",&s1[++pos1]);
				sum[pos1]=sum[pos1-1]+s1[pos1];
				dp[pos1]=Max(dp[pos1-1],sum[pos1]);
			}
			if(it[0]=='D'){
				pos1--;
			}
			if(it[0]=='L'){
				if(pos1!=0)
					s2[++pos2]=s1[pos1--];
			}
			if(it[0]=='R'){
				if(pos2!=0){
					s1[++pos1]=s2[pos2--];
					sum[pos1]=sum[pos1-1]+s1[pos1];
					dp[pos1]=Max(dp[pos1-1],sum[pos1]);
				}
			}
			if(it[0]=='Q'){
				int x;
				scanf("%d",&x);
				printf("%d\n",dp[x]);
			}
		}
	}
    return 0;
}