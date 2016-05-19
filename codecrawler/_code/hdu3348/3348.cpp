#include"stdio.h"
#include"string.h"
int min(int a[],int num[],int p,int sum[])
{
	int i;
	int ans=0;
	for(i=5;i>1;i--)
	{
		if(p>=num[i]*a[i])
		{
			ans+=num[i];
			p-=num[i]*a[i];
		}
		else
		{
			ans+=p/a[i];
			p%=a[i];
		}
	}
	if(p>num[1])return -1;
	else return ans+p;
}
int max(int a[],int num[],int p,int sum[])
{
	int i;
	int ans=0;
	for(i=5;i>1;i--)
	{
		if(p<=sum[i-1])continue;
		else
		{
			int t;
			//先用满足条件的最大面值，如果有余数，所用张数+1，
			//不足的部分用较小面值的进行补
			t=((p-sum[i-1])/a[i])+(((p-sum[i-1])%a[i])?1:0);
			ans+=t;
			p-=t*a[i];
		}
	}
	if(p>num[1])return -1;
	else return ans+p;
}
void dp(int a[],int num[],int p)
{
	int i;
	int sum[6]={0};
	sum[1]=num[1];
	for(i=2;i<=5;i++)
		sum[i]=sum[i-1]+a[i]*num[i];
	int mmin,mmax;
	mmin=min(a,num,p,sum);
	if(mmin==-1)printf("-1 -1\n");
	else
	{
		mmax=max(a,num,p,sum);
		if(mmax==-1)printf("-1 -1\n");
		else
			printf("%d %d\n",mmin,mmax);
	}
}
int main()
{
	int a[6]={0,1,5,10,50,100};
	int i,p;
	int num[6];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sum;
		sum=0;
		scanf("%d",&p);
		for(i=1;i<6;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i]*a[i];
		}
		if(sum<p)printf("-1 -1\n");
		else dp(a,num,p);
	}
	return 0;
}