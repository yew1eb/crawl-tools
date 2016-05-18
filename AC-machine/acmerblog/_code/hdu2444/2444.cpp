#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=205;
int flag[N];
int map[N][N];
int match[N];
bool link[N];
int n,m;
int bfs()
{
    int j;
	memset(flag,-1,sizeof(flag));
	for(j=1;j<=n;j++)
	{
	if(flag[j]!=-1) continue;
	queue<int> q;
	flag[j]=1;
    q.push(j);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(map[k][i]&&flag[i]==flag[k])
			{
		    	return 0;
			}
			if(map[k][i]&&flag[i]==-1)
			{
				q.push(i);
				flag[i]=1-flag[k];
			}
		}
	}
	}
	return 1;
}
bool find(int x)
{
	int i,k;
	for(i=1;i<=n;i++)
	{
		if(map[x][i]==1)
		{
		  k=i;
		   if(!link[k])
		   {
			link[k]=true;
			if(!match[k]||find(match[k]))
			{
				match[k]=x;
				 return true;
			}
		   }
		}
	}
	return false;
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&n,&m))
	{
	 memset(map,0,sizeof(map));
     while(m--)
	 {
		 scanf("%d%d",&a,&b);
		 map[a][b]=1;
		 map[b][a]=1;
	 }
     if(!bfs())
	 {
		 printf("No\n");continue;
	 }
	 int count=0;
     memset(match,0,sizeof(match));
	 for(int i=1;i<=n;i++)
	 {
		memset(link,false,sizeof(link));
		 if(find(i))
		 {
			 count++;
		 }
	 }
	 printf("%d\n",count/2);
	}
	return 0;
}