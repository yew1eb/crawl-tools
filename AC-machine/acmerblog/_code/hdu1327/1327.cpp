/*
题意：a有确定的值 其他的是随机值
通过运算，那些变量是确定的值
map 的应用
*/
//#pragma warning(disable: 4786)//加上这句可以屏蔽长标示符带来的警告
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,bool>m;
map<string,bool>::iterator it;
void pro(string s,string ss)
{
	it=m.find(ss);
	if(it==m.end())
	{
		m[ss]=false;
	}

	m[s]=m[ss];
}
int main()
{
	string s,ss;
	int i,n,j,ni=1;
	while(scanf("%d",&n),n)
	{
		m.clear();
		m.insert(pair<string,bool>("a",true));
		printf("Program #%d\n",ni++);
		for(i=1;i<=n;i++)
		{	
			cin>>s>>ss>>ss;
			pro(s,ss);
		}
		it=m.begin();
		int flag=0;
		while(it!=m.end())
		{
			if(it->second==true)
			{
				cout<<(it->first)<<" ";
				flag=1;
			}
			it++;
		}
		if(flag==0)
			cout<<"none";
		cout<<endl<<endl;
	}
	return 0;
}