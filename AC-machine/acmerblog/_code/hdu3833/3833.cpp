#include"stdio.h"
#include"string.h"


int main()
{
	int T;
	int n;
	int i,l;
	int t;
	int num[10011];
	int hash[10011];
	int flag;
	int temp;


	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(hash,0,sizeof(hash));
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			hash[num[i]]=i;
		}


		flag=0;
		t=n/2;
		for(i=1;i<t;i++)
		{
			if(flag)	break;
			temp=num[i]*2;
			for(l=0;l<i;l++)
			{
				if(num[l]>=temp)	continue;
				if(temp-num[l]>n)	continue;
				if(hash[temp-num[l]]>i)	{flag=1;break;}
			}
		}


		t=n-1;
		for(i=n/2;i<t;i++)
		{
			if(flag)	break;
			temp=num[i]*2;
			for(l=i+1;l<n;l++)
			{
				if(num[l]>=temp)	continue;
				if(temp-num[l]>n)	continue;
				if(hash[temp-num[l]]<i)	{flag=1;break;}
			}
		}


		if(flag)	printf("Y\n");
		else		printf("N\n");
	}
	return 0;
}