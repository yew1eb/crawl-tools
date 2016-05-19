#include <iostream>
#include <string>
using namespace std;

int letter[300];
char str[300],map[300][300];

int main()
{

#ifndef ONLINE_JUDGE
	freopen("2.txt","r",stdin);
#endif

	int i,j;
	while (gets(str))		//read four line at one time
	{
		memset(letter,0,sizeof letter);
		for (j=0; str[j]; ++j)
		{
			if (isupper(str[j]))
				++letter[str[j]-'A'];
		}
		for (i=0; i < 3; ++i)
		{
			gets(str);
			for (j=0; str[j]; ++j)
			{
				if (isupper(str[j]))
					++letter[str[j]-'A'];
			}
		}					//end read

		memset(map,' ',sizeof map);
	
		for (j=0; j < 26; ++j)	//calculate how many time letter appears
		{
			for (; letter[j] > 0; --letter[j])
			{
				map[letter[j]][j+j] = '*';
			}
		}
		
		for (i=1; ; ++i)		//ignore the ending spaces
		{
			for (j=52; j >= 0; --j)
			{
				if (map[i][j] == '*')
				{
					map[i][j+1] = '\0';
					break;
				}
			}
			if (j < 0)
				break;
		}
		while (--i)
			puts(map[i]);
		puts("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	}
	return 0;
}