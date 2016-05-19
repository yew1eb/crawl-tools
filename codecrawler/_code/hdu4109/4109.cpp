#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define val 1001
struct link
{
	int v;
	int cost;
	struct link *next;
};
struct node
{
	struct link *next;
}vode[val];
int into[val],ee[val],n,m;//into表示入度，ee表示从最早完成该任务的时间，ee初始化为1
void topsort();//拓扑排序，边拓扑边求最长路径
void create_link();
int main()
{
	int i,j,ans;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(into,0,sizeof(into));
		for(i=0;i<n;i++)
			ee[i]=1;
		create_link();
		ans=0;
		topsort();
		for(i=0;i<n;i++)
			if(ee[i]>ans) ans=ee[i];
		printf("%d\n",ans);
	}
	return 0;
}
void create_link()
{
	int i,j,a,b,c;
	struct link *s;
	for(i=0;i<n;i++)
		vode[i].next=NULL;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		into[b]++;
		s=(struct link*)malloc(sizeof(struct link));
		s->v=b;
		s->cost=c;
		s->next=vode[a].next;
		vode[a].next=s;
	}
}
void topsort()
{
	int i,j,v;
	struct link *p;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(into[j]==0) 
			{
				v=j;
				break;
			}
		into[v]=-1;
		p=vode[v].next;
		while(p!=NULL)
		{
			if(ee[p->v]<ee[v]+p->cost)//如果权值和更大，则替换
				ee[p->v]=ee[v]+p->cost;
			into[p->v]--;
			p=p->next;
		}
	}
}
