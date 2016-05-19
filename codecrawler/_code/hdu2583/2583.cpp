/*the number of n-permutations with k"<"symbol is F[n][k]
  find the turning
  F[i][0]=1,F[i][i-1]=1,i>j,i(n),j(k) 0<i<=100,0<=k<=100
  以1 3 2 5 4为例，如果我们要插入6,如何办，分<和>分析可知
  F[n+1][k] = F[n][k]*(k+1)+F[n][k-1]*(n-k+1)
  F[1][0]=F[2][0]=F[3][0]=F[4][0]=.....=F[n][0]=1;
  F[1][0]=F[2][1]=F[3][2]...............F[n][n-1]=1;
  转移式:
  F[n][k] = F[n-1][k]*(k+1)+F[n-1][k-1]*(n-k)*/

#include<iostream>
using namespace std;

int F[105][105];
int n,k;

void DP()
{
	int i,j;
	for(i=1; i<=100; ++i)
		F[i][0] = F[i][i-1] = 1;
	for(i=1; i<=100; ++i)
	{
		for(j=0; j<i-1; ++j)
		{
			F[i][j] = (F[i-1][j]*(j+1)+F[i-1][j-1]*(i-j)) % 2009;
		}
	}
}
int main()
{
	DP();
	while(cin >> n >> k)
	{
		cout << F[n][k] << endl;
	}
	return 0;
}