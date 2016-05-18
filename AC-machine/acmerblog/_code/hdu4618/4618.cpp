#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=306;

int n,m,ans,map[N][N];
int max(int a,int b){
	return a>b?a:b;
}
int solve(int x1,int y1,int x2,int y2)
{
	int i,l,a,b;
	for(i=x1;i<=x2;i++)
	{
		a=y1;b=y2;
		while(a<b && map[i][a]==map[i][b])	{a++;b--;}
		if(a<b)	return 0;
	}
	for(l=y1;l<=y2;l++)
	{
		a=x1;b=x2;
		while(a<b && map[a][l]==map[b][l])	{a++;b--;}
		if(a<b)	return 0;
	}
	return 1;
}
int main()
{
	int T;
	int i,l,a,b,t;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		for(l=0;l<m;l++)
			scanf("%d",&map[i][l]);
		ans=1;
		for(i=0;i<n;i++)
		{
			if(i+ans>=n)	break;
			for(l=0;l<m;l++)
			{
				if(l+ans>=m)break;
				t=(n-i-1)>(m-l-1)?(m-l-1):(n-i-1);
				a=i+t;
				b=l+t;
				while(i+ans<=a)
				{
					if(solve(i,l,a,b))
					{
						ans=max(ans,a-i+1);
						break;
					}
					a--;b--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}