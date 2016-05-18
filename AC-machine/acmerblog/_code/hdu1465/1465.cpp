#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	long long dp[21];
	dp[1] = 0;
	dp[2] = 1;
	for( int i = 3; i <= 20; i++ ){
		dp[i] = ( dp[i-1] + dp[i-2] ) * ( i - 1 );
	}
	int N;
	while( scanf( "%d", &N ) != EOF ){
		cout << dp[N] << endl;
	}
	return 0;
}