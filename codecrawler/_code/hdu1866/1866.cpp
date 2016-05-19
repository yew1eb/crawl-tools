/*
	Author: ACb0y
	Date: 2010-9-02
	Type: geometry (sum area of rectangle)
	ProblemId: hdu 1866
	Result: AC
*/
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}

int d[4];
int min_x, min_y, max_x, max_y;
char str[510];
int vis[1100][1100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1866.txt", "r", stdin);
#endif
	int i, j, k;
	while (gets(str))
	{
		int c = 0;
		int cnt = 0;
		int len = strlen(str);
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < len; i++) 
		{
			if (isdigit(str[i])) 
			{
				int temp = 0;
				while (isdigit(str[i++]))
				{
					temp *= 10;
					temp += str[i - 1] - '0';
				}
				d[c++] = temp;
				i--;
			}
			if (c == 4) 
			{
				c = 0;
				min_x = min(d[0], d[2]);
				max_x = max(d[0], d[2]);
				min_y = min(d[1], d[3]);
				max_y = max(d[1], d[3]);
				for (j = min_x; j < max_x; j++) 
				{
					for (k = min_y; k < max_y; k++) 
					{
						if (!vis[j][k])
						{
							vis[j][k] = 1;
							cnt++;
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}