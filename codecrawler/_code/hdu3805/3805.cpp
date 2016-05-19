#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct nod
{
	int flag,sum,a[10005];
}node[3];

void setflag()
{
	if(node[0].sum<node[1].sum && node[0].sum<node[2].sum)node[0].flag=1;
	if((node[0].sum<node[1].sum && node[0].sum>node[2].sum) || (node[0].sum>node[1].sum && node[0].sum<node[2].sum))node[0].flag=2;
	if(node[0].sum>node[1].sum && node[0].sum>node[2].sum)node[0].flag=3;
	if(node[1].sum<node[0].sum && node[1].sum<node[2].sum)node[1].flag=1;
	if((node[1].sum<node[2].sum && node[1].sum>node[0].sum) || (node[1].sum>node[2].sum && node[1].sum<node[0].sum))node[1].flag=2;
	if(node[1].sum>node[0].sum && node[1].sum>node[2].sum)node[1].flag=3;
	if(node[2].sum<node[1].sum && node[2].sum<node[0].sum)node[2].flag=1;
	if((node[2].sum<node[1].sum && node[2].sum>node[0].sum) || (node[2].sum>node[1].sum && node[2].sum<node[0].sum))node[2].flag=2;
	if(node[2].sum>node[1].sum && node[2].sum>node[0].sum)node[2].flag=3;
}

int main()
{
	int i,j,t,n,cnt[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(node,0,sizeof(node));
		for(j=0;j<3;j++)
		{
			node[j].flag=j+1;
			node[j].sum=j+1;
			node[j].a[0]=j+1;
		}
		for(i=1;i<n-2;i++)
		{
			setflag();
			for(j=0;j<3;j++)
			{
				if(node[j].flag==1)
				{
					node[j].a[i]=3*i+2;
					node[j].sum+=(3*i+2);
				}
				if(node[j].flag==2)
				{
					node[j].a[i]=3*i+3;
					node[j].sum+=(3*i+3);
				}
				if(node[j].flag==3)
				{
					node[j].a[i]=3*i+1;
					node[j].sum+=(3*i+1);
				}
			}
		}
		setflag();
		for(i=0;i<3;i++)
		{
			if(node[i].flag==1)cnt[0]=i;
			if(node[i].flag==2)cnt[1]=i;
			if(node[i].flag==3)cnt[2]=i;
		}
		printf("%d\n",3*n-3);
		for(i=0;i<n-2;i++)printf("%d %d\n",node[cnt[0]].a[i],node[cnt[1]].a[i]);
		printf("%d ",3*n-4);
		for(i=0;i<n-2;i++)printf("%d ",node[cnt[2]].a[i]);
		printf("%d\n",3*n-5);
	}

	return 0;
}