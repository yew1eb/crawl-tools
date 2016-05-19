#include <iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
long f[1001][31];
long pre[31],cur[31];
int T,N,V,K,v[1000];
void ZeroOnePack(int cost,int weight)
{
	for(int i=V;i>=weight;--i)//典型01背包，倒序处理
	{
		int j;
		for(j=1;j<=K;++j)
		{
			pre[j]=f[i-weight][j]+cost;//从大到小排序，方便最后合并找最大的前K个值
			cur[j]=f[i][j];//从大到小排序，方便最后合并找最大的前K个值
		}
		pre[j]=cur[j]=-1;
		int fi=1,pi=1,ci=1;
		while(fi<=K && (pre[pi]!=-1 || cur[ci]!=-1))
		{
			if(pre[pi]>cur[ci]) f[i][fi]=pre[pi++];
			else f[i][fi]=cur[ci++];
			if(f[i][fi]!=f[i][fi-1]) ++fi;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int tempcost=0;
	long maxdata=0;
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		memset(pre,0,sizeof(pre));
		memset(cur,0,sizeof(cur));
		cin>>N>>V>>K;
		for(int i=0;i<N;++i)
			cin>>v[i];
		for(int i=0;i<N;++i)
		{
			cin>>tempcost;
			ZeroOnePack(v[i],tempcost);
		}
		cout<<f[V][K]<<endl;
	}
	return 0;
}