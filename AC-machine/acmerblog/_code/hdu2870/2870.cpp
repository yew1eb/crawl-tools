#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=1005;

int n,m,ans;
char map[N][N],map_t[N][N];
int cnt[N][N],le[N],ri[N];

void solve(char cc,char a,char b,char c)
{
	int i,l,temp;

	for(i=1;i<=n;i++)
	for(l=1;l<=m;l++)
	{
		if(map[i][l]==a || map[i][l]==b || map[i][l]==c)
			map_t[i][l]=cc;
		else	map_t[i][l]=map[i][l];
	}
	
	memset(cnt[0],0,sizeof(cnt[0]));
	memset(map_t[0],0,sizeof(map_t[0]));
	for(i=1;i<=n;i++)
	{
		cnt[i][0]=cnt[i][m+1]=-1;
		for(l=1;l<=m;l++)
		{
			le[l]=ri[l]=l;
			if(map_t[i][l]!=cc)	cnt[i][l]=0;
			else	cnt[i][l]=cnt[i-1][l]+1;
		}
		for(l=2;l<=m;l++)
		{
			if(!cnt[i][l])	continue;
			while(cnt[i][le[l]-1]>=cnt[i][l])	le[l]=le[le[l]-1];
		}
		for(l=m-1;l>0;l--)
		{
			if(!cnt[i][l])	continue;
			while(cnt[i][ri[l]+1]>=cnt[i][l])	ri[l]=ri[ri[l]+1];
		}
		for(l=1;l<=m;l++)
		{
			if(!cnt[i][l])	continue;
			temp=cnt[i][l]*(ri[l]-le[l]+1);
			if(ans<temp)	ans=temp;
		}
	}
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(i=1;i<=n;i++)	scanf("%s",map[i]+1);
		ans=0;
		solve('a','w','y','z');
		solve('b','w','x','z');
		solve('c','x','y','z');
		cout<<ans<<endl;
	}
	return 0;
}