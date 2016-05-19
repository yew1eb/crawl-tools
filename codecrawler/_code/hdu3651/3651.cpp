#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;
int dp[110][11][11],b[110],len,ans;
char n[110];
void Init()
{
 len=strlen(n);
 for(int i=1;i<=len;i++)
 {
 b[i]=n[i-1]-'0';
 if(b[i]==0)
 b[i]=10;
 }
 memset(dp,-1,sizeof(dp));
 dp[0][5][6]=0;
 ans=9999999;
}
int ABS(int x,int y)
{
 if(x-y>0)
 return x-y;
 else
 return y-x;
}
void Solve()
{

 for(int i=0;i<len;i++)
 {
 for(int l=1;l<=10;l++)
 {
 for(int r=l+1;r<=10;r++)
 {
 if(dp[i][l][r]>=0)
 {
 for(int R=b[i+1]+1;R<=10;R++)
 {
 if(dp[i+1][b[i+1]][R]<0 || dp[i+1][b[i+1]][R]>dp[i][l][r]+max(ABS(b[i+1],l)+1,ABS(R,r)))
 {
 dp[i+1][b[i+1]][R]=dp[i][l][r]+max(ABS(b[i+1],l)+1,ABS(R,r));
 /* cout<<b[i+1]<<" "<<i<<" "<<l<<" "<<r<<" "<<R<<endl;
 if(b[i+1]==5 && i==0 && l==5 && r==6 && R==7)
 {
 cout<<ABS(b[i+1],l)+1<<" "<<ABS(R,r)<<endl;
 }*/
 if(i==len-1)
 {
 ans=min(ans,dp[i+1][b[i+1]][R]);
 }
 }
 }
 for(int L=b[i+1]-1;L>=1;L--)
 {
 if(dp[i+1][L][b[i+1]]<0 || dp[i+1][L][b[i+1]]>dp[i][l][r]+max(ABS(L,l),ABS(b[i+1],r)+1))
 {
 dp[i+1][L][b[i+1]]=dp[i][l][r]+max(ABS(L,l),ABS(b[i+1],r)+1);
 if(i==len-1)
 {
 ans=min(ans,dp[i+1][L][b[i+1]]);
 }
 }
 }
 }
 }
 }
 }
 // cout<<dp[1][5][7]<<endl;
}
int main()
{
 while(scanf("%s",&n)!=EOF)
 {
 Init();
 Solve();
 printf("%d\n",ans);
 }
 return 0;
}