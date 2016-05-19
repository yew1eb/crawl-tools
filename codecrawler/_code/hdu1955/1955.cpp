#include <iostream>
using namespace std;

//***********************常量定义*****************************

const int SIZE = 205;


//*********************自定义数据结构*************************




//********************题目描述中的变量************************

//监狱的人数
int m;
//会发生冲突的对数
int r;


//**********************算法中的变量**************************

//map[i][j]表示i和j是否会冲突
int map[SIZE][SIZE];

//A组里的人数
int aSize;
//b组里的人数
int bSize;
//dp[i][j] 表示用A组的i个人换B组的j个人是否可行
bool dp[SIZE][SIZE];
//visited[0][i] 表示用A组中的点i是否被访问过
//visited[1][i] 表示用B组中的点i是否被访问过
bool visited[2][SIZE];


//***********************算法实现*****************************

void Init()
{
	memset( map, 0, sizeof(map) );
	memset( visited, 0, sizeof(visited) );
	memset( dp, 0, sizeof(dp) );
}

void Input()
{
	cin >> m >> r;
	for( int i=0; i<r; i++ )
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
}

//side=0  表示当前正在搜索A组
//side=1  表示当前正在搜索B组
//id 表示当前正在搜索的编号
void DFS( int side, int id )
{
	visited[side][id] = true;

	//如果当前搜索的是A组
	if( side == 0 )
	{
		//记录A组中的元素个数
		aSize++;
		for( int i=1; i<=m; i++ )
		{
			//搜索的是B组中对应的点
			if( map[id][i] && !visited[1][i] )
			{
				DFS( 1, i );
			}
		}
	}	
	else
	{
		bSize++;
		for( int j=1; j<=m; j++ )
		{			
			if( map[j][id] && !visited[0][j] )
			{
				DFS( 0, j );
			}
		}
	}
}

//利用二维背包计算
void Knapsack()
{
	dp[0][0] = true;
	for( int x=m/2; x>=aSize-1; x-- )
	{
		for( int y=m/2; y>=bSize-1; y-- )
		{
			//if( dp[x - aSize][y - bSize] )	dp[x][y] = true;
			if( dp[x][y] || dp[x - aSize][y - bSize] ) dp[x][y] = true;
		}
	}
}

void Output()
{
	for( int i=m/2; i>=0; i-- )
	{
		if( dp[i][i] )
		{
			cout << i << endl;
			break;
		}
	}
}

//************************main函数****************************

int main()
{
	freopen( "in.txt", "r", stdin );	
	
	int caseNum;
	cin >> caseNum;

	while( caseNum-- )
	{
		Init();		
		Input();
		for( int i=1; i<=m; i++ )
		{
			//跳过已经处理过的节点
			if( visited[0][i] ) continue;

			//计算A、B中的人数
			aSize = 0;
			bSize = 0;
			DFS( 0, i );	

			//利用二维背包计算
			Knapsack();
			
		}
		for( int i=1; i<=m; i++ )
		{			
			if( visited[1][i] ) continue;			
			aSize = 0;
			bSize = 0;
			DFS( 1, i );
			Knapsack();
			
		}
		Output();
	}
	return 0;
}