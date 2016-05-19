#include<cstdio>
#include<cstring>
#define clr(a) memset(a,0,sizeof(a))
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
char qi[16][16];
int sum(int s)
{
	int sum=0;
	while(s)
	{
		if(s%2) sum++;
		s/=2;
	}
	return sum;
}
int play()
{
	int i,j;
	scanf("%s",qi[0]);
	if(qi[0][0]=='E') return 0;
	for(i=1;i<15;++i)
	{
		scanf("%s",qi[i]);
	}
	int s,f[15],ans=0x3f3f3f3f;
	for(s=0;s<(1<<15);++s)
	{
		clr(f);
		int tmp=0;
		for(i=0;i<15;++i)
		{
			if((s&(1<<i))==0)
			{
				for(j=0;j<15;++j)
				{
					if(qi[i][j]=='#')
						f[j]=1;
				}
			}
		}
		for(i=0;i<15;++i)
			tmp+=f[i];
		ans=min(max(tmp,sum(s)),ans);
	}
	printf("%d\n",ans);
	return 1;
}

int main()
{
	while(play());
	return 0;
}