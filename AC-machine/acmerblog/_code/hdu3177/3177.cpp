/*
 * 3177_2.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */

#include <iostream>
using namespace std;
struct Node{
	int f;
	int l;
};

bool compare(Node a , Node b){
	return a.f + b.l < b.f + a.l;
}


int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int v , n;
		scanf("%d%d",&v,&n);
		int i;
		Node nodes[n];
		for(i = 0 ; i < n ; ++i){
			scanf("%d%d",&nodes[i].f,&nodes[i].l);
		}

		sort(nodes,nodes+n,compare);

		bool flag = true;
		for(i = 0 ; i < n ; ++i){
			if(nodes[i].l > v){
				printf("No\n");
				flag = false;
				break;
			}else{
				v -= nodes[i].f;
			}
		}


		if(flag){
			printf("Yes\n");
		}

	}
}