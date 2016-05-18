#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 600
struct node
{
	int st,ed;
	int a,b,c,d;
}list[N*6];
int map[N][N];
int result[N];
int visit[N];
int n;
int cmp(const void *a,const void *b)
{
	return (*(struct node *)a).st-(*(struct node *)b).st;
}
int find(int a)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!visit[i]&&map[a][i])
		{
			visit[i]=1;
			if(!result[i]||find(result[i]))
			{
				result[i]=a;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int t,i,j,temp;
	int hour,minute,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d %d %d %d %d",&hour,&minute,&list[i].a,&list[i].b,&list[i].c,&list[i].d);
			list[i].st=hour*60+minute;
			list[i].ed=list[i].st+abs(list[i].a-list[i].c)+abs(list[i].b-list[i].d);
		}
		qsort(list+1,n,sizeof(list[0]),cmp);
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			temp=abs(list[i].c-list[j].a)+abs(list[i].d-list[j].b);
			if(list[i].ed+temp<list[j].st)
			map[i][j]=1;
		}
		ans=0;
		memset(result,0,sizeof(result));
		for(i=1;i<=n;i++)
		{
			memset(visit,0,sizeof(visit));
			if(find(i))
			ans++;
		}
		printf("%d\n",n-ans);
	}
	system("pause");
	return 0;
}