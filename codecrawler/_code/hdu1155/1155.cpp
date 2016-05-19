#include"stdio.h"
#include"string.h"
#define g 9.81
int main()
{
	double k,s,l,w;
	double e1,e2,e3;
	while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w)!=-1)
	{
		if(!k&&!l&&!s&&!w)break;
		e1=0.5*w*100;//10m/s的动能
		e2=w*s*g;//重力势能
		e3=0.5*k*(s-l)*(s-l);//弹性势能
		if(l>s)//绳长大于桥高
		{
			if(e2>e1)printf("Killed by the impact.\n");
			else printf("James Bond survives.\n");
		}
		else
		{
			if(e2<e3)printf("Stuck in the air.\n");
			else if(e2-e3>e1)printf("Killed by the impact.\n");
			else printf("James Bond survives.\n");
		}
	}
	return 0;
}