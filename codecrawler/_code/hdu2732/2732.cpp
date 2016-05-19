#include<stdio.h>
#include<string.h>
#define N 1000
#define inf 0x3fffffff
int dis[N],gap[N],head[N],num,n,m,D,ans;
int G[25][25],start=801,end=802;
struct edge
{
	int st,ed,flow,next;
}E[N*20];
void addedge(int x,int y,int w)
{
	E[num].st=x;E[num].ed=y;E[num].flow=w;E[num].next=head[x];head[x]=num++;
	E[num].st=y;E[num].ed=x;E[num].flow=0;E[num].next=head[y];head[y]=num++;
}
int abs(int a)
{
	if(a>0)return a;
	return -a;
}
bool judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
	{
        return false;
    }
    else if (!G[x][y])
	{
        return false;
    }
    return true;
}
bool out(int x,int y)//判断该柱子上的蜥蜴是否能跳出去
{
	if(x-D<0||x+D>=n||y-D<0||y+D>=m)
		return true;
	return false;
}
void makemap(int x,int y)
{
	int nn=x*m+y;
	addedge(nn,nn+400,G[x][y]);//柱子拆点
	if(out(x,y))//如果可以跳出就不跳到别的柱子上了
	{
		addedge(nn+400,end,G[x][y]);
		return ;
	}
	for (int i = -D; i <= D; ++i) 
		for (int j = -(D-abs(i)); j <= (D-abs(i)); ++j)
		{
			int xx = x + i, yy = y + j;
			if (judge(xx, yy) && !(x == xx && y == yy))
				addedge(nn+400, xx*m+yy, inf);
		}
}
int dfs(int u,int minflow)
{
	if(u==end)return minflow;
	int i,v,f,min_dis=ans-1,flow=0;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		if(E[i].flow)
		{
			v=E[i].ed;
			if(dis[u]==dis[v]+1)
			{
				f=dfs(v,E[i].flow>minflow-flow?minflow-flow:E[i].flow);
				E[i].flow-=f;
				E[i^1].flow+=f;
				flow+=f;
				if(flow==minflow)break;
				if(dis[start]>=ans)
					return flow;
			}
			min_dis=min_dis>dis[v]?dis[v]:min_dis;
		}
	}
	if(flow==0)
	{
		if(--gap[dis[u]]==0)
			dis[start]=ans;
		dis[u]=min_dis+1;
		gap[dis[u]]++;
	}
	return flow;
}
int isap()
{
	int maxflow=0;
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	gap[0]=ans;//点的个数
	while(dis[start]<ans)
       maxflow+=dfs(start,inf);
	return maxflow;
}
int main()
{
	int i,j,sum,t,op=1;
	char str[25];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&D);
		memset(head,-1,sizeof(head));
		num=0;ans=2;sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(j=0;str[j];j++)
				G[i][j]=str[j]-'0';
		}
		m=strlen(str);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(G[i][j]>0)
				{
					makemap(i,j);
					ans+=2;
				}
			}
			for(i=0;i<n;i++)
			{
				scanf("%s",str);
				for(j=0;j<m;j++)
					if(str[j]=='L')
					{
						sum++;
						addedge(start,i*m+j,1);
					}
			}
			sum-=isap();
			printf("Case #%d: ",op++);
			if(sum==0)//输出还得考虑单复数问题，
				puts("no lizard was left behind.");
			else if(sum==1)
				printf("%d lizard was left behind.\n", sum);
			else
				printf("%d lizards were left behind.\n", sum);
	}
	return 0;
}