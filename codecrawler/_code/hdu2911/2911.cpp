#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define M 1005

int a[M][M];
int equ, var;

void ini () { memset (a, 0, sizeof(a)); }

int Gauss ()
{
	int i, j, k;
	int col = 0;
	for (k = 0; k < equ && col < var; k++, col++)
	{
		for (i = k+1; i < equ; i++) while (a[i][col])
		{
			LL tp = a[k][col] & a[i][col];
			for (j = col; j <= var; j++)
			{
				a[k][j] = a[k][j] ^ (a[i][j]&tp);
				swap (a[k][j], a[i][j]);
			}
		}
		if (a[k][col] == 0) { k--; continue; };
	}
	for (i = k; i < equ; i++)
		if (a[i][col] != 0)
			return -1;
	return var-k;
}

int p[65] = {
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293};

int main()
{
	int t, cc = 0, n, i, j, k = 62;
	LL x;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		ini ();
		equ = k; var = n;
		for (i = 0; i < n; i++)
		{
			scanf ("%lld", &x);
			for (j = 0; j < k && x >= p[j]; j++)
			{
				while (x % p[j] == 0)
				{
					a[j][i] = !a[j][i];
					x /= p[j];
				}
			}
		}
		int fn = Gauss ();
		LL ans = 1;
		if (fn == -1) ans = 0;
		else
		{
			int mod = 1000000007;
			while (fn--) ans = (ans<<1) % mod;
			ans = (ans-1+mod) % mod;
		}
		printf ("Case %d: %lld\n", ++cc, ans);
	}
	return 0;
}