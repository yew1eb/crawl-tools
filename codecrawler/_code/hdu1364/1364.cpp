#include<iostream>
#include<string>
#include<queue>
#define MAXINT 9999999
#define MAXN 110
using namespace std;
int dis[MAXN],n,m,min1,max1;
struct edge
{
	int u,v,w;
}e[MAXN];
bool bellman_ford()
{
	for(int i=min1;i<=max1;i++)
		dis[i]=MAXINT;
	dis[min1]=0;//这里可要也可不要，因为Bellman-Ford是对所有边进行操作的，即使没有源点也照样进行松弛操作
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dis[e[j].v]>dis[e[j].u]+e[j].w)
				dis[e[j].v]=dis[e[j].u]+e[j].w;
		}
	}
		for(int j=0;j<m;j++)
		{
			if(dis[e[j].v]>dis[e[j].u]+e[j].w)
				return false;
		}
		return true;
}
int main()
{
	char str[5];
	int a,b,c;
	while(cin>>n)
	{
		if(n==0) break;
		cin>>m;
		max1=0;min1=MAXN;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>str>>c;
			max1=max(a+b+1,max1);
			min1=min(a,min1);
			min1=min(b,min1);
			if(strcmp(str,"gt")==0)
			{
				e[i].u=a+b+1;
				e[i].v=a;
				e[i].w=-c-1;
			}
			else {
				e[i].v=a+b+1;
				e[i].u=a;
				e[i].w=c-1;
			}
		}
		if(bellman_ford())
			cout<<"lamentable kingdom"<<endl;
		else cout<<"successful conspiracy"<<endl;
	}
	return 0;
}