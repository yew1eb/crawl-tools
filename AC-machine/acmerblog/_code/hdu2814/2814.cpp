#include <iostream> //������Ϊ�����ҵ�,�ύ��Ϊ����֤����Ƿ���ȷ.
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 400;

unsigned long long A, B, N;
int C;
int phi[MAXN];
int d[MAXN];
void init_phi()
{
	int i, j;
	for (i = 1; i < MAXN; i ++)
		phi[i] = i;
	for (i = 2; i < MAXN; i += 2)
		phi[i] /= 2;
	for (i = 3; i < MAXN; i += 2)
		if (phi[i] == i)
		{
			for (j = i; j < MAXN; j += i)
			{
				phi[j] = phi[j] / i * (i - 1);
			}
		}
}

int Fib_T (int mod)
{
	if (mod == 1)
		return 1;
	int t0 = 0, t1 = 1;
	int i;
	for (i = 1; ; i ++)
	{
		t0 = (t0 + t1) % mod;
		swap (t0, t1);
		if (t0 == 0 && t1 == 1)
			return i;
	}
}

int get_Fib (int n, int mod)
{
	int t0 = 0, t1 = 1;
	int i;
	for (i = 0; ; i ++)
	{
		if (i == n)
			return t0;
		t0 = (t0 + t1) % mod;
		swap (t0, t1);
	}
}

int bspow (int a, unsigned long long b, int mod)
{
	int ans = 1;
	while (b)
	{
		if (b % 2)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

int cal_G(int mod)
{
	if (mod == 1)
		return 0;
	int FT = Fib_T (mod);
	int ab = bspow (A % FT, B, FT);
	int t = get_Fib (ab, mod);
	return t;
}

int solve ()
{
	if (C == 1)
		return 0;
	int temp = cal_G (phi[C]);
	d[1] = cal_G (C);
	int i;
	for (i = 2; i < MAXN; i ++)
	{
		d[i] = bspow (d[i - 1], temp + phi[C], C);
	}
	int T;
	for (i = MAXN - 2; i >= 1; i --)
		if (d[i] == d[MAXN - 1])
		{
			T = MAXN - 1 - i;
			break;
		}
		int j = N % T;
		while (j + T < MAXN)
			j += T;
		return d[j];
}

int main ()
{
	//freopen ("2.txt", "r", stdin);
	//freopen ("3.txt", "w", stdout);
	int ca = 1, t;
	scanf ("%d", &t);
	init_phi();
	while (t --)
	{
		scanf ("%I64u%I64u%I64u%d", &A, &B, &N, &C);
		int ans = solve ();
		printf ("Case %d: %d\n", ca ++, ans);
	}
}