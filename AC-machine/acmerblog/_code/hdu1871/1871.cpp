#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

bool cmp(const string& str1,const string& str2)
{
	return (str1+str2)>(str2+str1);
}
int N,num;
vector<string> str;
char s[100];
void input()
{
	for(int i=0; i<N; i++)
	{
		scanf("%s", s);
		str.push_back(string(s));//memcpy(str[num++], s, strlen(s)+1);
	}
}
int main() 
{
	while(scanf("%d",&N)==1)
	{
		if(N==0) break;
		str.clear();
		input();
		sort(str.begin(), str.end(), cmp);//solve();
		for(int i=0; i<str.size(); i++)
			printf("%s",str[i].c_str());
		printf("\n");
	}
    return 0;
}