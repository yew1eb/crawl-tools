#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
int map[501][501],mark[501],link[501],v[501];
int n,m;
char time[10];
struct node
{
	int x1,x2,y1,y2;
	int t,sum;
}aa[501];
int fun(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int dfs(int k)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(map[k][i]&&!v[i])
		{
			v[i]=1;
			if(link[i]==-1||dfs(link[i]))
			{
				link[i]=k;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j,ans;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",time);
			scanf("%d%d%d%d",&aa[i].x1,&aa[i].y1,&aa[i].x2,&aa[i].y2);
			aa[i].t=(time[0]-'0')*10*60+(time[1]-'0')*60
				+(time[3]-'0')*10+(time[4]-'0');
			aa[i].sum=fun(aa[i].x1,aa[i].y1,aa[i].x2,aa[i].y2);
		}
		memset(map,0,sizeof(map));
		for(i=0;i<m-1;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if((aa[i].t+aa[i].sum+fun(aa[i].x2,aa[i].y2,aa[j].x1,aa[j].y1))<aa[j].t)
					map[i][j]=1;
			}
		}
		ans=0;
		memset(link,-1,sizeof(link));
		for(i=0;i<m;i++)
		{
			memset(v,0,sizeof(v));
			ans+=dfs(i);
		}
		printf("%d\n",m-ans);
	}
	return 0;
}