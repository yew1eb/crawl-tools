#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define LL long long
#define eps 1e-6
double X,Y,P,Q;
int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%lf%lf%lf%lf",&X,&Y,&P,&Q);
		double t1=(X+Y)*P*Q+X*(1-Q);
		double t2=(X+Y)*P*(1-Q)+Y*Q;
		bool flag=0;
		double res;
		if(t1>t2-eps){
			flag=0;
			res=t1;
		}
		else {
			flag=1;
			res=t2;
		}
		if(flag)cout<<"wolf ";
		else cout<<"tiger ";
		printf("%.4f\n",res);
	}
	return 0;
}