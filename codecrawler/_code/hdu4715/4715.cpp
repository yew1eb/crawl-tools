/*
 *  Author:      illuz <iilluzen[at]gmail.com>
 *  Blog:        http://blog.csdn.net/hcbbt
 *  File:        10.cpp
 *  Create Date: 2013-09-08 12:55:09
 *  Descripton:  10 
 */

#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

set<int> m;
#define MAX_P  1000001
int nList[MAX_P] = {0};
void Calc() 
{
	int n,p,t,sq=(int)sqrt(MAX_P*2+1);
	for (n=3;n<=sq;n+=2)
	{
		if (nList[n>>1]) continue;
		for (t=n*n;t<=MAX_P<<1;t+=n<<1) //筛选循环
			nList[t>>1] = 1;
	}
	m.insert(2);
	for (n=t=1;t<MAX_P;++t)
	{
		if (nList[t]) continue;
		m.insert((t<<1)+1);
		if (++n==10)
			n=0;
	}
}
/****** TEMPLATE ENDS ******/

const int MAXN = 0;

int main() {
	Calc();
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int nn = abs(n);
		bool flag = false;
		for (set<int>::iterator i = m.begin(); i != m.end(); i++) {
			if (m.count(*i + nn) != 0) {
				flag = true;
				if (n < 0) printf("%d %d\n", *i, *i + nn);
				else printf("%d %d\n", *i + nn, *i);
				break;
			}
		}
		if (!flag) printf("FAIL\n");
	}
	return 0;
}

