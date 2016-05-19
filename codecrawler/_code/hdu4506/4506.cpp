#include"iostream"
#include"cstdlib"
using namespace std;

int n;
int aim[111];
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int T;
	int i;
	int now,ans;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>aim[i];
		qsort(aim,n,sizeof(int),cmp);

		now=ans=0;
		for(i=0;i<n;i++)
		{
			if(aim[i]==now)	{if(i==0)ans+=5;ans++;continue;}
			ans+=(aim[i]-now)*6;
			now=aim[i];
			ans+=5;
			ans++;
		}
		ans+=now*4;
		cout<<ans<<endl;
	}
	return 0;
}