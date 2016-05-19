#include<iostream>
using namespace std;

const int MAX=16001;
bool prime[MAX];

void initial()
{
	memset(prime,true,sizeof(prime));
	prime[1]=prime[2]=false;

	int i,j,tmp;
	for(i=3;i<MAX;i++)
	{
		tmp=(i+1)/2;
		for(j=2;j<=tmp;j++)
		{
			if(i%j==0)
			{
				prime[i]=false;
				break;
			}
		}
	}
}

int main()
{
	initial();

	int n,cas=1;

	while(scanf("%d",&n) , n>0)
	{
		printf("%d: ",cas++);
		if(prime[n])
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}