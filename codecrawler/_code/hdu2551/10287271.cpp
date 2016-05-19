#include<iostream>
using namespace std ;
int main( void )
{
    int t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=0; ;i++){
            sum+=i*i*i ;
            if(sum>=n) { cout<<i<<endl; break ; }
        }
    }
  return 0 ;
}