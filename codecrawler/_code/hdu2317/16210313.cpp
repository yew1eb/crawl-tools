#include<iostream>
using namespace std;

int main(){
    int n,r,e,c;
    cin>>n;
    while(n--){
        cin>>r>>e>>c;
        if(r>e-c){
            cout<<"do not advertise"<<endl;// äºäº
        }else if(r==e-c){
            cout<<"does not matter"<<endl;// æ æè°
        }else{
            cout<<"advertise"<<endl;// èµäº
        }
    }
    return 0;
}
