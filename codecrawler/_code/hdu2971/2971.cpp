/*
	又学了一招了，矩阵中有负数的时候，取模取了之后
	if(r.num[i][j] < 0)	r.num[i][j] += mod;
	就是因为这里一直错，于是开始乱七不遭地改，郁闷是后来xwc提醒说要考虑
	还有就是很奇怪，hdu oj 对于_int64 的要求很不高的，今天试了好多，感觉没有什么不可以的
	记得zoj是要用_int64  % I64d 的，有些oj long long int  %lld
 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Mat
{
	_int64 num[4][4];
	Mat()
	{
		for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			num[i][j] = 0;
	}
};
Mat mul(Mat a, Mat b, _int64 mod)
{
	Mat r;
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
		r.num[i][j] = 0;
	for(int i = 0; i < 4; i++)
	for(int k = 0; k < 4; k++)
	{
		
		if(a.num[i][k] == 0)
			continue;
			
		for(int j = 0; j < 4; j++)
		{
			
			if(b.num[k][j] == 0)
				continue;
				
			r.num[i][j] =(r.num[i][j] + a.num[i][k] * b.num[k][j]) % mod;
			if(r.num[i][j] < 0)
				r.num[i][j] += mod;
		}
		
	}
	return r;
}
Mat mal(Mat a, Mat b, _int64 n, _int64 mod)
{
	while(n)
	{
		if(n & 1)
		{
			b = mul(a , b, mod);
			n--;
		}
		else
		{
			a = mul(a, a, mod);
			n >>= 1;
		}
	}
	return b;
}
int main()
{
	int t;
	//cin >> t;
	scanf("%d", &t);
	while(t--)
	{
		_int64 a2, n, mod;
		//cin >> a2 >> n >> mod;
		scanf("%I64d %I64d %I64d", &a2, &n, &mod);
		_int64 sum2 = (a2 * a2 + 1) % mod;
		_int64 a3 = (2 * a2 * a2 - 1) % mod;
		_int64 a4 = (2 * a2 * a3 - a2) % mod;
		if(n == 1)
		{
			cout << "1" << endl;
			continue;
		}
		if(n <= 4)
		{
			if(n == 3)
				sum2 += a3 * a3;
			if(n == 4)
				sum2 += a3 * a3 + a4 * a4;
			cout << sum2 % mod << endl;
			continue;
		}
		Mat init, unit;
		for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			init.num[i][j] = 0;
			unit.num[i][j] = 0;
		}
		init.num[0][0] = (4 * a2 *  a2) % mod;	// 这里的取模我一开始是加了的，后来改的时候又去，郁闷
		init.num[0][1] = (2 - 8 * a2 * a2) % mod;
		init.num[0][2] = (4 * a2 *  a2) % mod;	
		init.num[0][3] = -1;
		init.num[1][0] = 1;	
		init.num[2][1] = 1;	
		init.num[3][2] = 1;
		unit.num[0][0] = (sum2 + a3 * a3 + a4 * a4) % mod;	
		unit.num[1][0] = (sum2 + a3 * a3) % mod;
		unit.num[2][0] = sum2 % mod; 
		unit.num[3][0] = 1;
		Mat ans;
		ans = mal(init, unit, n - 4, mod);
		printf("%I64d/n", ans.num[0][0]);
		//cout << ans.num[0][0] % mod << endl;
	}
}