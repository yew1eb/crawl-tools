#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int vis[1001][1001],n,m,si,sj,ei,ej,ans;
char g[1001][1001];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct state
{
	int x,y,cnt;
	state(int _x=0,int _y=0,int _cnt=0):x(_x),y(_y),cnt(_cnt){};  
    friend bool operator <(const state &a,const state &b)  
    {  
        return a.cnt>b.cnt;  
    } 
};
priority_queue<state> Q;
void BFS()
{
	Q.push(state(si,sj,0));
	vis[si][sj]=0;
	state tmp;
	while(!Q.empty())
	{
		tmp=Q.top();
		Q.pop();
		if(tmp.x==ei && tmp.y==ej)
		{
			ans=tmp.cnt;
			return ;
		}
		for(int k=0;k<4;k++)  
        {  
            int i=tmp.x+dir[k][0];  
            int j=tmp.y+dir[k][1];  
			int t;
			if(i>n || i<1|| j>m || j<1)
				continue;
			if(g[i][j]=='X')
				t=tmp.cnt;
			else t=tmp.cnt+1;
			if(vis[i][j]>t)
			{
				vis[i][j]=t;
				Q.push(state(i,j,t));
			}
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)==2 &&(n||m))
	{
	    getchar();
		for(int i=1;i<=n;i++)
		{
			gets(g[i]+1);
			for(int j=1;j<=m;j++)
			{
				//scanf("%c",&g[i][j]);
				vis[i][j]=INT_MAX;
			}
		}
		scanf("%d %d",&si,&sj);
		scanf("%d %d",&ei,&ej);
		ans=-1;
		while(!Q.empty())
			Q.pop();
		BFS();
		printf("%d\n",ans);
	}
	return 0;
}