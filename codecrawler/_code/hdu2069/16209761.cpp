/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
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
using namespace std;

const int kMAX=2500;
const double kEPS=10E-6;

long long dp[101][kMAX];    //dp[x][y]è¡¨ç¤ºçæ¯å¨ç¨äºxæç¡¬å¸çæåµä¸ï¼å°è¾¾yå¼çè·¯å¾æ°

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;

    int value[]={0,1,5,10,25,50};
    memset(dp,0,sizeof(dp));
    dp[0][0]=1ll;

    for (int i=1;i<=5;++i)    //ç¨çç¡¬å¸
    {
        for (int j=1;j<=100;++j)    //ç¡¬å¸æ°ç®
        {
            for (int k=value[i];k<kMAX;++k)
            {
                dp[j][k]+=dp[j-1][k-value[i]];
            }
        }
    }
  while(~scanf("%d",&n))
  {
      long long ans=0ll;
      for(int j=0;j<=100;++j)
          ans+=dp[j][n];
        printf("%lld\n",ans);
  }

  return 0;
}
