#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;
int dp[30][30][30];

int w(int a,int b,int c)
{
  if(a<=0||b<=0||c<=0)return 1;
  if(a>20||b>20||c>20)return w(20,20,20);
  if(dp[a][b][c]>0)return dp[a][b][c];
  if(a<b&&b<c)
  {
   dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
  }
  else
  {
   dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
  }
  return dp[a][b][c];
}

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
      if(a==-1&&b==-1&&c==-1)break;
      memset(dp,0,sizeof(dp));
      printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    return 0;
}
