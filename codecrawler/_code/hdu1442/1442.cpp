#include<cstdio>
#include<cstring>
using namespace std;
char name[30];
int getcode(char c)
{
	switch (c)
	{
	case 'B':
	case 'p':
	case 'F':
	case 'V':
		return 1;
		break;
	case 'C':
	case 'S':
	case 'K':
	case 'G':
	case 'J':
	case 'Q':
	case 'X':
	case 'Z':
		return 2;
		break;
	case 'D':
	case 'T':
		return 3;
		break;
	case 'L':
		return 4;
		break;
	case 'M':
	case 'N':
		return 5;
		break;
	case 'R':
		return 6;
		break;
	default:
		return 0;
	}
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
	for (int i = 1; i <= 9; i++)
		printf(" ");
	printf("NAME");
	for (int i = 14; i <= 34; i++)
		printf(" ");
	printf("SOUNDEX CODE\n");
	while (scanf("%s", name) == 1)
	{
		int u = 0;
		int v = 0;
		int t = 0;
		for (int i = 1; i <= 9; i++)
			printf(" ");
		printf("%s", name);
		for (int i = 10 + strlen(name); i <= 34; i++)
			printf(" ");
		printf("%c", name[0]);
		for (int i = 1; name[i] != '\0'; i++)
		{
			if (u != 0 && v != 0 && t != 0)
				break;
			switch (name[i])
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			case 'Y':
			case 'W':
			case 'H':
//continue;
				break;
			default:
				if (!u)
				{
					if (getcode(name[i - 1]) == getcode(name[i]))
						break;
					u = getcode(name[i]);
				}
				else if (!v)
				{
					if (getcode(name[i - 1]) == getcode(name[i]))
						break;
					v = getcode(name[i]);
				}
				else
				{
					if (getcode(name[i - 1]) == getcode(name[i]))
						break;
					t = getcode(name[i]);
				}
			}
		}
		printf("%d%d%d\n", u, v, t);
	}
	for (int i = 1; i <= 19; i++)
		printf(" ");
	printf("END OF OUTPUT\n");
	return 0;
}