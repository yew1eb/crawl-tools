#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int flag;
struct Node{
	int a;
	int b;
	int num;
	int val;
}tree[888888];

int pos[200005];
int val[200005];
int temp[200005];

void Buildtree(int i,int a,int b)
{
	tree[i].a=a;
	tree[i].b=b;
	tree[i].num=b-a+1;
	if(a==b)
		return;
	int mid=(a+b)>>1;
	Buildtree(i<<1,a,mid);
	Buildtree(i<<1|1,mid+1,b);
}

void update(int i,int pos,int val)
{
	tree[i].num--;
	if(tree[i].a==tree[i].b)
	{
		tree[i].val=val;
	//	printf("i==%d__val==%d\n",i,tree[i].val);
		return;
	}
	if(pos<tree[i<<1].num)
		update(i<<1,pos,val);
	else
		update(i<<1|1,pos-tree[i<<1].num,val);
}

void getnum(int i)
{
	if(tree[i].a==tree[i].b)
	{
		temp[flag++]=tree[i].val;
		//printf("i===%d_____val===%d\n",i,tree[i].val);
		return;
	}
	getnum(i<<1);
	getnum(i<<1|1);
}


int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		Buildtree(1,1,N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d",&pos[i],&val[i]);
		}
	//	for(i=1;i<=10;i++)
	//	{
	//		printf("i==%d___a==%d___b=%d____num=%d___cal==%d\n",i,tree[i].a,tree[i].b,tree[i].num,tree[i].val);
	//	}
		for(i=N;i>0;i--)
		{
			update(1,pos[i],val[i]);
		}
		flag=0;
		getnum(1);
		for(i=0;i<N;i++)
		{
			printf(i==N-1?"%d\n":"%d ",temp[i]);
		}
	}
	return 0;
}