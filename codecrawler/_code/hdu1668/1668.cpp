#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>

using namespace std;

#define INF 0xFFFFFF 

int n,m;
long long  dp[1<<14][14][14];
long long num[1<<14][14][14];
int maps[14][14];
int v[14];

bool jud(int s,int i)
{
	if(i==0) return true;
	if(s&(1<<(i-1))) return true;
	return false;
}

void solve()
{
	int x,y,tmps,tmp;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	memset(maps,0,sizeof(maps));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		maps[x][y]=maps[y][x]=1;
	}
	if(n==1)
	{
		cout<<v[1]<<" "<<1<<endl;
		return;
	}
	memset(dp,-1,sizeof(dp));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		int j=0;
		j|=(1<<(i-1));
		dp[j][i][0]=v[i];
		num[j][i][0]=1;
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!jud(i,j)) continue;
			tmps=i^(1<<(j-1));
			for(int k=1;k<=n;k++)
			{
				if(k==j) continue;
				if(!jud(i,k)) continue;
				if(!maps[k][j]) continue;
				for(int q=0;q<=n;q++)
				{
					if(q==k || q==j) continue;
					if(!maps[q][k] && q) continue;
					if(!jud(tmps,q)) continue;
					if(dp[tmps][k][q]==-1) continue;
					tmp=v[j]+v[j]*v[k]+dp[tmps][k][q];
					if(maps[q][j]) tmp+=v[q]*v[j]*v[k];
					if(tmp==dp[i][j][k])
						 num[i][j][k]+=num[tmps][k][q];
					if(tmp>dp[i][j][k])
					{
						dp[i][j][k]=tmp;
						num[i][j][k]=num[tmps][k][q];	
					}
				}
			}
		}
	}
	long long ans1=-1,ans2=0;
	for(int s=(1<<n)-1,i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(ans1==dp[s][i][j])
				ans2+=num[s][i][j];
			if(dp[s][i][j]>ans1)
			{
				ans1=dp[s][i][j];
				ans2=num[s][i][j];
			}
		}
	}
	if(n==1)
	{
		cout<<ans1<<" "<<1<<endl;
		return;
	}
	if(ans1==-1) printf("0 0\n");
	else 
		cout<<ans1<<" "<<ans2/2<<endl; 
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}