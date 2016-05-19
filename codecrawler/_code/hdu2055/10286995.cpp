#include<iostream>
using namespace std;
int main(){
    int b,t;
    char a;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>=65&&a<=90)    a-=64;
       else  a=-(a-96);
       cout<<a+b<<endl;
    }
    return 0;
}
