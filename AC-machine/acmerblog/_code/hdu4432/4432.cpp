#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXP = 40000; 
int prime[MAXP] = {0},num_prime = 0; 
int isNotPrime[MAXP] = {1, 1}; 
int digit[MAXP];
int n,m;
/*void GetPrime()
{     
      for(int i = 2 ; i <  MAXP ; i ++){           
          if(! isNotPrime[i])             
               prime[num_prime ++]=i;         
          for(int j = 0 ; j < num_prime && i * prime[j] <  MAXP ; j ++)         
                  {             
                                isNotPrime[i * prime[j]] = 1;             
                                if( !(i % prime[j]))  break;         
                  }     
      } 
}*/
int   sqr(int x){ return x*x;}
int   GetSqrValue(int i,int m){
      int sum=0;
      while (i){
            sum+=sqr(i%m);
            i/=m;
      }
      return sum;
}

void  PrintBaseM(int ans,int m){
      int nPs=0;
      while (ans){
            digit[nPs++]=ans%m;
            ans/=m;
      }
      for (int i=nPs-1;i>=0;--i) 
      if (digit[i]<10)cout<<digit[i]; else cout<<char(digit[i]+55);
      cout<<endl;
}
int main()
{
    //GetPrime();
    while (cin>>n>>m){
          int ans=0;
          int N= int(sqrt(n*1.0));
          for (int i=1;i<=N;++i)
          if (!(n%i))
          {
              ans+=GetSqrValue(i,m);
              if (n/i != i)
              ans+=GetSqrValue(n/i,m);
          }
          PrintBaseM(ans,m);
    }
    return 0;
}