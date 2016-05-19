#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int N = 3005;
typedef long long LL;

LL sum[N][N] ,f[N];
bool a[N][N];

int que[N] , up[2][N];

inline LL get( int lx,int ly,int rx,int ry ){
	lx--;ly--;
	//cout<<sum[rx][ry]<<" "<<sum[lx][ly]<<" "<<sum[rx][ly]<<" "<<sum[lx][ry]<<endl;
	return sum[rx][ry] + sum[lx][ly] - sum[rx][ly]-sum[lx][ry];
}

int main() {
	int test, i , j , n , m , k , tmp;
	scanf("%d",&test);
	while( test-- ) {
		scanf("%d%d%d",&n,&m,&k);
		memset( sum[0] , 0 ,sizeof( sum[0] ));
		for( i = 1; i <= n ;i++) {
			sum[i][0] = 0 ;
			LL add = 0;
			for( j = 1; j <= m;j++ ) {
				scanf("%d",&tmp);
				a[i][j] = ( tmp >= k );
				add += tmp;
				sum[i][j] = sum[i-1][j] + add;
				//cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
			}
		}
		memset( up , 0 ,sizeof( up ));
		LL ans = 0;
		for( i = 1; i <= n;i++ ) {
			int cur = i%2;
			int head = 0 ,tail = 0;
			memset( f , 0 ,sizeof( f ));
			if( a[i][1] ) {
				up[cur][1] = up[1-cur][1] + 1;
				f[1] = get( i - up[cur][1] + 1 ,1,i,1);
			} else {
				up[cur][1] = 0;
				f[1] = 0;
			}
			que[tail++] = 1;
			ans = max( ans , f[1] );
			for( j = 2; j <= m;j++) {
				if( a[i][j] ) up[cur][j] = up[1-cur][j] + 1;
				else up[cur][j] = 0;
				
				while( head < tail ) {
					int idx = que[tail-1];
					if( up[cur][idx] >= up[cur][j] ) tail--;
					else break;
				}
				int leftidx = 0;
				if( head < tail ) leftidx = que[tail-1];
				
				que[tail++] = j;
				f[j] = f[leftidx] + get( i - up[cur][j]+1 ,leftidx+1, i , j ); 	
				//cout<<i<<" j="<<j<<" left="<<leftidx<<" f[j]="<<f[j]<<endl;
				ans = max( ans , f[j] );
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*

100
2 3 2
2 3 4
2 2 1

2 3 2
1 1 1
1 1 1

2 3 2
1 1 1
2 2 2

2 3 2
1 3 1
2 1 2 

3 4 2
2 3 2 1
3 1 2 3
4 4 4 4

3 2 2
1 4
2 5 
3 6

3 2 2
2 3
1 3
2 3

3 4 2
2 2 1 1
1 3 2 2
3 4 2 2

2 3 2
2 2 2
2 2 1

2 4 2
2 2 1 3
1 2 1 5

*/