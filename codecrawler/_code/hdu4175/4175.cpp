#include<cstdio>
#include<cmath>
#define min(a,b) a<b?a:b
#define INF 1000000007
using namespace std;
int z;
int c,t,l;
int dp[100][1005];
struct node{
	int x,y;
}a[100][1005];
int main()
{
	scanf("%d",&z);
	while(z--){
		scanf("%d%d%d",&c,&t,&l);
		for(int i=1;i<=c;i++){
			for(int j=1;j<=t;j++) scanf("%d%d",&a[i][j].x,&a[i][j].y);
		}
		
		for(int i=0;i<=c;i++)
		   for(int j=0;j<=t;j++) 
		      dp[i][j]=INF;
		      
		for(int i=1;i<=t;i++) dp[c][i]=a[c][i].y+l-a[c][i].x;
		for(int i=c-1;i>0;i--){
			for(int k=1;k<=t;k++){
				for(int j=1;j<=t;j++){
				   dp[i][k]=min(dp[i][k],dp[i+1][j]+a[i][k].y+abs(a[i+1][j].x-a[i][k].x));
			    }
			}			
		}
		int ans=INF;
		for(int i=1;i<=t;i++) 
		   ans=min(ans,dp[1][i]+a[1][i].x);
		printf("%d\n",ans);
	}
}