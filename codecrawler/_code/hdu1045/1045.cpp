#include <iostream>
using namespace std;

char map[10][10];
int n;
int ans;

int judge(int k) //判断该点能否放置大炮
{
	int x = k / n;
	int y = k % n;
	int i;
	for(i=y; i>=0; i--)		//从该点往左找
	{
		if(map[x][i] == 'X')
		{
			break;
		}
		if(map[x][i] == '@')
		{
			return false;
		}
	}
	for(i=x; i>=0; i--)   //从该点往上找
	{
		if(map[i][y] == 'X')
		{
			break;
		}
		if(map[i][y] == '@')
		{
			return false;
		}
	}
	return true;
}

void dfs(int k, int cnt)
{
	if(k == n * n)
	{
		if(cnt > ans)
		{
			ans = cnt;
		}
		return ;
	}
	if(map[k/n][k%n] == '.' && judge(k))  //若该点能放置大炮
	{
		map[k/n][k%n] = '@';      //'@' 标记为大炮
		dfs(k+1,cnt+1);
		map[k/n][k%n] = '.';	//回溯时恢复该点状态
	}
	dfs(k+1,cnt);  //不放
}

int main()
{
	while(cin>>n,n)
	{
		ans = 0;
		for(int i=0; i<n; i++)
		{
			cin>>map[i];
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}