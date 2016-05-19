#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
using namespace std;
int s,e,LIMIT;
struct node
{
	int index;
};
struct Eage
{
	int from,to,len;
	int next;
}eage[200011];
int tot,head[5011];
int dis[5011][55];
void add(int a,int b,int len)
{
	eage[tot].from=a;
	eage[tot].to=b;
	eage[tot].len=len;
	eage[tot].next=head[a];
	head[a]=tot++;
}
void SPFA()
{
	int l,j;
	int flag;
	int hash[5011];
	queue<node>q;
	node now,next;

	memset(hash,0,sizeof(hash));
	memset(dis,127,sizeof(dis));
	now.index=s;
	dis[s][0]=0;
	q.push(now);
	hash[s]=1;

	while(!q.empty())
	{
		now=q.front();
		q.pop();
		hash[now.index]=0;
		for(j=head[now.index];j!=-1;j=eage[j].next)
		{
			flag=0;
			dis[now.index][LIMIT]=dis[now.index][LIMIT]>dis[now.index][LIMIT+1]?dis[now.index][LIMIT+1]:dis[now.index][LIMIT];
			for(l=0;l<=LIMIT;l++)
			{
				if(dis[now.index][l]+eage[j].len<dis[eage[j].to][l+1])
				{
					flag=1;
					dis[eage[j].to][l+1]=dis[now.index][l]+eage[j].len;
				}
			}
			if(flag && !hash[eage[j].to])
			{
				next.index=eage[j].to;
				q.push(next);
				hash[next.index]=1;
			}
		}
	}
}
int main()
{
	int n,m;
	int a,b,c;
	int ans;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		memset(head,-1,sizeof(head));
		tot=0;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		scanf("%d%d%d",&s,&e,&LIMIT);
		LIMIT=LIMIT/10+(LIMIT%10==0?0:1);

		SPFA();

		ans=1111111111;
		ans=ans>dis[e][LIMIT]?dis[e][LIMIT]:ans;
		if(ans==1111111111)	printf("-1\n");
		else				printf("%d\n",ans);
	}
	return 0;
}