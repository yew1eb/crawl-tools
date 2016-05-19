#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <iostream>

#include <string>

#include <vector>

#include <map>

#include <set>

#include <algorithm>

using namespace std;

#define pub(x) push_back(x)

#define x first

#define y second

#define MP make_pair

typedef long long ll;

typedef long double real;



struct word
{
	string t;
	int s[30];
	void make()
	{
		memset(s, 0, sizeof s);
		for (size_t i = 0; i < t.size(); ++i)
			s[t[i]-'a']++;
	}
} dic[121]; 
char s[100];

int b[80][30];
bool cmp(const word &a, const word &b)
{ return a.t < b.t; }

bool match(int *s, int k)
{
	bool us = false, un =false;
	for (int i = 0; i < 26; ++i)
	{
		if (b[k][i] == 1 && s[i] == 0) return false;
		if (b[k][i] == 2 && s[i] > 0) return false;
		if (b[k][i] == 3 && s[i] > 0) us = true;
		if (b[k][i] == 3) un = true;
	}
	//printf("%d\n", k);
	if (!un) return true;
	return us;
}


int main()

{
	while (1)
	{
		gets(s);
		if (s[0] == '#') break;
		int m = 0;
		while (s[0] != '*')
		{
			dic[++m].t = s;
			dic[m].make();
			gets(s);
		}
		sort(dic + 1, dic + 1 + m, cmp);
		for (int i = 1; i <= m; ++i) dic[i].make();
		//for (int i = 1; i <= m; ++i){puts(dic[i].t.c_str());}	puts("----");
		//printf("%d\n", dic[1].s[0]);
		memset(b, 0, sizeof b);
		while (1)
		{
			gets(s);
			if (s[0] == '*') break;
			memset(b, 0, sizeof b);
			int k = 1;
			for (int i = 0; s[i]; ++i)
				if ('a' <= s[i]  && s[i] <= 'z')
				{
					if (i > 0 && s[i - 1] == '+')
						b[k][s[i] - 'a'] = 1; else
					if (i > 0 && s[i - 1] == '-')
						b[k][s[i] - 'a'] = 2; else
						b[k][s[i] - 'a'] = 3;
				} else
				if (s[i] == '|') 
					++k;
			//printf("%s %d %d\n", s, b[1]['e' - 'a'] , b[1]['a' - 'a']);
			int ans = -1;
			for (int i = 1; i <= m; ++i)
			{
				for (int j = 1; j <= k; ++j)
				if (match(dic[i].s, j)) {ans = i; break;}
				if (ans >= 0) break;
			}
			if (ans == -1) puts("NONE"); 
				else puts(dic[ans].t.c_str());
				
		}
		puts("$");
	}
	return 0;

}