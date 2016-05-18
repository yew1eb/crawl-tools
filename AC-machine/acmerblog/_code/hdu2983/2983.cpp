#include<iostream>
#include<string>
#include<queue>
#define MAXINT 9999999
#define MAXN 1100
using namespace std;
int dis[MAXN],n,m,num,p[MAXN];
int vis[MAXN],cou[MAXN];
queue<int> Q;
struct edge
{
	int v,w,next;
	edge(int _next=0,int _v=0,int _w=0):next(_next),v(_v),w(_w){};
}e[MAXN*201];
bool spfa()
{
	for(int i=1;i<=n;i++)
		dis[i]=0;
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n;i++)
	{
		Q.push(i);
		vis[i]=1;
		cou[i]=1;
	}
	while(!Q.empty())
	{
		int t=Q.front();
		Q.pop();vis[t]=0;
		for(int j=p[t];j!=-1;j=e[j].next)
		{
			if(dis[e[j].v]>e[j].w+dis[t])
			{
				dis[e[j].v]=e[j].w+dis[t];
				if(!vis[e[j].v])
				{
					vis[e[j].v]=1;
					cou[e[j].v]++;					
					if(cou[e[j].v]>n)
						return false;
					Q.push(e[j].v);
				}
			}
		}
	}
	return true;
}
int main()
{
	char str;
	int a,b,c;
	while(cin>>n>>m)
	{
		 num=0;
		 memset(p,-1,sizeof(p));
		for(int i=0;i<m;i++)
		{
			cin>>str;
			if(str=='P')
			{
				cin>>a>>b>>c;
				e[num]=edge(p[a],b,c);
				p[a]=num++;
				e[num]=edge(p[b],a,-c);
				p[b]=num++;
			}
			else {
				cin>>a>>b;
				e[num]=edge(p[b],a,-1);
				p[b]=num++;
			}
		}
		if(spfa())
			cout<<"Reliable"<<endl;
		else cout<<"Unreliable"<<endl;
	}
	return 0;
}