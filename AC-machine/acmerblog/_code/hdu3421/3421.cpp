/*
hdu 3421 Max Sum II 读不懂题的伤不起啊
题意：吧一串数字 分成几串，串数尽量少（能用0链接起来的两串就用0链接起来），使其中几串的和最大
*/

#include<stdio.h>
__int64 he;
int main()
{
	int t,n,i,ret,qian,j,dang;
	scanf("%d",&t);
	for(i=1;i<=t;)
	{
		he=0;
		scanf("%d",&n);
		qian=-1;
		ret=0;
		int ji=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&dang);
			if(dang>0) he+=dang;
			if(ji)
			{
				if(dang<0)
				{
					ji=0;
				}
			}else
			{
				if(dang==0)
				{
					
				}else if(dang>0)
				{
					ji=1;
					ret++;
				}
			}
		}
		if(i!=1)
			printf("\n");
		printf("Case %d:\n",i++);
		printf("%d %I64d\n",ret,he);
	}
	return 0;
}