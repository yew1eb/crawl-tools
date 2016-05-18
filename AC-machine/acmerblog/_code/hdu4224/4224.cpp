#include<stdio.h>
int main()
{
	int i,a[3],b[3],c[3],t,op=1;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++)
			c[i]=0;
		for(i=0;i<3;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			if(a[i]==b[i])
				c[0]++;
			else if(a[i]>b[i])
				c[1]++;
			else c[2]++;
		}
		printf("Case %d: ",op++);
		if(c[0]==3||(c[1]>0&&c[2]>0))
			puts("Yes");
		else puts("No");
	}
	return 0;
}
