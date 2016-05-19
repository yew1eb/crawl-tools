/*
	Author: ACb0y
	Date: 2010-9-05
	Type: force
	ProblemId: hdu 1583 DNA Assembly
	Result: 2919263 2010-09-05 10:02:43 Accepted 1583 281MS 272K 1079 B C++ ACb0y 
*/
#include <iostream>
#include <string>
using namespace std;

int n;
int ans;
int d[10];
int vis[10];
string str[10];

//字符串合并
string str_merge(string a, string b)
{
	if (a == "") 
	{
		return b;
	}
	int i;
	int flag = 0;
	int pos;
	int alen = a.length();
	int blen = b.length();
	
	for (i = 1; i <= alen; i++) 
	{
		if (b.substr(0, i) == a.substr(alen - i, i))
		{
			flag = 1;
			pos = i;
		} 
	}
	if (flag) 
	{
		return a + b.substr(pos, blen - pos);
	}
	else 
	{
		return a + b;
	}
}

//回溯法求N！
void dfs(int pos)
{
	int i;
	if (pos == n) 
	{
		string temp = "";
		for (i = 0; i < n; i++) 
		{
			temp = str_merge(temp, str[d[i]]);
		}
		if (temp.length() < ans) 
		{
			ans = temp.length();
		}
	}
	else 
	{
		for (i = 0; i < n; i++) if (!vis[i])
		{
			d[pos] = i;
			vis[i] = 1;
			dfs(pos + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int i;
#ifndef ONLINE_JUDGE
	freopen("1583.txt", "r", stdin);
#endif
	while (cin >> n) 
	{
		for (i = 0; i < n; i++) 
		{
			cin >> str[i];
		}
		memset(vis, 0, sizeof(vis));
		ans = 10000;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}