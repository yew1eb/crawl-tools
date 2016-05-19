#include"stdio.h"
#include"string.h"
#include"algorithm"
#include"cmath"
#define N 10001
using namespace std;

struct node
{
	int t,x,y;
}A[N];

int cmp(node a,node b){return a.t<b.t;}
int max(int a,int b){return a>b?a:b;}

int main()
{
	int n,m;
	int dp[N];
	int i,j,ans;
	while(scanf("%d%d",&n,&m)!=-1&&(n+m))
	{
		for(i=0;i<m;i++)
			scanf("%d%d%d",&A[i].t,&A[i].x,&A[i].y);
		sort(A,A+m,cmp);
		ans=0;
		for(i=0;i<m;i++)
		{
			dp[i]=1;
			for(j=0;j<i;j++)
			{
				if(abs(A[i].t-A[j].t)>=(abs(A[i].x-A[j].x)+abs(A[i].y-A[j].y)))
					dp[i]=max(dp[i],dp[j]+1);
			}
			if(dp[i]>ans)ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}