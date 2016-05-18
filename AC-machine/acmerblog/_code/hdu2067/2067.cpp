#include <iostream>
using namespace std;
#define N 36
__int64 chessboard[N][N];

void init(){
	int i,j;
	memset(chessboard,0,sizeof(chessboard));
	for (i=0;i<N;i++)
		chessboard[i][0]=1;
	for (i=1;i<N;i++)
		for (j=1;j<=i;j++)
			chessboard[i][j]=chessboard[i-1][j]+chessboard[i][j-1];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("2067in.txt","r",stdin);
#endif
	int n,ce=0;
	init();
	while (scanf("%d",&n)!=EOF){
		if(n==-1)
			break;
		ce++;
		printf("%d %d %I64d\n",ce,n,2*chessboard[n][n]);
	}
	return 0;
}