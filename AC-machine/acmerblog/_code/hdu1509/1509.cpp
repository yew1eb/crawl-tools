/*
 * 1509_1.cpp
 *
 *  Created on: 2013年8月7日
 *      Author: Administrator
 */


#include <iostream>
#include <queue>

using namespace std;

struct Node{
	string name;
	int val;
	int priority;
	int num;
	friend bool operator<(Node a , Node b){
		if(a.priority != b.priority){
		
			//先输出优先级高的(即priority小的)
			return b.priority < a.priority;
		}

		//用来实现当优先级相同时根据进队顺序输出的功能
		return b.num < a.num;
	}
};
int main(){

	priority_queue<Node> q;
	Node cur , next;

	string str;
	int k = 0;
	while(cin >> str){
		if( str == "GET"){
			if(q.empty()){
				cout<<"EMPTY QUEUE!"<<endl;
			}else{
				cur = q.top();
				q.pop();

				cout<<cur.name<<" "<<cur.val<<endl;
			}
		}else{
			cin>>next.name>>next.val>>next.priority;

			//用来标记进队顺序,先进的num值小
			next.num = k++;
			q.push(next);
		}
	}



}