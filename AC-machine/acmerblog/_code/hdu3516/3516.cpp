#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int M=1100;

const int INF=1000000000;

int dp[M][M];
int K[M][M];

int x[M];
int y[M];


int get_w(int i,int j,int k)
{
 return x[k+1]-y[j]+y[k]-x[i];
}


int main()
{
 int n;
 while(scanf("%d",&n)==1)
 {
 for(int i=1;i<=n;i++)
 scanf("%d%d",&x[i],&y[i]);
 for(int i=1;i<=n;i++)
 for(int j=i;j<=n;j++)
 dp[i][j]=INF;
 for(int i=1;i<=n;i++)
 dp[i][i]=0;
 memset(K,-1,sizeof(K));
 for(int j=1;j<=n;j++)
 for(int i=j-1;i>=1;i--)
 {

 int low=K[i][j-1];
 int high=K[i+1][j];
 if(low==-1)
 low=i;
 if(high==-1)
 high=j-1;
 for(int k=low;k<=high;k++)
 {
 int w=get_w(i,j,k);
 //cout<<w<<endl;
 if(dp[i][j]>dp[i][k]+dp[k+1][j]+w)
 {
 dp[i][j]=dp[i][k]+dp[k+1][j]+w;
 K[i][j]=k;
 }

 }

 }
 /*for(int i=1;i<=n;i++)
 {
 for(int j=1;j<=n;j++)
 {
 cout<<K[i][j]<<" ";

 }
 cout<<endl;
 }*/
 printf("%d\n",dp[1][n]);
 //cout<<dp[1][n]<<endl;

 }
 return 0;

}