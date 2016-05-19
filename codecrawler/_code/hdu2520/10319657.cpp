#include<iostream>
using namespace std;
int main( void )
{
  int n,t;
  cin>>t;
  while(t--)
  {
      cin>>n;
     cout<<(n*n%10000)<<endl;
  }
  return 0;
}