#include <iostream>
using namespace std;
int main()
{
	int d, n, i, a[32], l, flag;
	cin >> d;
	while (d--)
	{
		cin >> n;
		l = 0;
		while (n)
		{
			a[l++] = n%2;
			n /= 2;
		}
		flag = 1;
		for (i = 0; i < l; i++)
		{
			if(a[i])
				if (flag)
				{
					cout << i;
					flag = 0;
				}
				else 
					cout << " " << i;
		}
		cout<<endl;
	}
	return 0;
}