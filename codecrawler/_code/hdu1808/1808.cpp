#include <cstdio>
#include <cstring>

int data[100005];
int remainder[100005];
int c,n;

int main ()
{
    while (scanf("%d%d",&c,&n) && (c||n))
	{
		int i,s,e;
		memset(remainder,0,sizeof(remainder));
		for (i=1;i<=n;i++)
			scanf("%d",&data[i]);
		int sum=0;
		for (i=1;i<=n;i++)
		{
			sum=(sum+data[i])%c;
			if (sum == 0)
			{
				s=1;
				e=i;
				break;
			}
			else if (remainder[sum])
			{
				s=remainder[sum]+1;
				e=i;
				break;
			}
			else
				remainder[sum]=i;
		}
		for (i=s;i<=e;i++)
			printf(i==e?"%d\n":"%d ",i);
    }
    return 0;   
}