#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")  
typedef __int64 ll;
const int MAXN = 205;
const ll mod = 1000000007;
ll AA[MAXN], CC[MAXN][MAXN], POW[MAXN], CM[MAXN][MAXN];
ll niyuan(ll a)
{
	ll res = 1, p = a;
	int n = mod-2;
	while (n)
	{
		if (n & 1) res = res*p%mod;
		p = p*p%mod;
		n >>= 1;
	}
	return res;
}
void init()
{
	int j, i, k;
	for (AA[0] = 1, i = 1; i<= 200; ++i) AA[i] = AA[i-1]*i%mod;
	for (POW[0] = 1, i = 1; i<= 200; ++i) POW[i] = POW[i-1]*2%mod;
	CC[0][0] = 1;
	CM[0][0] = 1;
	for (i = 1; i<= 200; ++i)
	{
		for ( j = 0, k=i/2+1; j<k; ++j)
		{
			CC[i][j] = AA[i]*niyuan(AA[i-j]*AA[j]%mod)%mod;
			CC[i][i-j] = CC[i][j];
		}
		CM[i][0] = 1;
		for ( j = 1; j<=i; ++j)
			CM[i][j] = (CM[i][j-1] + CC[i][j])%mod;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	int t, N, M, P, Q, i, j, a, b, k, x, mx, mn, pp, qq;
	ll res, s1, s2, s3;
	init();
	scanf("%d", &t);
    while(t--)
    {
		scanf("%d%d%d%d", &N, &M, &P, &Q);
		res = 0;
		for (i=0; i<=N && (i<<1)<=M && (i<<1)<=P; ++i) // 2H_0
		{
			s1 = CC[N][i]*CC[M][i<<1]%mod*AA[i<<1]%mod*niyuan(POW[i])%mod;
			for (j = 0; j<=M-(i<<1) && (j<<1)<=N-i && (j<<1)<=P-(i<<1); ++j) // 2H_1
			{
				s2 = CC[N-i][j<<1]*CC[M-(i<<1)][j]%mod*AA[j<<1]%mod*niyuan(POW[j])%mod * s1;
				s2 %= mod;
				pp = P-2*i-2*j; qq = Q;
				for (a=N-i-2*j,b=M-2*i-j,k=0,x=pp+qq; k<=a && k<=b && k<=x; ++k) // 1L 1H
				{
					mx = min(k, pp);
					mn = max(0, k-qq);
					s3 = s2*(  CC[a][k]*CC[b][k]%mod*AA[k]%mod*(CM[k][mx]-(mn==0?0:CM[k][mn-1]))%mod)%mod;
					//printf("%d..%d..%d..%I64d\n", i,j,k,s3);
					res = (res + s3) % mod;
				}
			}	
		}
		printf("%I64d\n", (res-1+mod)%mod);
    }
    return 0;
}
