#include <iostream>
#include <map>
#include <string>
using namespace std;

int prime[7000];
int cnt;

bool isok (int x)
{
	for (int i = 0; i < cnt && prime[i]*prime[i] <= x; i++)
		if (x % prime[i] == 0) 
			return false;
	return true;
}
void getprime ()
{
	cnt = 2;
	prime[0] = 2;
	prime[1] = 3;
	for (int i = 5; i < 65535; i ++)
		if (isok (i)) prime[cnt++] = i;
}

int divisor (int n)
{
	int count = 0;
	//prime[i]*prime[i] <= n;省了很多时间
	for (int i = 0; i < cnt && prime[i]*prime[i] <= n; i++)
	{
		if (n % prime[i] == 0)
		{
			count ++;
			while (n % prime[i] == 0 && n)
				n /= prime[i];
		}
	}
	//灰常重要 BUG
	if (n > 1) count++;
	return count;
}

int main()
{
	getprime();
	int t;
	cin >> t;
	while(t--)
	{
		map<string, int> m;
		int n; 
		cin >> n;
		string a;
		int num;
		while(n--)
		{
			cin >> a >> num;
			m.insert(pair<string, int>(a, divisor(num)));
		}
		int max = 0;
		string result;
		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
		{
			if(max < it->second)
			{
				max = it->second;
				result = it->first;
			}
		}
		cout << result << endl;
	}
	return 0;
}