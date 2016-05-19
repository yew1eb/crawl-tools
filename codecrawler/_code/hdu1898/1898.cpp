#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    long t;
    cin>>n;
    while(n--){
        cin>>a>>b>>t;
        if(t%a>t%b)
            cout<<"Xiangsanzi!"<<endl;
        else if(t%a<t%b)
            cout<<"Sempr!"<<endl;
        else
            cout<<"Both!"<<endl;
    }
    return 0;
}