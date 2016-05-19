/*
	这是昨天比赛很水的题目，而我却没有做出来，真是不应该的；
	题目没有看仔细，What 以.结尾不要 回答的，这点注意就OK
	发现STL很强大，决定好好学下。
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	string str;
	while( getline(cin, str) )
	{
		string str1 = "What";
		size_t found1;
		found1 = str.find(str1);
		int i;
		while(found1 != string::npos)
		{
			int len = str.size();
			for(i = found1 + 4; i < len; i++)
			{
				if(str[i] == '?')
				{
					cout << "Forty-two";
					for(int j = found1 + 4; j < i; j++)
						cout << str[j];
					cout << "." << endl;
					//found1 = i;
					break;
				}
				if(str[i] == '.')
				{
					//found1 = i;
					break;
				}
			}
			found1 = str.find(str1, found1 + (i - 4 - found1));
		}
	}
}