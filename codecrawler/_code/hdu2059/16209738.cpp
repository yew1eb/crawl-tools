/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-09 14:44
 # Filename: HDU2059 é¾åèµè·.cpp
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
#include <float.h>
#define MAX 110
using namespace std;

double dp[MAX];
int path[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int l,n,c,t;
  int vr,vt1,vt2;

  while(~scanf("%d%d%d%d",&l,&n,&c,&t))
  {
      scanf("%d%d%d",&vr,&vt1,&vt2);
      path[0]=0;
      dp[0]=0.0;
      for(int i=1;i<=n;++i)
          scanf("%d",&path[i]);
      path[n+1]=l;

      for(int i=1;i<=n+1;++i)
      {
          dp[i]=DBL_MAX;
          for(int j=0;j<i;++j)
          {
              double len=1.0*(path[i]-path[j]);
              double temp=(len>=c)?((c*1.0)/vt1+(len-c)*1.0/vt2):((len*1.0)/vt1);
              if(j) 
          temp+=t;
              dp[i]=min(dp[i],dp[j]+temp);
          }
      }
      double rabit_time=(l*1.0)/vr;
      if(dp[n+1]>rabit_time)
          printf("Good job,rabbit!\n");
      else
          printf("What a pity rabbit!\n");
  }

  return 0;
}
