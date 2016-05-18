#include"stdio.h"
#include"math.h"
double fun(double x,double y)
{
	double ans;
	double m=(double)sqrt(2);
	int n,i;
	n=x+y;
	ans=0.0;
	for(i=1;i<n;i++)
		ans+=i*m;
	ans+=x*m;//这里注意
	for(i=0;i<n;i++)
		ans+=sqrt(i*i+(i+1)*(i+1));
	return ans;
}
int main()
{
	int t;
	int n;
	int x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%.3f\n",fabs(fun(x1,y1)-fun(x2,y2)));
	}
	return 0;
}