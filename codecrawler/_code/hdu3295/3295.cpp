/*
	这题只要能模拟它的过程就行，但是要注意剪枝。
	而代码中的mark就是用来剪枝的。比方说，如果有几个color相同的连在一起，这时候我们只需要搜索其中一个其实就搜索了全部情况，
	所以加了个mark来标记下在某一情况下相连的是否已经搜索过。

	还有一点，在BFS2那里，用来搜索相同的颜色的时候，我开始用的DFS...但是就超出内存了... 但是估计是因为没用mark标记的原因吧......我也没试了.....
	不过我觉得这里用BFS还是比DFS好.....呵呵.....

	好吧，开始的时候没想到这来一直是memory limit exceeded.....好吧就这样了.....继续刷题.....
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct{
	int map[6][6];
	int count;
	int step;
}Node;

int mark[6][6];
int N, M;
int map[6][6];
Node start, midmap;
int flag, min;
int moves[][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

void BFS2( int i, int j, int color ){
	queue<int> q;
	midmap.map[i][j] = 0;
	midmap.count--;
	mark[i][j] = 1;
	q.push( i * 10 + j );
	while( !q.empty() ){
		int n = q.front();
		q.pop();
		for( int i = 0; i < 4; i++ ){
			int x = n / 10 + moves[i][0];
			int y = n % 10 + moves[i][1];
			if( x < 0 || y < 0 || x >= N || y >= M || midmap.map[x][y] != color ){
				continue;
			}
			mark[x][y] = 1;
			midmap.map[x][y] = 0;
			midmap.count--;
			q.push( x * 10 + y );
		}
	}
}

Node Handle( Node n ){
	Node temp = n;
	memset( temp.map, 0, sizeof( temp.map ) );
	for( int j = 0; j < M; j++ ){
		int k = N - 1;
		for( int i = N - 1; i >= 0; i-- ){
			if( n.map[i][j] != 0 ){
				temp.map[k--][j] = n.map[i][j];
			}
		}
	}
	int k = 0;
	for( int j = 0; j < M; j++ ){
		if( temp.map[N-1][j] != 0 ){
			for( int i = 0; i < N; i++ ){
				temp.map[i][k] = temp.map[i][j];
			}
			k++;
		}
	}
	while( k != M ){
		for( int i = 0; i < N; i++ ){
			temp.map[i][k] = 0;
		}
		k++;
	}
	return temp;
}

int BFS1(){
	queue<Node> q;
	for( int i = 0; i < N; i++ ){
		for( int j = 0; j < M; j++ ){
			if( start.map[i][j] ){
				midmap = start;
				BFS2( i, j, start.map[i][j] );
				Node temp = midmap;
				temp.step = 1;
				temp = Handle( temp );
				q.push( temp );
			}
		}
	}
	while( !q.empty() ){
		Node n = q.front();
		q.pop();
		if( n.count == 0 ){
			return n.step;
		}
		memset( mark, 0, sizeof( mark ) );
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < M; j++ ){
				if( n.map[i][j] && !mark[i][j] ){
					midmap = n;
					BFS2( i, j, n.map[i][j] );
					Node temp = midmap;
					temp.step += 1;
					temp = Handle( temp );
					q.push( temp );
				}
			}
		}
	}
	return -1;
}

int main(){
	while( scanf( "%d%d", &N, &M ) != EOF ){
		start.count = 0;
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < M; j++ ){
				cin >> start.map[i][j];
				if( start.map[i][j] != 0 ){
					start.count++;
				}
			}
		}
		int ans = BFS1();
		if( ans != -1 ){
			cout << ans << endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}