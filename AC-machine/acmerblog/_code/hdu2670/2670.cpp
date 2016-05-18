#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[1001];
struct op
{
	int w,v;
}p[1001];
int cmp(const void *a,const void *b)
{
	struct op *c,*d;
	c=(struct op *)a;
	d=(struct op *)b;
	return d->v-c->v;
}
int main()
{
	int i,j,n,k,max;
	while(scanf("%d%d",&n,&k)!=-1)
	{
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&p[i].w);
		for(i=0;i<n;i++)
			scanf("%d",&p[i].v);
		qsort(p,n,sizeof(p[0]),cmp);
		for(i=0;i<n;i++)
			for(j=k;j>=1;j--)
			{
				if(dp[j]<dp[j-1]+p[i].w-(j-1)*p[i].v)
				dp[j]=dp[j-1]+p[i].w-(j-1)*p[i].v;
			}
			printf("%d\n",dp[k]);
	}
	return 0;
}