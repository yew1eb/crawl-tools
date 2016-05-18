#include<cstdio>
#include<cstring>
#include<cmath>
int total,d,n;
int x[5],y[5],life[5],dead[5],totalhp,lif[5];
double f[6][6][6][6][6][6];
bool can[5][5];
bool DIS(int i,int j,int d)
{
	return	((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=d*d;
}

double dfs(int x)
{
	double &ans = f[lif[0]][lif[1]][lif[2]][lif[3]][lif[4]][x];
	if(ans>=0.0)
		return ans ;
	if(lif[0]+lif[1]+lif[2]+lif[3]+lif[4]<totalhp-n-1)
		return 0.0;
	ans=0;
	if(lif[x]+1>life[x])
		return 0.0;
	for(int i=0;i<5;++i)
		if(can[i][x])
		{
			int total=0;
			lif[x]++;
			for(int j=0;j<5;++j)
				if(can[i][j]&&lif[j])
					++total;
			ans+=dfs(i)/total;
			lif[x]--;
		}
	return ans;

}

int main()
{
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		for(int i=0;i<5;++i)
			scanf("%d%d",&x[i],&y[i]);
		totalhp=0;
		for(int i=0;i<5;++i)
		{
			scanf("%d",&life[i]);
			totalhp+=life[i];
		}

		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				if(i!=j)
				can[i][j]=DIS(i,j,d);
				else
				can[i][i]=false;
		for(int i=0;i<=5;++i)
			for(int j=0;j<=5;++j)
				for(int k=0;k<=5;++k)
					for(int u=0;u<=5;++u)
						for(int v=0;v<=5;++v)
							for(int w=0;w<5;++w)
								f[i][j][k][u][v][w]=-1;

		f[life[0]-1][life[1]][life[2]][life[3]][life[4]][0]=0.2;
		f[life[0]][life[1]-1][life[2]][life[3]][life[4]][1]=0.2;
		f[life[0]][life[1]][life[2]-1][life[3]][life[4]][2]=0.2;
		f[life[0]][life[1]][life[2]][life[3]-1][life[4]][3]=0.2;
		f[life[0]][life[1]][life[2]][life[3]][life[4]-1][4]=0.2;

		double ans[5]={0};
		for(lif[0]=0;lif[0]<=life[0];++lif[0])
		for(lif[1]=0;lif[1]<=life[1];++lif[1])
		for(lif[2]=0;lif[2]<=life[2];++lif[2])
		for(lif[3]=0;lif[3]<=life[3];++lif[3])
		for(lif[4]=0;lif[4]<=life[4];++lif[4])
		for(int i=0;i<5;++i)
		{
			if(lif[i]==0)
				ans[i]+=dfs(i);
 else
 dfs(i);
		}
		for(int i=0;i<5;++i)
			printf("%.3f%c",ans[i],i!=4?' ':'\n');
	}
}