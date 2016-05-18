#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int Gcd(int m, int n)
{
	return m == 0 ? n : Gcd(n % m, m );
}

int main()
{
	int ncase;
	int a, b, c;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d%d", &a, &b);
		int temp = a / b;
		for(int i = 2; ; ++i)
		{
			if(i * b != b && Gcd(temp, i) == 1)
			{
				printf("%d\n", i * b);
				break;
			}
		}
	}
	return 0;
}