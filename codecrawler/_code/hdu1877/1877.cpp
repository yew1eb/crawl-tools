#include<iostream>
#include<stack>
using namespace std;
int m,a,b;
stack<int> p;
int main()
{
	int t;
	while(cin>>m)
	{
		if(!m) break;
		cin>>a>>b;
		a+=b;
		if(a==0) {cout<<0<<endl;continue;}
		while(a)
		{
			t=a%m;
			p.push(t);
			a/=m;
		}
		while(!p.empty())
		{
			cout<<p.top();
			p.pop();
		}
		cout<<endl;
	}
	return 0;
}