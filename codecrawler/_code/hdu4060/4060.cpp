#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 2010

int h,w,n,m,t;
char s[N][N];
int sum[N][N];
int cntr[300],cntc[300];
bool map[300][300],vis[300];
int link[300];
vector<pair<int,int> >que;

bool dfs(int x)
{
	for (int i=0;i<=m;i++)
	if (!vis[i] && map[x][i])
	{
		vis[i]=1;
		if (link[i]==-1 || dfs(link[i]))
		{
			link[i]=x;
			return 1;
		}
	}
	return 0;
}

int main()
{
	while(scanf("%d%d%d%d%d",&h,&w,&n,&m,&t)!=EOF)
	{
		for (int i=0;i<h;i++)
			scanf("%s",s[i]);
		que.clear();
		if (n==m)
		{
			if (h==w)
			{
				for (int i=1;i*n<h;i++)
				{
					int x=i;
					int y=h-i*n;
					if (y%(n+1)!=0) continue;
					y/=n+1;
					if (y>x) continue;
					que.push_back(make_pair(x,y));
				}
			}
		}
		else
		{
			int x,y;
			bool flag=1;
			x=w*n-h*m;y=n-m;
			if (x%y==0) x/=y;
			else flag=0;

			int tx=h*(m+1)-w*(n+1);
			y=n-m;
			
			if (tx%y==0) y=tx/y;
			else flag=0;
			
			if (x<=0 || y<=0 || x<y) flag=0;
			if (flag && n*x+(n+1)*y==h && m*x+(m+1)*y==w)
			{
				que.push_back(make_pair(x,y));
			}
		}
		if (que.size()==0) 
		{
			printf("-1\n");
			continue;
		}
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++)
			sum[i][j]=sum[i][j-1]+sum[i-1][j]+(s[i-1][j-1]-'0')-sum[i-1][j-1];

		int ans=2100000000;

		for (int jj=0;jj<que.size();jj++)
		{
			int x=que[jj].first,y=que[jj].second,z=x+y;
			int ans1=0;
			memset(cntr,0,sizeof(cntr));
			memset(cntc,0,sizeof(cntc));
			memset(map,0,sizeof(map));
			memset(link,-1,sizeof(link));
			for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				int tt=sum[i*z][j*z]-sum[i*z-x][j*z]-sum[i*z][j*z-x]+sum[i*z-x][j*z-x];
				if (tt!=x*x) ans1++;
			}
			for (int i=0;i<=n;i++)
			for (int j=0;j<=m;j++)
			{
				int tt=sum[i*z+y][j*z+y]-sum[i*z][j*z+y]-sum[i*z+y][j*z]+sum[i*z][j*z];
				cntr[i]+=tt;
				cntc[j]+=tt;
			}

			for (int i=0;i<=n;i++)
			for (int j=0;j<=m;j++)
			{
				int tt=sum[i*z+y][j*z+y]-sum[i*z][j*z+y]-sum[i*z+y][j*z]+sum[i*z][j*z];
				if (!tt) continue;
				if (cntr[i]-sum[i*z+y][w]+sum[i*z][w]!=0 || cntc[j]-sum[h][j*z+y]+sum[h][j*z]!=0)
					continue;
				map[i][j]=1;
			}
			for (int i=0;i<=n;i++) if (cntr[i]-sum[i*z+y][w]+sum[i*z][w]!=0) ans1++;
			for (int i=0;i<=m;i++) if (cntc[i]-sum[h][i*z+y]+sum[h][i*z]!=0) ans1++;

			for (int i=0;i<=n;i++)
			{
				memset(vis,0,sizeof(vis));
				if (dfs(i)) ans1++;
			}
			ans=min(ans,ans1);
		}
		printf("%d\n",t*ans);
	}
	return 0;
}
/*
61 6 1
00000
01110
01110
01110
11111
11111
*/