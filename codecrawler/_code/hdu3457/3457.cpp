#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
struct po{
	int x1,y1,x2,y2;
}a[1001];
bool cmp(po x,po y){
	if(x.x1==y.x1) return x.y1<y.y1;
	return x.x1<y.x1;
}
int dp[1002];
int main(){
	int n,xs,x,y,i,j;
	while(~scanf("%d",&n),n){
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++) dp[i]=1;
		for(i=1;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i].x1>a[j].x2&&a[i].y1>a[j].y2){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		int mi=0;
		for(i=0;i<n;i++) mi=max(mi,dp[i]); 
		printf("%d\n",mi);
	}
	return 0;
}
//2 3 4