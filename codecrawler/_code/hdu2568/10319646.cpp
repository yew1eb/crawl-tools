#include<iostream>
using namespace std;
int main( void ){
    int t,n,count;
    cin>>t;
    while(t--){
     cin>>n;
     count=0;
     while(n) {
         if(n%2){     n--;     count++;}
         else      n=n/2;
         
     }
     cout<<count<<endl;
    }
   return 0;
}