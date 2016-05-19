#include <stdio.h>
#include <math.h>
#define N 35

__int64 one[N], two[N], lock[N], a[N], b[N];

int main()
{
	one[3] = 16; two[3] = 18; lock[3] = 104;
	for (int i = 4; i < 26; i++)
	{
		a[i] = ((__int64)(pow(2.0, i-1))-2) * 6 + 4 * ((__int64)(pow(2.0, i-2))-1);
		b[i] = 9 * ((__int64)(pow(2.0, i-1))-2);
		one[i] = one[i-1] + 4 * two[i-1] + a[i];
		two[i] = 2 * one[i-1] + 4 * two[i-1] + b[i];
		lock[i] = 2 * one[i] + 4 * two[i];
	}

	for (int i = 3; i < 26; i++)
	{
		printf("N=%d: %I64d\n", i, lock[i]);
	}
	return 0;
}