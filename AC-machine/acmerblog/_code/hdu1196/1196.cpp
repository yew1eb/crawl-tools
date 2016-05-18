#include<iostream>
using namespace std;
int main(){int n,ans;
while(cin>>n){
	if(n==0)break;
		ans=1;
		while(n%2==0){
			n/=2;
			ans*=2;
		}

	cout<<ans<<endl;

}
	return 0;
}