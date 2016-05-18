#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define LL long long
#define maxint 2147483647
#define maxll 9223372036854775807
#define dg cout << "Here!" << endl;
using namespace std;

int main()
{
	int C, i, len;
	char s[10001], ch;
	scanf("%d", &C);
	while(C--)
	{
		scanf("%s", s);
		len = strlen(s);
		for(i = 0; i < len; i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				if(s[i+1] == '-' || s[i+1] == '\0')
                {
                    //ch = s[i] + 'A' - '1';
                    putchar(s[i] + 'A' - '1');
                    i++;
                }
				else if(s[i+1] >= '0' && s[i+1] <='9')
				{
				    //ch = (s[i] - '0')*10 + s[i+1] - '0' + 'A' - 1;
					putchar((s[i] - '0')*10 + s[i+1] - '0' + 'A' - 1);
					i++;
				}
				else putchar(s[i] + 'A' - '1');
			}
			else if(s[i] == '#')
				putchar(' ');

		}
		puts("");
	}
    return 0;
}