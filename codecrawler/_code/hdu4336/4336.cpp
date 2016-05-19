#include<cstdio>
const int maxn=1<<20;

double E[maxn],p[21],pr;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		pr=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
			pr-=p[i];
		}
		int state=(1<<n)-1;
		E[state]=0;
		for(int i=state-1;i>=0;i--)
		{
			double a=pr,b=1.0;
			for(int j=1;j<=n;j++)
			{
				int t=1<<(j-1);
				if((i&t)>0)a+=p[j];
				else b+=p[j]*E[i+t];
			}
			E[i]=b/(1-a);
		}
		printf("%lf\n",E[0]);
	}

	return 0;
}