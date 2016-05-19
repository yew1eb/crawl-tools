#include <iostream>
using namespace std;
int main()
{
	char ch;
	int n,i,j;
	int flag=0;//空行用 
	while(cin>>ch&&ch!='@'){
		cin>>n;
		if(flag) cout<<endl;
		flag=1;
		for(i=1;i<n;i++) cout<<" ";
		cout<<ch<<endl;
		for(i=2;i<n;i++){
			for(j=1;j<=n-i;j++) cout<<" ";
			cout<<ch;
			for(j=1;j<=2*i-3;j++) cout<<" ";
			cout<<ch<<endl;
		}
		if(n!=1)
		{
			for(i=1;i<=2*n-1;i++) cout<<ch;
			cout<<endl;
		}
	}
	return 0;
}