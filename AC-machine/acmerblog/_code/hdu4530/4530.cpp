#include <stdio.h>

int main()
{
	int test,x,Q,t,k;
	double ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&x,&Q);
		while(Q--)
		{
			scanf("%d %d",&t,&k);
			if(t==1)
			{
				ans=(60-x)*k*1.0;
				printf("%.2lf\n",ans);
			}
			else if(t==2)
			{
				ans=1.0*60*k*60/(60-x);
				printf("%.2lf\n",ans);
			}
			else
			{
				ans=12.0*3600*60*k/x;
				printf("%.2lf\n",ans);
			}
		}
	}
	return 0;
}