#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define LL long long
#define FF(i, n) for (int i = 0; i < n; i++)
#define M 2

int ans[M];
int ret[M][M], mod = 10007;
int init[M][M];
int s[M][M] = { 1, 1,
 1, 0 };

void ini(int n)
{
 FF(i, n) FF(j, n) init[i][j] = s[i][j];
}

void matmul(int a[][M], int b[][M], int n)
{
 int tp[M][M] = {0};
 FF(i, n) FF(k, n) if(a[i][k]) FF(j, n) if(b[k][j])
 tp[i][j] = (tp[i][j]+(LL)a[i][k]*b[k][j]) % mod;
 FF(i, n) FF(j, n) a[i][j] = tp[i][j];
}

void qmod(int n, int b)
{
 FF(i, n) FF(j, n) ret[i][j] = (i==j);
 for ( ; b; b >>= 1)
 {
 if (b & 1) matmul(ret, init, n);
 matmul(init, init, n);
 }
}

int cal(int a, int b)
{
 a %= mod;
 int res = 1;
 for ( ; b; b >>= 1)
 {
 if (b & 1) res = res * a % mod;
 a = a * a % mod;
 }
 return res;
}

int main()
{
 int n;
 while (cin >> n)
 {
 ini(M);
 qmod(M, n+1);
 cout << (cal(2,n)-2*ret[0][1]%mod+mod)%mod << endl;
 }
 return 0;
}