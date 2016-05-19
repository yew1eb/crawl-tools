#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	int num,n,t,s,x,j,z,temp;
	cin>>t;
	while(t--)
	{
		cin>>num>>n;
		s=0;
		for(z=1;z<=n/3;z++)
		{
			temp=0;
			x=(n-z)/2;
			j=max(z,n/2-z+1);
			
			if(x+z<=n-z-x||x>n-z-x)continue;
			if(j==z)
			{
				temp=z;
				s--;
			}
			if(temp!=x&&x==n-z-x)s--;
			s+=(x-j+1)*2;
			//cout<<z<<" "<<x<<" "<<j<<" "<<temp<<" "<<s<<endl;


		}
		cout<<num<<" "<<s<<endl;
	}
	return 0;
}