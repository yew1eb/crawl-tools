#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

bool isprim(int n)
{
	int res = sqrt(n + 0.0); //注意超时~
	for(int i = 2; i <= res; ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num, n, count;
	while(scanf("%d", &num) != EOF)
	{
		count = 0;	
		for(int i =0; i < num; ++i)
		{
			scanf("%d", &n);
			if(isprim(n))
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}