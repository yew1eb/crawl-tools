#include<stdio.h>
int main()
{
	int n,m,s,i;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		s=0;
		for(i=2;i<=n;i++)
            s=(s+m)%i;
		printf("%d %d %d\n",n,m,s+1);
	}
	return 0;
}