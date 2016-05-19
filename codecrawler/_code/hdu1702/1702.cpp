/*
 * 1702_1.cpp
 *
 *  Created on: 2013年8月7日
 *      Author: Administrator
 *      为了能有章泽天这样的女朋友而不断努力。。。。
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int t, m;
	string str;
	cin >> t;
	stack<int> p;
	queue<int> q;
	while (t--) {
		/**
		 * 因为STL中的stack、queue没有专门的clear()函数
		 * 所以每次都要自己写清空stack、queue的函数
		 */
		while(!p.empty()){
			p.pop();
		}

		while(!q.empty()){
			q.pop();
		}
		cin >> m >> str;

		if (str == "FIFO") {

			for (int i = 0; i < m; ++i) {
				string cmd;
				int n;
				cin >> cmd;
				if (cmd == "IN") {
					cin >> n;
					q.push(n);
				} else if (cmd == "OUT") {
					if (!q.empty()) {
						int a = q.front();
						q.pop();
						cout << a << endl;
					} else {
						cout << "None" << endl;
					}

				}
			}
		} else {
			for (int i = 0; i < m; ++i) {
				string cmd;
				int n;
				cin >> cmd;
				if (cmd == "IN") {
					cin >> n;
					p.push(n);
				} else if (cmd == "OUT") {
					if (!p.empty()) {
						int a = p.top();
						p.pop();
						cout << a << endl;
					} else {
						cout << "None" << endl;
					}

				}
			}

		}

	}

}