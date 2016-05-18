#include"stdio.h"
#include"math.h"
int main()
{
	int n;
	int count;
	int a,b;
	int t;
	int temp;
	while(scanf("%d",&n)!=-1)
	{
		if(n==0)
		{
			printf("1\n");
			continue;
		}


		count=0;
		t=n/2;
		a=1;
		while(a*a<t)
		{
			temp=n-a*a;
			b=sqrt(temp);
			if(b*b==temp)
				count+=8;


			a++;
		}


		if((int)sqrt(n)*(int)sqrt(n)*2==n)
			count+=4;
		if((int)sqrt(n)*(int)sqrt(n)==n)
			count+=4;


		printf("%d\n",count);
	}
	return 0;
}