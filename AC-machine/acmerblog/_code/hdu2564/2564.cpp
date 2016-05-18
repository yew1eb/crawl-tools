#include<iostream>
#include<string>
using namespace std;
char b[10010];

void run(char b)
{
	if(b >= 'a' && b <= 'z')
		printf("%c", b - 32);
	else if(b >= 'A' && b <= 'Z')
		printf("%c", b);
}
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(b);
		int i;
		if(b[0] != ' ')
		{
			run(b[0]);
		}
		for(i = 0; i < strlen(b)-1; i++)
		{
			if(b[i] == ' ' && b[i]+1 != ' ')
			{
				run(b[i+1]);
			}
		}
		printf("\n");

	}
	return 0;
}