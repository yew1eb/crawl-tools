#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn =1005;
struct data
{
	int id;
	int task;
	int score;
}e[maxn];
bool vis[maxn];
bool cmp(const data &a,const data &b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else 
	{
		if(a.task!=b.task)
			return a.task>b.task;
		else return a.id<b.id;
	}
}
int main()
{
	int n,s,p;
	while(scanf("%d%d%d",&n,&s,&p)!=EOF)
	{
		memset(e,0,sizeof(e));
		for(int i=1;i<=s;i++)
			e[i].id=i;
		for(int i=1;i<=n;i++)
		{
			int num=0;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=s;j++)
			{
				int k;
				scanf("%d",&k);
				if(k==0)
					num++;
				else vis[j]=1;
			}
			for(int j=1;j<=s;j++)
			{
				if(vis[j])
				{
					e[j].score+=num;
					e[j].task++;
				}
			}
		}
		std::sort(e+1,e+s+1,cmp);
		int ans1,ans2;
		for(int i=1;i<=s;i++)
		{
			if(e[i].id==p)
			{
				ans1=e[i].score;
				ans2=i;
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
}