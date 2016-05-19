#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 5005
using namespace std;
int f[MAXN][3],n,ans;
char s[MAXN];
void getf()
{
	n=strlen(s),ans=0;
	for(int k=0;k<n;++k)
		for(int i=0;i+k<n;++i)
		{
		  int j=i+k,now=k%3,pre2=(now-2+3)%3;//pre记录的是f(i,j)的上两层，这里的f[i+1][pre2]指的是f(i+1,j-1)
		  f[i][now]=(k==0 || (k==1 && s[i]==s[j]) || (i+1<=j-1 && s[i]==s[j] && f[i+1][pre2]));
                  //k==0还有k=1都要特殊处理，防止i+1>j-1

                  ans+=f[i][now];
		}
}
int main()
{
	while(~scanf("%s",s))
	{
		getf();
		cout<<ans<<endl;
	}
}