/*

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<math.h>
using namespace std;
typedef long long int64;
//typedef __int64 int64;
typedef pair<int64,int64> PII;
#define MP(a,b) make_pair((a),(b)) 
const int maxn = 18;
const int inf = 0x7fffffff;
const double pi=acos(-1.0);
const double eps = 1e-8;
char mat[ maxn ][ maxn ];
bool flag;
const int dx[]={1,-1,0,0,-1,-1,1,1};
const int dy[]={0,0,1,-1,-1,1,-1,1};

bool in( int x,int y ){
	if( x>=0&&x<15&&y>=0&&y<15 )
		return true;
	else
		return false;
}

bool Judge( int x,int y,char xx ){
	for( int i=0;i<8;i++ ){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if( in(tx,ty)==true&&mat[tx][ty]==xx )
			return true;
	}
	return false;
}

int bfs( int x,int y,char xx ){
	
	int tx = x+1;
	int ty = y;
	int cnt = 0;
	while( tx<15 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx++;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	tx = x-1;
	while( tx>=0 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx--;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	if( cnt>=4 ) return 5;
	//row to "5"
	tx = x;
	ty = y+1;
	cnt = 0;
	while( ty<15 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			ty++;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	ty = y-1;
	while( ty>=0 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			ty--;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	if( cnt>=4 ) return 5;
	// col to "5"
	tx = x+1;
	ty = y+1;
	cnt = 0;
	while( tx<15&&ty<15 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx++;
			ty++;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	tx = x-1;
	ty = y-1;
	while( tx>=0&&ty>=0 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx--;
			ty--;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	if( cnt>=4 ) return 5;
	//right up to "5"
	tx = x-1;
	ty = y+1;
	cnt = 0;
	while( tx>=0&&ty<15 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx--;
			ty++;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	tx = x+1;
	ty = y-1;
	while( tx<15&&ty>=0 ){
		if( mat[tx][ty]==xx ){
			cnt++;
			tx++;
			ty--;
			if( cnt>=4 ) break;
		}
		else 
			break;
	}
	if( cnt>=4 ) return 5;
	//left up to "5"
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int cnt1 = 0;
		int cnt2 = 0;
		for( int i=0;i<15;i++ ){
			scanf("%s",mat[i]);
			for( int j=0;j<15;j++ ){
				if( mat[i][j]=='W' ) cnt1++;
				if( mat[i][j]=='B' ) cnt2++;
			}
		}
		char xx ;
		if( cnt1==cnt2 ) xx = 'B';
		else xx = 'W';
		flag = false;
		for( int i=0;i<15;i++ ){
			for( int j=0;j<15;j++ ){
				if( mat[i][j]=='.'&&Judge( i,j,xx )==true ){//i,j周围有 xx
					if( bfs( i,j,xx )>=5 ){
						flag = true;
						break;
					}
				}
			}
			if( flag==true ) break;
		}
		if( flag ) puts("YES");
		else puts("NO");
	}
	return 0;
}