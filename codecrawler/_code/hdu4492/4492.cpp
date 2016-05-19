#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,n,t,tt,p,len;
	char s[600];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&tt);
		getchar();
		gets(s);
		scanf("%d",&n);
		p=0;
		len=strlen(s);
		printf("%d ",tt);
		while(n--)
		{
			scanf("%d",&i);
			p=(p+i)%len;
			if(p<0)
				p+=len;
			putchar(s[p]);
		}
		printf("\n");
	}
	return 0;
}