#include<stdio.h>
#include<stdlib.h>
#define N 400010
_int64 dp[N],sum[N],a[N];
int q[N];
int n,T;
int head,tail;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
_int64 getDP(int i,int j)
{
     return dp[j]+(sum[i]-sum[j])-a[j+1]*(i-j);
} 
_int64 getUP(int j,int k)
{
      return dp[j]-sum[j]+a[j+1]*j-(dp[k]-sum[k]+a[k+1]*k);
}
_int64 getDOWN(int j,int k)
{
      return  a[j+1]-a[k+1];
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&T)!=-1)
	{
	    for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(a[1]),cmp);
		sum[0]=0;
		for(i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
        dp[0]=0;
		head=tail=0;
		q[tail++]=0;
		for(i=1;i<=n;i++)
		{
		   while(head+1<tail&&getUP(q[head+1],q[head])<=i*getDOWN(q[head+1],q[head]))
			   head++;
		   dp[i]=getDP(i,q[head]);
		   j=i-T+1;
		   if(j<T)continue;
		   while(head+1<tail&&getUP(q[tail-1],q[tail-2])*getDOWN(j,q[tail-1])>=getUP(j,q[tail-1])*getDOWN(q[tail-1],q[tail-2]))
			   tail--;
		   q[tail++]=j;
		}
		printf("%I64d\n",dp[n]);
	}
    return 0;
}