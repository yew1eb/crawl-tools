#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int c1[10005],c2[10005];
int a[105],ans[10005];

int main()
{
	int i,j,n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum=sum+a[i];
		}
		for(i=0;i<=sum;i++)
		{
			c1[i]=0;
			c2[i]=0;
		}
		c1[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j+a[i]<=sum;j++)
			{
				if(c1[j]==1)
				{
					c2[j]=1;
					c2[j+a[i]]=1;
					c2[abs(j-a[i])]=1;
				}
			}
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		int num=0;
		for(i=1;i<=sum;i++)
		{
			if(c1[i]==0)
				ans[num++]=i;
		}
		if(num==0)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",num);
		for(i=0;i<num-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[num-1]);
	}
	return 0;
}