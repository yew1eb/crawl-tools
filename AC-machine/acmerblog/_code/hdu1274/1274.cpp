/*
 * 1274_5.cpp
 *
 *  Created on: 2013年8月7日
 *      Author: Administrator
 *
 *      章泽天,我的女神！！！！
 */


#include <iostream>

using namespace std;

string str;
int fun(int index){

	char c ;
	int k;
	int e = 0;

	for(c = str[index++] ; index < str.length() && c != ')' ; c  = str[index++]){

		for( k = 0 ; isdigit(c) ; c = str[index++]){
			k = 10*k + c - '0';
		}

		if(!k){
			k = 1;
		}

		if( c == '('){
			while(k--){
				e = fun(index);
			}

			index = e;
		}else{
			while(k--){
				cout<<c;
			}
		}


	}

	if( c == ')'){
		return index;
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> str;
		fun(0);
		cout<<endl;
	}
}