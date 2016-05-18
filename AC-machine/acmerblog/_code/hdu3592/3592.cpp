#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1000+10;
const int MAXM=200000+1000;
const int INF=100000000;
struct edge
{
	int to;
	int val;
	int next;
}e[MAXM];
int head[MAXN],dis[MAXN],len,n,ml,md;

void add(int from,int to,int val)
{
	e[len].to=to;
	e[len].val=val;
	e[len].next=head[from];
	head[from]=len++;
}

int spfa()
{
	int start=1;
	bool vis[MAXN]={0};
	int cnt[MAXN]={0};
	deque<int> q;
	q.push_back(start);
	vis[start]=1;
	cnt[start]=1;
	dis[start]=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop_front();
		vis[cur]=false;
		for(int i=head[cur];i!=-1;i=e[i].next)
		{
			int id=e[i].to;
			if(dis[id] > dis[cur] + e[i].val)
			{
				dis[id]=dis[cur] + e[i].val;
				if(!vis[id])
				{
					if(++cnt[id] > n)
						return -1;
					vis[id]=true;
					if(!q.empty() && dis[id] > dis[q.front()]) 
						q.push_back(id);
					else
						q.push_front(id);
				}
			}
		}
	}

	if(dis[n]==INF)
		return -2;
	
	return dis[n];
}

int main()
{
	while(~scanf("%d%d%d",&n,&ml,&md))
	{
		memset(head,-1,sizeof(head));
		len=0;
		for(int i=1;i<=n;i++)
		{
			dis[i]=INF;
			add(i,i-1,0);
		}

		for(int i=0;i<ml;i++)
		{
			int from,to,val;
			scanf("%d%d%d",&from,&to,&val);
			add(from,to,val);	
		}
		
		for(int i=0;i<md;i++)
		{
			int from,to,val;
			scanf("%d%d%d",&from,&to,&val);
			add(to,from,-val);	
		}


		printf("%d\n",spfa());
		
	}
	return 0;
}