#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

typedef pair<int,int>mp;

struct cmp{
	bool operator()(mp a,mp b){//first表示位置,second表示距离
		if(a.first == b.first)return a.second>b.second;//距离从小到大排序
		return a.first>b.first;//位置从小到大排序 
	}
};

priority_queue<mp,vector<mp>,cmp>oq;

int main(){//优先队列插入复杂度logN 
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		while(!oq.empty())oq.pop();
		for(int i=0;i<n;++i){
			cin>>a>>b;
			oq.push(mp(a,b));
		}
		int num=1;
		mp next;
		while(!oq.empty()){
			next=oq.top();
			oq.pop();
			if(num&1)oq.push(mp(next.first+next.second,next.second));
			++num;
		}
		printf("%d\n",next.first);
	}
	return 0;
}