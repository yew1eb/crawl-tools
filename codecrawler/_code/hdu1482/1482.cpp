#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int vis['Z'];
int istrue['Z'];
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		int min=0x3f3f3f3f;
		int max=-0x3f3f3f3f;
		int eps=max;								//计算与特殊值的差					
		string a[3],b[3],c[3];
		memset(vis,0,sizeof(vis));
		memset(istrue,0,sizeof(istrue));
		cin>>a[0]>>b[0]>>c[0];
		cin>>a[1]>>b[1]>>c[1];
		cin>>a[2]>>b[2]>>c[2];
		for(i=0;a[0][i];i++)
			vis[a[0][i]]=vis[b[0][i]]=1000;
		for(i=0;a[1][i];i++)
			vis[a[1][i]]=vis[b[1][i]]=1000;
		for(i=0;a[2][i];i++)
			vis[a[2][i]]=vis[b[2][i]]=1000;			//给出现过的字符标上特殊值。
		for(i=0;i<3;i++)
		{
			if(c[i]=="even") 
			{
				for(j=0;a[i][j];j++)
				{
					istrue[a[i][j]]=1;				//istrue数组记录绝对正确的硬币
					istrue[b[i][j]]=1;
				}
			}
			if(c[i]=="up")
			{
				for(j=0;a[i][j];j++)
				{
					vis[ a[i][j] ]++;
					vis[ b[i][j] ]--;
				}
			}
			if(c[i]=="down")
			{
				for(j=0;a[i][j];j++)
				{
					vis[ a[i][j] ]--;
					vis[ b[i][j] ]++;
				}
			}
		}
		int ok,k;
		for(i='A';i<='L';i++)
		{
			ok=1;
			if(vis[i]==0) continue;
			if(vis[i]<min) min=vis[i];
			if(vis[i]>max) max=vis[i];
			if(istrue[i]) continue;
			
			for(j='A';j<='L';j++)						//第一次判断，假币在++,--,计算后很可能是一个只出现一次的值
			{
				if(i==j||vis[j]==0||istrue[j]) continue;
				if(vis[i]==vis[j])
				{ok=0;break;}
			}
			if(ok)
			{
				
				if(abs(vis[i]-1000)>eps) {eps=abs(vis[i]-1000);k=i;}	//再一次判断，如果相差越大，说明越是假币				
			}
		}
		if(vis[k]==min) printf("%c is the counterfeit coin and it is light.\n",k);
		else printf("%c is the counterfeit coin and it is heavy.\n",k);
	}
	return 0;
}
/*
送数据
sample input 
12 
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 
AGHL BDEC even 
JKI ADE up 
J K even 
ABCDEF GHIJKL up 
ABC DEF even 
I J down 
ABCDEF GHIJKL up 
ABHLEF GDIJKC down 
CD HA even 
A B up 
B A down 
A C even 
A B up 
B C even 
DEFG HIJL even 
ABC DEJ down 
ACH IEF down 
AHK IDJ down 
ABCD EFGH even 
AB IJ even 
A L down 
EFA BGH down 
EFC GHD even 
BA EF down 
A B up 
A C up 
L K even 
ACEGIK BDFHJL up 
ACEGIL BDFHJK down 
ACEGLK BDFHJI down 
ACEGIK BDFHJL up 
ACEGIL BDFHJK down 
ACEGLK BDFHJI up 

sample output 
K is the counterfeit coin and it is light. 
I is the counterfeit coin and it is heavy. 
I is the counterfeit coin and it is light. 
L is the counterfeit coin and it is light. 
B is the counterfeit coin and it is light. 
A is the counterfeit coin and it is heavy. 
A is the counterfeit coin and it is light. 
L is the counterfeit coin and it is heavy. 
A is the counterfeit coin and it is light. 
A is the counterfeit coin and it is heavy. 
L is the counterfeit coin and it is light. 
K is the counterfeit coin and it is heavy.
*/