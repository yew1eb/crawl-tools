#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t; 
	cin >> t;
	while(t--)
	{
		int n;
		int flag = 0;
		char a[10];
		cin >> n;
		while(n--)
		{
			cin >> a;
			if(strcmp("Caps", a) == 0)
			{
				if(flag == 0)
					flag = 1;
				else
					flag = 0;
				continue;
			}
			if(strcmp("Shift", a) == 0)
			{
				cin >> a;
				if(flag == 1)
					putchar(tolower(a[0]));
				else
					putchar(toupper(a[0]));
				continue;
			}
			if(flag == 0)
				putchar( tolower(a[0]));
			else if(flag == 1)
				putchar( toupper(a[0]));
		}
		cout << endl;
	}
	return 0;
}