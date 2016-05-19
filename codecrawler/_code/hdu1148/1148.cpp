#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include <sstream>
using namespace std;

const int N=105;

int player[N][2]; // player[i][0]: win , player[i][1]: lose. 

int n,k;
short judge(string a, string b)
{
	if(a == b)
	{
		return 0;
	}
	short result;
	if(a == "rock")
	{ 
		if(b == "scissors")
		{
			result = 1;
		}
		else if(b == "paper")
		{
			result = -1;
		}
	}
	else if(a == "scissors")
	{
		if(b == "rock")
		{
			result = -1;
		}
		else if(b == "paper")
		{
			result = 1;
		}
	}
	else
	{
		if(b == "scissors")
		{
			result = -1;
		}
		else if(b == "rock")
		{
			result = 1;
		}
	}
	return result;
}
int main()
{
	short ans;
	string sa,sb;
	int pa,pb;
	bool first = true;
	while(cin>>n && n)
	{
		if(!first)putchar('\n');
		if(first)first=false;
		memset(player,0,sizeof(player));
		cin>>k;
		while(k--)
		{
			cin>>pa>>sa>>pb>>sb;
			ans = judge(sa,sb);
			if(ans)
			{
				if(ans==1)//win
				{
					player[pa][0]++;
					player[pb][1]++;
				}
				else//lose
				{
					player[pb][0]++;
					player[pa][1]++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			int total = player[i][0]+player[i][1];
			if(total>0)
			{
				printf("%.3f\n",((float)player[i][0])/total);
			}
			else
			{
				printf("-\n");
			}
		}
	}
	return 0;
}