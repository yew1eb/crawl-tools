#include<cstdio>
int main()
{
	int t,cas=1,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n!=1&&n!=2)
			n=n*2-4;
		printf("Case %d: %d\n",cas++,n);
	}
	return 0;
}