#include<stdio.h>
#include<string.h>

const int maxn=1005;
//const int hsz=999997777;
const int maxk=2;

int key[maxk]={17,37};

int map[maxn][maxn],sub[maxn][maxn];
int row[maxn][maxn][maxk],fin[maxn][maxn][maxk];
int pow[maxk];
int n,m;

void prepare()
{
	int tmp;
	
	for (int t=0;t<maxk;t++)
	{
		pow[t]=1;
		for (int i=1;i<m;i++) 
			pow[t] = pow[t] * key[t];
	}
	
	//for (int t=0;t<3;t++) printf("pow[%d] is %lld\n",t,pow[t]);
				
	for (int i=1;i<=n;i++)
	{
		for (int t=0;t<maxk;t++) row[i][m][t]=0;
			
		for (int j=1;j<=m;j++)
		{
			for (int t=0;t<maxk;t++)
				row[i][m][t] = key[t] * row[i][m][t] + map[i][j];
		}
		/*
		for (int t=0;t<3;t++)
			printf(" row[%d][%d][%d] is %d\n",i,m,t,row[i][m][t]);
		*/
		for (int j=m+1;j<=n;j++)
		{
			for (int t=0;t<maxk;t++)
			{
				tmp = row[i][j-1][t] - pow[t]*map[i][j-m];
				//if ( tmp<0 ) tmp+=hsz;
				
				row[i][j][t] = tmp*key[t] + map[i][j];
				
				
				//printf("row[%d][%d][%d] is %d\n",i,j,t,row[i][j][t]);
			}
		}
	}
	//printf("==========================================\n");
	
	for (int j=m;j<=n;j++)
	{
		for (int t=0;t<maxk;t++) fin[m][j][t]=0;		
			
		for (int i=1;i<=m;i++)
		{
			for (int t=0;t<maxk;t++)
			{
				fin[m][j][t] = key[t]*fin[m][j][t] + row[i][j][t];
				//printf("				[%d][%d] is %d %d\n",i,t,fin[m][j][t],row[i][j][t]);
			}
		}
		/*
		for (int t=0;t<3;t++)
			printf("fin[%d][%d][%d] is %d\n",m,j,t,fin[m][j][t]);
		*/
		for (int i=m+1;i<=n;i++)
		{
			for (int t=0;t<maxk;t++)
			{
				tmp = fin[i-1][j][t] - pow[t]*row[i-m][j][t];
				//if ( tmp<0 ) tmp+=hsz;
				
				fin[i][j][t] = key[t]*tmp + row[i][j][t];
				//printf("fin[%d][%d][%d] is %d %d\n",i,j,t,fin[i][j][t],tmp);	
			}
		}
		//printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
	
}

bool check(int x,int y)
{
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
		if ( map[i+x][j+x]!=sub[i][j] )
			return false;
	return true;
}

int getnum() 
{
	char c;
	while((c = getchar()), c != '0' && c != '1');
	return c - '0';
}

int main()
{
	while ( scanf("%d%d",&n,&m)!=EOF )
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				map[i][j]=getnum();
				
				//scanf("%d",&map[i][j]);
				
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				sub[i][j]=getnum();
				
				//scanf("%d",&sub[i][j]);
				
		if ( n<m )
		{
			printf("No\n");
			continue;
		}
		
		int srow[maxk],all[maxk];
		
		prepare();
		memset(all,0,sizeof(all));
		for (int i=1;i<=m;i++)
		{
			memset( srow,0,sizeof(srow));
			for (int j=1;j<=m;j++)	
			{
				for (int t=0;t<maxk;t++)
					srow[t] = srow[t]*key[t] + sub[i][j];
			}
			
			for (int t=0;t<maxk;t++)
			{
				all[t] = all[t]*key[t] + srow[t];
				//printf("srow[%d] is %d\n",t,srow[t]);
			}
		}	
		
		//for (int t=0;t<3;t++) printf("all[%d] is %d\n",t,all[t]);
		
		bool findans=false;
		
		for (int i=m;i<=n;i++)
		for (int j=m;j<=n;j++)	
		{
			int ok=0;	
			for (int t=0;t<maxk;t++)
			if ( fin[i][j][t]==all[t] )
				ok++;
			if ( ok==maxk && check(i-m,j-m) )
			{
				findans=true;
				break;
			}
		}
		if ( findans ) 
			printf("Yes\n");
		else
			printf("No\n");
	}
}