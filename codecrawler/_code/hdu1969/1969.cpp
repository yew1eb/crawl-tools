#include"stdio.h"
#include"math.h"
#define PI acos(-1.0)


double MAX(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	int T;
	int n,peo;
	int i;
	int temp;
	double low,up,mid;
	double S[10011];


	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&peo);
		peo++;


		up=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			S[i]=PI*temp*temp;
			up=MAX(up,S[i]);
		}


		low=0;
		mid=(low+up)/2;
		while(up-low>=0.0000001)
		{
			temp=0;
			for(i=0;i<n;i++)	temp+=(int)(S[i]/mid);
			if(temp>=peo)	low=mid;
			else			up=mid;
			mid=(low+up)/2;
		}
		printf("%0.4lf\n",mid);
	}
	return 0;
}