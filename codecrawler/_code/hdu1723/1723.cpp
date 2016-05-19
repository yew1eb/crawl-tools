#include <iostream>
using namespace std;
long f[31];
#define min(a,b) (a>b?b:a)
int main()
{
	//freopen("in.txt","r",stdin);
	int M,N;
	while(cin>>N>>M,!(N==0&&M==0))
	{
		memset(f,0,sizeof(f));
		f[0]=0;f[1]=1;
		for(int i=2;i<=N;++i)
		{
			for(int k=1;k<=min(M,i);++k)
				f[i]+=f[i-k];
		}
		cout<<f[N]<<endl;
	}
	return 0;
}