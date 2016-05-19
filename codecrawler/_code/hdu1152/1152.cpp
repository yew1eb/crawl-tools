#include"stdio.h"
#include"string.h"
int x[200001],y[200001];
int main()
{
	int i;
	int n;
	int a,b,t;
	while(scanf("%d",&n)!=-1&&n)
	{
		for(i=0;i<(n+1)/2;i++)
			scanf("%d%d",&x[i],&y[i]);
		a=b=0;
		t=(n+1)/2-1;
		for(i=0;i<t;i++)
		{
			if(x[i]>x[t])
			{
				if(y[i]>y[t])a++;
				else if(y[i]<y[t])b++;
			}
			else if(x[i]<x[t])
			{
				if(y[i]<y[t])a++;
				else if(y[i]>y[t])b++;
			}
		}
		for(i=0;i<t;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			if(x[i]>x[t])
			{
				if(y[i]>y[t])a++;
				else if(y[i]<y[t])b++;
			}
			else if(x[i]<x[t])
			{
				if(y[i]<y[t])a++;
				else if(y[i]>y[t])b++;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}