#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int nodes=300;
const int edges=180000;
int n,m,l,k;
int map[80][80];
int s,t;
struct node 
{
	int v,next;
	int flow;
}e[edges];
int head[nodes],cnt;
class Dinic
{
    public:
        int spath()
        {
            queue<int>q;
            while(!q.empty()) q.pop();
            memset(dis,-1,sizeof(dis));
            dis[s]=0;
            q.push(s);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i=head[u];i+1;i=e[i].next)
                {
                    int v=e[i].v;
                    if(dis[v]==-1&&e[i].flow>0)
                    {
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
            return dis[t]!=-1;
        }
        int Min(int a,int b)
        {
            if(a<b) return a;
            return b;
        }
        int dfs(int u,int flow)
        {
            int cost=0;
            if(u==t) return flow;
            for(int i=head[u];i+1;i=e[i].next)
            {
                int v=e[i].v;
                if(dis[v]==dis[u]+1&&e[i].flow>0)
                {
                    int min=dfs(v,Min(e[i].flow,flow-cost));
                    if(min>0)
                    {
                        e[i].flow-=min;
                        e[i^1].flow+=min;
                        cost+=min;
                        if(cost==flow) break;
                    }
                    else dis[v]=-1;
                }
            }
            return cost;
        }
        int result()
        {
            int res=0;
            while(spath())
            {
                res+=dfs(s,inf);
            }
            return res;
        }
    private:
        int dis[nodes];
}dinic;
void Init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
void add(int a,int b,int c)
{
	e[cnt].v=b;
	e[cnt].next=head[a];
	e[cnt].flow=c;
	head[a]=cnt++;
	
	e[cnt].v=a;
	e[cnt].next=head[b];
	e[cnt].flow=0;
	head[b]=cnt++;
}
void Input()
{
	scanf("%d%d%d%d",&n,&m,&l,&k);
	memset(map,0,sizeof(map));
	for(int i=1;i<=l;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		map[a][b]=1;
	}
}
bool judge(int tim)
{
	s=0;t=2*m+n+1;
	Init();
	for(int i=1;i<=n;i++)
	add(s,i,tim);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]) add(i,n+j,1);
			else add(i,n+m+j,1);
		}
	}
	for(int i=1;i<=m;i++)
	{
		add(n+m+i,n+i,k);
		add(n+i,t,tim);
	}
	int k=dinic.result();
	if(k>=tim*n) return true;
	else return false;
}
void treatment(int ca)
{
	int ans;
	int low=0,up=m;
	while(low<=up)
	{
		int mid=(low+up)/2;
		if(judge(mid))
		{
			ans=mid;
			low=mid+1;
		}
		else up=mid-1;
	}
	printf("Case %d: %d\n",ca,ans);
} 
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		Input();
		treatment(ca++);
	}
	return 0;
}