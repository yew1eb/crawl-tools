#include<iostream>

using namespace std;

int main(){
    long  n,m,i;
    while(cin>>n>>m ){
        if(n==0 && m==0) break;
        bool s=false;
        for(i=-10000;i<10001;i++){
            long k=n-i;
            if(k*i==m){
                s=true;
                break;
            }    
        }
        if(s==true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}