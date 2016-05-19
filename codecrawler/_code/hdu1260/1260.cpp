#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
unsigned int time1[2001];
long time2[2001];
int min(int a,int b)
{
	return a>b?b:a;
}
void converttime(long time,struct tm &t)
{
	int hour=0,minute=0,second=0;
	second=time%60;
	minute=((time-second)/60)%60;	minute%=60;
	hour=(time-second-minute*60)/3600;	hour%=24;
	t.tm_hour+=hour;	t.tm_min+=minute;	t.tm_sec+=second;
}
int main()
{
	freopen("in.txt","r",stdin);
	struct tm t;
	t.tm_year=2013-1900;	t.tm_mon=4;	t.tm_mday=2;
	t.tm_hour=8;	t.tm_min=0;	t.tm_sec=0;	t.tm_isdst=0;
	char str[13];
	int N,K;
	cin>>N;
	while(N--)
	{
		memset(time1,0,sizeof(time1));
		memset(time2,0,sizeof(time2));
		t.tm_hour=8;	t.tm_min=0;	t.tm_sec=0;
		cin>>K;
		for(int i=1;i<=K;++i)
			cin>>time1[i];
		for(int i=1;i<=K-1;++i)
			cin>>time2[i+1];
		for(int i=2;i<=K;++i)
		{
			time1[i]=min(time1[i-1]+time1[i],time1[i-2]+time2[i]);
		}
		converttime(time1[K],t);
		strftime(str,13,"%H:%M:%S %p",&t);  
		cout<<strlwr(str)<<endl;
	}
	return 0;
}