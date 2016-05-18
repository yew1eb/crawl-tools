#include"stdio.h"
#include"string.h"
__int64 p[105],w[105];
int main()
{
	int T;
	int i,j;
	int n,d,a,k,x;
	__int64 sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&n,&d,&a,&k,&x);
		//p[i]表示活i天的人数
		//w[i]表示第i天的种子数
		memset(p,0,sizeof(p));
		memset(w,0,sizeof(w));
		p[0]=n;
		sum=0;
		for(i=1;i<=x;i++)
		{
			for(j=d;j>=0;j--)
				p[j+1]=p[j];
			for(j=k;j>=0;j--)
				w[j+1]=w[j];
			p[0]=w[k];

			w[0]=0;
			for(j=1;j<=a;j++)
				w[0]+=p[j];

			for(j=1;j<=d;j++)
				sum+=p[j];
		}
		printf("%I64d\n",sum*5);
	}
	return 0;
}