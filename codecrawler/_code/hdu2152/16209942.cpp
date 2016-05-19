/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-04 19:10
 # Filename: HDU2152 Fruit.cpp
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

const int kMAX=100100;
const double kEPS=10E-6;

int ans[kMAX],tans[kMAX];
int a[kMAX],b[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;

  while(~scanf("%d%d",&n,&m) )
  {
    for(int i=0;i<n;++i)
      scanf("%d%d",&a[i],&b[i]);

    memset(ans,0,sizeof(ans));
    memset(tans,0,sizeof(tans));
    ans[0]=1;

    for(int i=0;i<n;++i)
    {
      for(int j=0;j<=m;++j)
        if(ans[j])
        {
          for(int k=a[i];k+j<=m && k<=b[i];++k)
            tans[k+j]+=ans[j];

        }
        memcpy(ans,tans,sizeof(ans));
        memset(tans,0,sizeof(tans));
    }
    printf("%d\n",ans[m]);

  }

  return 0;
}
