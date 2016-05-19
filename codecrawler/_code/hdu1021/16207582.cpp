#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>      
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    __int64 n;
    ios::sync_with_stdio(false);
    while(cin>>n){
        if(n%4==2)
            cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}