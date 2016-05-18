#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int a[10], b[10];

bool check() {
    int cnt = 0;
    for( int i = 1; i <= 9; ++i ) {
	if( b[i] >= 3 ) b[i] -= 3, ++cnt;
	while( i <= 7 && b[i] && b[i+1] && b[i+2] )
	    --b[i], --b[i+1], --b[i+2], ++cnt;
    }
    return cnt == 4;
}

bool ok() {
    for( int i = 1; i <= 9; ++i ) if( a[i] >= 2 ) {
	for( int j = 1; j <= 9; ++j )
	    b[j] = a[j];
	b[i] -= 2;
	if( check() )
	    return true;
    }
    return false;
}

int main()
{
    int x;
    while( cin >> x ) {
	memset(a, 0, sizeof(a)); a[x] = 1;
	for( int i = 1; i <= 12; ++i )
	    cin >> x, ++a[x];
	vector<int> ans;
	for( int i = 1; i <= 9; ++i ) {
	    ++a[i];
	    if( a[i] <= 4 && ok() )
		ans.push_back(i);
	    --a[i];
	}
	for( int i = 0; i < ans.size(); ++i )
	    printf( "%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ' );
    }
    return 0;
}