#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		cout<<(a%100+b%100)%100<<endl;
	}
	return 0;
}