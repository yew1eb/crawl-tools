#include<cstdio>

int main()
{
	int T,n,cnt = 1,B;
	while(scanf("%d%d%d",&T,&n,&B),(T || n || B))
	{

		double s,p,sum = 0;
		while(T--)
		{
			scanf("%lf%lf", &s, &p);
			sum += s*(1.0-p/100.0);
		}
		printf("Case %d: %.2f\n\n",cnt++,sum/(B*1.0));
	}
	return 0;
}