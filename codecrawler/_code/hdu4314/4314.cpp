#include"iostream"
#include"cstdio"
#include"cstring"
#include"algorithm"
using namespace std;
const int N=2012;

int n,limit;
int sum[2012],dp[2][2012];
struct node{
	int h,l;
}E[N];

int min(int a,int b){
	return a>b?b:a;
}
int max(int a,int b){
	return a>b?a:b;
}
int cmp(node n1,node n2){
	return n1.h+n1.l>n2.h+n2.l;
}
int solve()
{
	int i,l;
	int pre,now,t=1<<30;
	int ans=0;
	dp[0][0]=0;
	for(l=1;l<=n;l++)	dp[0][l]=t;
	for(i=1;i<=n;i++)
	{
		now=i%2;
		pre=1-now;
		for(l=0;l<=i;l++)	dp[now][l]=0;
		for(;l<=n;l++)		dp[now][l]=t;
		for(l=1;l<=i;l++)
		{
			dp[now][l]=min(dp[pre][l]-E[i].h,max(dp[pre][l-1],limit-sum[i]-E[i].l));
			if(dp[now][l]<=0 && ans<l)	ans=l;
		}
	}
	return ans;
}
int main()
{
	int i;
	while(scanf("%d",&n)!=-1)
	{
		for(i=1;i<=n;i++)	scanf("%d%d",&E[i].h,&E[i].l);
		scanf("%d",&limit);
		E[0].h=E[0].l=0;
		sum[0]=0;
		sort(E+1,E+n+1,cmp);
		for(i=1;i<=n;i++)	sum[i]=sum[i-1]+E[i].h;
		printf("%d\n",solve());
	}
	return 0;
}