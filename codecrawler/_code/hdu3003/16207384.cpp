/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-05 18:57
 # Filename: HDU3003 Pupu.cpp
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

const int kMAX=10010;
const double kEPS=10E-6;

// å¿«éå¹åæ¨¡
// å¿«éå¹åæ¨¡å°±æ¯å¨O(logn)åæ±åºa^n mod bçå¼ãç®æ³çåçæ¯(a*b) mod c=(a mod c)*(b mod c)mod c
long long exp_mod(const long long &base,const long long &exp,const long long &mod)
{
    if(exp==0ll) return 1ll%mod;
    if(exp==1ll) return base%mod;
    long long tmp=exp_mod(base,exp/2,mod);
    tmp=tmp*tmp%mod;
    if(exp&1) tmp=tmp*base%mod;//if n is odd;
    return tmp;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

    long long n;

  while(~scanf("%lld",&n) && n)
  {
        long long ans=0;
    if(n>1)
      ans=exp_mod(2,n-1,n)+1;
        printf("%lld\n",ans%n);
  }

  return 0;
}
