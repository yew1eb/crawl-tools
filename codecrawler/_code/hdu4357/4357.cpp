#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 66;
char a[N], b[N];
bool check() {
	int n = 60;
	while(n -- > 0) {
		swap(a[0], a[1]);
		a[0] ++;
		a[1] ++;
		if(a[0] > 'z') a[0] = 'a';
		if(a[1] > 'z') a[1] = 'a';
		
		if(a[0] == b[0] && a[1] == b[1]) return true;
	}
	return false;
}

int main() {
	int T, cas = 0;
	scanf("%d", &T);
	while(T-- > 0) {
		scanf("%s%s", a, b);
		int n = strlen(a);
		bool ok = 0;
		if(n == 2) {
			if(check()) ok = 1;
			else ok = 0;
		} else {
			int s1 = 0, s2 = 0;
			for(int i = 0; i < n; i ++) {
				s1 += a[i] - 'a';
				s2 += b[i] - 'a';
			}
			if((s1+s2)&1) ok = 0;
			else ok = 1;
		}
		if(ok) printf("Case #%d: YES\n", ++cas);
		else printf("Case #%d: NO\n", ++cas);
	}
	return 0;
}