#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=110000;

int base,len,y[N],dir[N];
char x[N];
void add()
{
	int i;
	base=0;
	for(i=0;i<len;i++)
	{
		y[i]+=dir[i];
		y[i+1]+=y[i]/10;
		y[i]%=10;
		base+=y[i];
	}
	while(y[len])
	{
		base+=y[len];
		len++;
	}
}
int main()
{
	int T;
	int i;
	cin>>T;
	memset(dir,0,sizeof(dir));
	dir[0]=1;
	while(T--)
	{
		scanf("%s",x);
		strrev(x);
		memset(y,0,sizeof(y));
		for(i=0;x[i];i++)	y[i]=x[i]-'0';
		len=i;
		add();
		while(base%10)	add();
		for(i=len-1;i>=0;i--)	printf("%d",y[i]);
		cout<<endl;
	}
	return 0;
}