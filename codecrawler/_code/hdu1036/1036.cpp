#include"stdio.h"
#include"string.h"
#include"math.h"
int main()
{
	int n,i;
	int sum,t;
	int h,m,s;
	char str[101];
	double d;
	scanf("%d%lf",&n,&d);
	while(scanf("%d",&t)!=-1)
	{
		int f;
		sum=0;f=1;
		for(i=0;i<n&&f;i++)
		{		
			if(scanf("%d:%d:%d",&h,&m,&s)==3)
				sum+=h*3600+m*60+s;
			else 
			{
				gets(str);
				f=0;
			}
		}
		if(f==0)
			printf("%3d: -\n",t);
		else 
		{
			sum=sum/d+0.5;
			printf("%3d: %d:%02d min/km\n",t,sum/60,sum%60);
		}
	}
	return 0;
}