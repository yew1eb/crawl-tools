#include<cstring>
#include<cstdio>
#include<queue>
char mp[30][30];
int cnt,ans,head[30000],gap[30000],dis[30000],sum,vi[30][30];
const int inf=1<<30;
struct EDGE
{
	int to,f,nxt;
}edge[2000000];
int n,m,s,t,nn;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int di[][2]={1,0,-1,0,0,1,0,-1,0,0};
int min(int a,int b)
{
	return a<b?a:b;
}
int in(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!='#';
}
void add(int a,int b,int c)
{
	edge[cnt].to=b;
	edge[cnt].f=c;
	edge[cnt].nxt=head[a];
	head[a]=cnt++;
	edge[cnt].to=a;
	edge[cnt].f=0;
	edge[cnt].nxt=head[b];
	head[b]=cnt++;
}
void init()
{
		cnt=ans=sum=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
			scanf("%s",mp[i]+1);
		s=1,t=2;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int num=(i-1)*m+j+2;
			if(mp[i][j]=='X')
			{
				sum++;
				add(s,num,1); 
			}
		}
		nn=2+n*m;
}
int dfs(int x,int y)
{
    vi[x][y]=1;
	if(mp[x][y]=='@')
	return 1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(!in(xx,yy))
			continue;
		if(vi[xx][yy])
		continue;
		if(dfs(xx,yy))
		return 1;
	}
	return 0;
}
int ok()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		memset(vi,0,sizeof(vi));
		if(mp[i][j]=='X'&&!dfs(i,j))
		return 1;
	}
	return 0;
}
int gfs(int x,int flow)
{
	if(x==t)
	return flow;
	int temp=flow,pos=nn-1,j;
	for(j=head[x];j!=-1;j=edge[j].nxt)
	{
		int y=edge[j].to;
		int c=edge[j].f;
		if(c>0&&dis[x]==dis[y]+1)
		{
			int temp_flow=gfs(y,min(temp,c));
			temp-=temp_flow;
			edge[j].f-=temp_flow;
			edge[j^1].f+=temp_flow;
			if(temp==0||dis[s]==nn)
			return flow-temp;
		}
		if(c>0&&pos>dis[y])
		pos=dis[y];
	}
	if(temp==flow)
	{
		if(!(--gap[dis[x]]))
		dis[s]=nn;
		else
		gap[dis[x]=pos+1]++;
	}
	return flow-temp;
}
int sap()
{
    int maxflow=0;
	memset(gap,0,sizeof(gap));
	memset(dis,0,sizeof(dis));
	gap[0]=nn;
	while(dis[s]<nn)
	{
		maxflow+=gfs(s,inf);
	}
	return maxflow;
}
int judge(int ti)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int u=(i-1)*m+j;
		u=(ti-1)*m*n+2+u;
		if(mp[i][j]=='#')
		continue;
		for(int k=0;k<5;k++)
		{
			int x=i+di[k][0];
			int y=j+di[k][1];
			int v=(x-1)*m+y;
			v=ti*m*n+2+v;
			if(!in(x,y))
			continue;
			add(u,v,1);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int v=(i-1)*m+j;
		v=2+ti*m*n+v;
		if(mp[i][j]=='@')
		{
		 add(v,t,1);
      }
    }
	nn+=n*m;
	ans+=sap();
	return ans==sum;
}
int gao()
{
	if(sum==0)
	return 0;
	int ti=0;
	while(1)
	{
		ti++;
		if(judge(ti))
		break;
		//printf("%d",ti); 
//		printf("%d",ans);
	}
	return ti;
}
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{
		init();
		if(ok())
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",gao());
	}
	return 0;
}