/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-08 18:24
 # Filename: HDU2577 How to Type.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 100010
using namespace std;

int dp[2][MAX]; //dp[0]å¤§åä¸éå®, dp[1]å¤§åéå®

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  char str[120];
  scanf("%d",&n);
  getchar();

  while(n--)
  {
    gets(str);
    int len=strlen(str);
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    for(int i=0;i<len;++i)
      if(str[i]<='Z')
      {
        dp[0][i+1] = min(dp[0][i]+2,dp[1][i]+2);
        dp[1][i+1] = min(dp[0][i]+2,dp[1][i]+1);
      }
      else
      {
        dp[0][i+1] = min(dp[0][i]+1,dp[1][i]+2);
        dp[1][i+1] = min(dp[0][i]+2,dp[1][i]+2);
      }
      printf("%d\n",min(dp[0][len],dp[1][len]+1));
  }

  return 0;
}
