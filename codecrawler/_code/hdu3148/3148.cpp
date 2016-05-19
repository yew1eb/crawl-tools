//============================================================================
// Name        : J.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef long long LL;
const int P = 2147483647;
const int maxn = 101;
map< int, LL > f[ maxn ];
vector< int > fac;
LL c[ maxn ][ maxn ];
int n, m;
LL ff[ maxn ], iv[ maxn ];

int powmod( LL a, int b, int c){
	LL ret = 1;
	while(b){
		if(b & 0x1) ret = ret * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ret;
}

int gcd(int a, int b) {return b ? gcd( b, a % b) : a; }
inline int lcm( int a, int b){return (a / gcd( a, b)) * b;}

void get_fac( ){
	LL i;
	fac.clear();
	for(i = 1; i * i <= m; ++ i) if(m % i == 0){
		fac.push_back( i );
		if( m / i != i) fac.push_back( m / i );
	}
	sort( fac.begin(), fac.end());
}
void get(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; ++ i) f[ i ].clear();
}

void work(){
	get_fac();
	f[ 0 ][ 1 ] = 1;
	for(int i = 0; i < fac.size() && fac[ i ] <= n; ++ i) {
		for(int j = n; j >= 0; -- j)
			for(map<int, LL>::iterator p = f[ j ].begin(); p != f[ j ].end(); ++ p) {
				LL cc = 1;
				int cct = 1;
				for(int k = fac[ i ]; j + k <= n; k += fac[ i ], ++ cct) {
					cc = cc * c[n - j - k + fac[ i ]][ fac[ i ]] % P;
					cc = cc * ff[ fac[ i ] - 1 ] % P;
					LL &now = f[ j + k ][ lcm(p -> first, fac[ i ]) ];
					now = (now + (p-> second * cc % P )* iv[ cct ] % P) % P;
				}
			}
	}
	printf("%d\n", (int)f[ n ][ m ]);
}
void pre(){
	int i, j;
	for(i = 0; i < maxn; ++ i) for(j = 0; j <= i; ++ j)
		if(i == 0 || j == 0) c[ i ][ j ] = 1;
		else c[ i ][ j ] = (c[i - 1][ j ] + c[ i - 1][j - 1 ]) % P;
	ff[ 0 ] = 1;
	for(i = 1; i < maxn; ++ i)
		ff[ i ] =ff[i - 1] * i % P;
	iv[ 0 ] = 1;
	for(i = 1; i < maxn; ++ i)
		iv[ i ] = iv[i - 1] * powmod( i, P - 2, P) % P;
}

int main() {
	pre();
	int T;
	cin >> T;
	while(T --){
		get();
		work();
	}
	return 0;
}