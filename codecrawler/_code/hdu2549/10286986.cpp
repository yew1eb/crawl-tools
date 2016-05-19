#include<iostream>
#include<string>
using namespace std ;
int main( void )
{
    int t,n,i;
    string a;
    cin>>t ;
    while(t--)
    {
         cin>>a>>n ;
         for( i=0 ; a[i]!='.' ; i++ );
         cout<<(n+i>=a.size()?'0':a[n+i])<<endl;
    }
    return 0 ;
}
