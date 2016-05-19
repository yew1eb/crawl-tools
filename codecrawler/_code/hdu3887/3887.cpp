#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,root;
int C[100011];
int ans[100011];
int hash[100011];
int queue[100011];
int eage_now[100011];
struct Eage
{
	int from,to,next;
}eage[200011];
int tot,head[100011];
void add(int a,int b)
{
	eage[tot].from=a;
	eage[tot].to=b;
	eage[tot].next=head[a];
	head[a]=tot++;
}
int query(int k)
{
	int t=0;
	while(k>0)
	{
		t+=C[k];
		k-=k&(-k);
	}
	return t;
}
void update(int k,int dir)
{
	while(k<=n && k>0)
	{
		C[k]+=dir;
		k+=k&(-k);
	}
}
void DFS()
{
	int z,i,j;
	int k=0;
	int flag;

	memset(hash,0,sizeof(hash));
	hash[root]=1;
	queue[++k]=root;
	ans[root]=0;
	for(i=0;i<=n;i++)	eage_now[i]=head[i];
	while(k)
	{
		flag=0;
		for(j=eage_now[queue[k]];j!=-1;j=eage[j].next)
		{
			z=eage[j].to;
			if(hash[z])	continue;
			eage_now[queue[k]]=eage[j].next;
			queue[++k]=z;
			hash[z]=1;
			ans[z]=query(z);
			flag=1;
			break;
		}
		if(flag==0)
		{
			ans[queue[k]]=query(queue[k])-ans[queue[k]];
			update(queue[k],1);
			k--;
		}
	}
}
int main()
{
	int i;
	int a,b;
	while(scanf("%d%d",&n,&root),n||root)
	{
		tot=0;
		memset(head,-1,sizeof(head));
		for(i=1;i<n;i++)	{scanf("%d%d",&a,&b);add(a,b);add(b,a);}

		memset(C,0,sizeof(C));
		DFS();

		for(i=1;i<n;i++)	printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}