#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int main() {
	int i, j, k, temp;
	map<int, int> a;
	a[0] = 0;
	for (i = 1; i <= 1000; i++) {
		k = int(sqrt(i));
		if (k * k == i)
			temp = 1;
		else {
			temp = 0;
			k++;
		}
		for (j = 1; j < k; j++)
			if (i % j == 0)
				temp += 2;
		if (a[temp] == 0)
			a[temp] = i;
	}
	cin >> i;
	while (i--) {
		cin >> j;
		if (a[j] == 0)
			cout << -1 << endl;
		else
			cout << a[j] << endl;
	}
	return 0;
}