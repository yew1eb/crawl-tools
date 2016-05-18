#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>

#define N 1100

using namespace std;

struct TR
{
	int son[26],f;bool fg;
}tr[N];

int n,q[N],m,len,cnt;
double dp[N][30][2],g[30];
char str[N];

inline void insert(char *s)
{
	int now=1;
	for(int i=0;i<len;i++)
	{
		if(!tr[now].son[s[i]-'a']) tr[now].son[s[i]-'a']=++cnt;
		now=tr[now].son[s[i]-'a'];
	}
	tr[now].fg=true;
}

inline void build()
{
	int h=1,t=2,sta; q[1]=1;
	while(h<t)
	{
		sta=q[h++];
		for(int i=0;i<26;i++)
		{
			int now=tr[sta].son[i],tmp;
			if(sta==1) tmp=1;
			else tmp=tr[tr[sta].f].son[i];
			if(now==0) tr[sta].son[i]=tmp;
			else
			{
				tr[now].f=tmp; tr[now].fg|=tr[sta].fg;
				q[t++]=now;
			}
		}
	}
}

inline void read()
{
	memset(g,0.0,sizeof g);
	double a;
	for(int i=1;i<=n;i++)
	{
		scanf("%s%lf",str,&a);
		g[str[0]-'a']=a;
	}
	memset(tr,0,sizeof tr);
	tr[cnt=1].f=1;
	scanf("%s",str);
	len=strlen(str);
	insert(str);
	build();
}

inline void go()
{
	memset(dp,0,sizeof dp);
	dp[0][1][0]=1.0;
	for(int i=0;i<m;i++)
		for(int j=1;j<=cnt;j++)
		{
			if(dp[i][j][0]>0.0)
			{
				for(int k=0;k<26;k++)
				{
					if(g[k]==0.0) continue;
					if(tr[tr[j].son[k]].fg) dp[i+1][tr[j].son[k]][1]+=dp[i][j][0]*g[k];
					else dp[i+1][tr[j].son[k]][0]+=dp[i][j][0]*g[k];
				}
			}
			if(dp[i][j][1]>0.0)
			{
				for(int k=0;k<26;k++)
				{
					if(g[k]==0.0) continue;
					dp[i+1][tr[j].son[k]][1]+=dp[i][j][1]*g[k];
				}
			}
		}
	double ans=0.0;
	for(int i=1;i<=cnt;i++) ans+=dp[m][i][1];
	printf("%.2lf%%\n",ans*100.0);
}

int main()
{
	while(scanf("%d%d",&n,&m),n||m) read(),go();
	return 0;
}