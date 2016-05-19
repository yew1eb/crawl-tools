/*
 * 1236_1.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */

#include <iostream>

using namespace std;

struct Node {
	string name;
	int sum;

};

bool compare(Node a, Node b) {
	if (a.sum == b.sum) {
		return a.name < b.name;
	}

	return a.sum > b.sum;
}

int main() {
	int n, m, line;
	while (cin >> n >> m >>line, n) {
		Node students[n];

		int scores[m+1];

        memset(scores,0,sizeof(scores));
		int i;
		for (i = 0; i < n; ++i) {
			students[i].sum = 0;
		}
		for (i = 1; i <= m; ++i) {
			cin >>scores[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> students[i].name;
			int num;
			int j;
			cin >> num;
			for (j = 1; j <= num; ++j) {
				int jj;
				cin >>jj;
				students[i].sum += scores[jj];
			}


		}
		sort(students, students + n, compare);


		int count = 0;
		for (i = 0; i < n; ++i) {
			if (students[i].sum >= line) {
				count++;
			}
		}

		if (count != 0) {
			printf("%d\n", count);
			for (i = 0; i < n; ++i) {
				if (students[i].sum >= line) {

					cout << students[i].name << " " << students[i].sum << endl;
				}
			}
		} else {
			printf("0\n");
		}
	}

}