/*
 * 1157_1.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */


#include <iostream>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,o[n];
		for(i = 0 ; i < n ; ++i){
			scanf("%d",&o[i]);
		}

		sort(o,o+n);

		cout<<o[n/2]<<endl;
	}
}