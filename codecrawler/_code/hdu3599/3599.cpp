#include<stdio.h>
#include<string.h>
#define oo 100000000
#define M 1510
int head[M*2],head2[2*M],Q[M*M],mark[M*2],tot,dis[M*2],dist[M*2],work[M*2];
struct node
{
	int to,cap,next;
}edge[M*M],edge2[M*M];
int fir,end,n,g[M][M];
void add(int a,int b,int d)
{
	edge[tot].to=b,edge[tot].cap=d,edge[tot].next=head[a],head[a]=tot++;
	edge[tot].to=a,edge[tot].cap=d,edge[tot].next=head[b],head[b]=tot++;
	return ;
}
void add2(int a,int b,int d)
{
	edge2[tot].to=b;edge2[tot].cap=d;edge2[tot].next=head2[a];head2[a]=tot++;
	return ;
}
void spfa()
{
	int i;
	for(i=0;i<=n;i++)
	{
		dis[i]=oo;
		mark[i]=0;
	}
	int l,r;
	l=r=0;
	Q[r++]=fir;
	dis[fir]=0;
	mark[fir]=1;
	while(l<r)
	{
		int k;
		k=Q[l++];
		mark[k]=0;
		for(i=head[k];i!=-1;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>edge[i].cap+dis[k])
			{
				dis[y]=edge[i].cap+dis[k];
				if(!mark[y])
				{
					Q[r++]=y;
					mark[y]=1;
				}
			}
		}
	}
	return ;
}
void bfs(int u)
{
	int i,l=0,r=0;
	Q[r++]=u;
	while(l<r)
	{
		int k;
		k=Q[l++];
		for(i=head[k];i!=-1;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]==dis[k]-edge[i].cap)
			{
				if(!g[y][k])
				add2(y,k,1),g[y][k]=1;
				/*if(!g[k][y])
				add2(k,y,1),g[k][y]=1;*/
				Q[r++]=y;
			}
		}
	}
	return ;
}
inline int min(int a,int b){
 return a<b?a:b;
}
bool BFS()
{
 int i,j,k,l,h,y;
 for(i=1;i<=end;i++)dist[i]=-1;
 dist[fir]=0;
 l=h=0;
 Q[h++]=fir;
 while(l<h)
	{
 k=Q[l++];
 for(i=head2[k];i!=-1;i=edge2[i].next)
		{
 y=edge2[i].to;
 if(edge2[i].cap>0&&dist[y]==-1)
			{
				dist[y]=dist[k]+1;
 Q[h++]=y;
			}
 }
 }
 return (dist[end]>=0);
}
int DFS(int x,int exp){
 mark[x]=1;
 if(x==end)return exp;
 for(int temp,y,&i=work[x];i!=-1;i=edge2[i].next){
 y=edge2[i].to;
 if(edge2[i].cap>0&&dist[y]==dist[x]+1&&!mark[y]){
 if((temp=DFS(y,min(edge2[i].cap,exp)))>0)
 {
 edge2[i].cap-=temp;
 //edge2[i^1].cap+=temp;
 return temp;
 }
 }
 }
 return 0;
}
int Dinic_flow(){
 int ans=0,flow,i;
 while(BFS()){
 for(i=0;i<=end;i++)work[i]=head2[i];
 while(1){
 for(i=1;i<=end;i++)mark[i]=0;
 flow=DFS(fir,oo);
 if(flow==0)break;
 ans+=flow;
 }
 }
 return ans;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		tot=0;
		memset(head,-1,sizeof(head));
		memset(head2,-1,sizeof(head2));
		memset(g,0,sizeof(g));
		int a,b,d;
		while(scanf("%d%d%d",&a,&b,&d)&&a)
		{
			add(a,b,d);
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}	
		fir=1;end=n;
		spfa();
		tot=0;
		bfs(n);
		/*int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			printf("%d ",g[i][j]);
			printf("\n");
		}*/
		printf("%d\n",Dinic_flow());
	}	
	return 0;
}