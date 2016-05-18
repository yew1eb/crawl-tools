#include"stdio.h"
int main()
{
	int t;
	int n;
	char c1,c2;
	int a,b,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		a=b=0;
		for(i=0;i<n;i++)
		{
			scanf("%c %c",&c1,&c2);
			getchar();
			if(c1=='R')
			{
				if(c2=='S')a++;
				else if(c2=='P')b++;
			}
			else if(c1=='S')
			{
				if(c2=='P')a++;
				else if(c2=='R')b++;
			}
			else if(c1=='P')
			{
				if(c2=='R')a++;
				else if(c2=='S')b++;
			}
		}
		if(a>b)printf("Player 1\n");
		else if(a==b)printf("TIE\n");
		else if(a<b)printf("Player 2\n");
	}
	return 0;
}