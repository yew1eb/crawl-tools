#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[])
{
	int cas,n,m,t;
	priority_queue<int,vector<int>,greater<int> >Q0;
	priority_queue<int,vector<int>,less<int> >Q1;
	int tmp_arr[2001],arr[2001];
	cin >> cas;
	while (cas--) {
		cin >> m >> n;
		for (int j=0; j<n; j++) {
			cin>>t;
			Q0.push(t);
		}
		while (--m) {
			int i=0;
			for (int j=0; j<n; j++)
				cin>>arr[j];
			while (!Q0.empty()) {
				tmp_arr[i++]=Q0.top();
				Q0.pop();
			}
			for (int j=0; j<n; j++)
				Q1.push(tmp_arr[j]+arr[0]);
			for (int j=1; j<n; j++) {
				for (int k=0; k<n; k++) {
					if (tmp_arr[k]+arr[j]>=Q1.top())
						break;
					Q1.push(tmp_arr[k]+arr[j]);
				}
				for (int j=Q1.size(); j>n; j--)
					Q1.pop();
			}

			while (!Q1.empty()) {
				Q0.push(Q1.top());
				Q1.pop();
			}
		}
		for (int j=0; j<n; j++) {
			j&&putchar(' ');
			cout<<Q0.top();
			Q0.pop();
		}
		puts("");
	}
	return 0;
}