#include<iostream>
using namespace std;
int main()
{
	int t,n,k,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>k;
		if(k==1)
		{
			if(n%2==1)
			{
				cout<<"Case "<<i<<": first"<<endl;
			}
			else
			{
				cout<<"Case "<<i<<": second"<<endl;
			}
		}	
		else
		{
			if(k>=n)
			{
				cout<<"Case "<<i<<": first"<<endl;
			}
			else
			{
				cout<<"Case "<<i<<": second"<<endl;
			}
		}
	}
	return 0;
}