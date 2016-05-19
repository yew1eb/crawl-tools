#include<iostream>
#include<cmath>

using namespace std;

int main(){
        int n,m;
        int d,b;
        while(cin>>n>>m && (n||m)){
                for(d=sqrt(2.0 *m); d>0;d--){
                        b=m-(d+d*d)/2;
                        if(b%d==0)
                        cout<<"["<<(b/d)+1<<","<<(b/d)+d<<"]"<<endl;
                }
                cout<<endl;
        }
        return 0;
}
