#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=110;
int e[maxn][maxn];
int vis[maxn],n;
int bfs(int x)//从x点开始分组。 
{
	queue<int>q;
	q.push(x);
	vis[x]=1;
	int i,j,k,u,v;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=1;i<=n;i++)
		{
			if(e[u][i]==1||u==i)continue;
			if(vis[i]==-1)
			{
				vis[i]=1-vis[u];
				q.push(i);
			}
			else if(vis[i]==vis[u])return 0;
		}
	}
	return 1;
}
int main()
{
	while(cin>>n)
	{
		int i,j,k,a;
		memset(e,0,sizeof(e));
		memset(vis,-1,sizeof(vis));
		for(i=1;i<=n;i++)
		{
			while(cin>>a&&a!=0)
			e[i][a]=1;
		}
		//改成无向图 
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(!e[i][j])e[j][i]=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]!=-1)continue;
			if(!bfs(i))break;
		}
		if(i<=n)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
/*
	题意：将n个人分成两组，使得每组中的每个人都认识剩余所有人。
	用二维数组e记录关系，e[i][j]==0表示i不认识j。
	vis[i]表示组别，分别为1和0。则可知若e[i][j]==0 ,则i和j必定是一个是0，一个是1。
bfs一遍，当出现矛盾的时候就不能分组。
	由于枚举所有点作起点，且起点为1组内。又e[i][j]=0,e[j][i]=1和e[i][j]=e[j][i]=0情况相同。
为避免起点为1造成的初始化错误，所以讲有向不认识图，改成无向图。例：不认识关系：3->1->2->4,
开始枚举1，则vis[1]=1,vis[2]=0,vis[4]=1,后枚举3,vis[3]=1,vis[1]=0,矛盾，可情况是能分成(3,2)和(1,4)的。 
*/