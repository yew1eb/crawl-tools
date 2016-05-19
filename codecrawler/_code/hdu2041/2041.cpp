#include<iostream>
using namespace std;
int main()
{
	int n,m,i;
	int da[51];
	cin>>n;
	da[1] = 0;
	da[2] = 1;
	da[3] = 2;
	for(i = 4; i <= 40; i++)
		da[i] = da[i-1] + da[i-2];
	while(n--)
	{
		cin>>m;
		cout<<da[m]<<endl;
	}
	return 0;
}