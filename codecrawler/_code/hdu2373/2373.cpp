#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

#define INF 0x3ffffff
#define MAXN 1010

struct node
{
	int to;
	int dis;
	int next;
}edge[MAXN*MAXN];

int head[MAXN],en;
bool in[MAXN];
int s[MAXN];
int n,m,dis[MAXN];
int dp[MAXN];

void add(int u,int v,int w)
{
    edge[en].to=v;
    edge[en].dis=w;
    edge[en].next=head[u];
    head[u]=en++;

    edge[en].to=u;
    edge[en].dis=w;
    edge[en].next=head[v];
    head[v]=en++;
}

void spfa(int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		in[i]=false;
	}
	dis[s]=0;
	in[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		in[u]=false;
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[u]+edge[i].dis<dis[v])
			{
				dis[v]=dis[u]+edge[i].dis;
				if(!in[v])
				{
					q.push(v);
					in[v]=true;
				}
			}
		}
	}
}


int dag_dp(int u)
{
    if(dp[u]!=-1) return dp[u];
    int tmp=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dis[v]<dis[u]) tmp+=dag_dp(edge[i].to);
    }
    return dp[u]=tmp;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(head,-1,sizeof(head));en=0;
        int u,v,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        spfa(2);
        memset(dp,-1,sizeof(dp));
        dp[2]=1;
        dag_dp(1);
        printf("%d\n",dp[1]);
    }
    return 0;
}