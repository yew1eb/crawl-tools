#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		double c=0,cs=0;
		for(int i=0;i<n;++i){
			double cr;
			string mark;
			cin>>cr>>mark;
			if(mark=="P"||mark=="N")continue;
			else if(mark=="A"){c+=cr;cs+=cr*4.0;}
			else if(mark=="A-"){c+=cr;cs+=cr*3.7;}
			else if(mark=="B+"){c+=cr;cs+=cr*3.3;}
			else if(mark=="B"){c+=cr;cs+=cr*3.0;}
			else if(mark=="B-"){c+=cr;cs+=cr*2.7;}
			else if(mark=="C+"){c+=cr;cs+=cr*2.3;}
			else if(mark=="C"){c+=cr;cs+=cr*2.0;}
			else if(mark=="C-"){c+=cr;cs+=cr*1.7;}
			else if(mark=="D"){c+=cr;cs+=cr*1.3;}
			else if(mark=="D-"){c+=cr;cs+=cr*1.0;}
			else if(mark=="F"){c+=cr;cs+=cr*0;}
		}
	//	cout<<cs<<' '<<c<<endl;
		if(c==0)cout<<"0.00"<<endl;
		else cout<<setiosflags(ios::fixed)<<setprecision(2)<<cs/c<<endl;
	}
	return 0;
}