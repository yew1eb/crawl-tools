# include<stdio.h>
# include<string.h>
int f[10],visit[1005];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,n,m,k,t,ans,flag;
	f[0]=1;
	for(i=1;i<=8;i++)
		f[i]=f[i-1]*i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		flag=0;
		memset(visit,0,sizeof(visit));
		for(i=1;i<=n;i++)
		{
			ans=n-i+1;
			if(ans>8)
			{
				visit[i]=1;
				if(flag==0) {printf("%d",i);flag=1;}
				else printf(" %d",i);
			}
			else 
			{
				t=m/f[ans-1];
				if(m%f[ans-1]!=0) t++;
				k=0;
				for(j=max(1,n-9);j<=n;j++)
				{
					if(visit[j]==0) k++;
					if(k==t) break;
				}
				visit[j]=1;
				if(flag==0) {printf("%d",j);flag=1;}
				else printf(" %d",j);
				m-=(t-1)*f[ans-1];
			}
		}
		printf("\n");
	}
	return 0;
}