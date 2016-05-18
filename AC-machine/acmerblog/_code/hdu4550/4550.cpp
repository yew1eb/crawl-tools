#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=105;

int l,r;
char str[N],ans[N];
void find(int a,int b)
{
	if(b<a)	return ;
	int i,index;
	char min;
	min='9'+1;
	for(i=b;i>=a;i--)	if(str[i]<min)	{min=str[i];index=i;}
	for(i=b;i>index;i--)	ans[r--]=str[i];
	ans[l++]=str[index];
	find(a,index-1);
}
int main()
{
	int T;
	int i;
	int index,len;
	char min;
	cin>>T;
	while(T--)
	{
		scanf("%s",str);
		len=strlen(str);
		min='9'+1;
		for(i=len-1;i>=0;i--)
		{
			if(str[i]=='0')	continue;
			if(str[i]<min)	{min=str[i];index=i;}
		}
		if(min=='9'+1)
		{
			while(len--)	printf("0");
			cout<<endl;
			continue;
		}
		l=0;r=len-1;
		ans[l++]=min;
		for(i=len-1;i>index;i--)	ans[r--]=str[i];
		
		find(0,index-1);
		for(i=0;i<len;i++)	printf("%c",ans[i]);
		cout<<endl;
	}
	return 0;
}