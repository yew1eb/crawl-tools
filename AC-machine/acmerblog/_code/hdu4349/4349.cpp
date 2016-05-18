#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
int main()
{
	int n;
	int i;
	int cnt,ans;
	while(scanf("%d",&n)!=-1)
	{
		cnt=0;
		ans=1;
		while(n)	{cnt+=n%2;n/=2;}
		for(i=0;i<cnt;i++)	ans*=2;
		printf("%d\n",ans);
	}
	return 0;
}