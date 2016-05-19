#include<iostream>
using namespace std;
int main(){
    int t,n,a[30],b[30],i,j,temp1,temp2,k,s;
    cin>>t;
    while(t--){
        cin>>n;
        s=n;
        for(i=0;i<s;i++)
            cin>>a[i]>>b[i];
        for(i=0;i<s;i++){
            for(j=0;j<s-1;j++){
                if(a[j]>a[j+1]){
                    temp1=a[j];a[j]=a[j+1];a[j+1]=temp1;
                    temp2=b[j];b[j]=b[j+1];b[j+1]=temp2;
                }
            }
        }
        for(i=0;i<s;i++){
            for(j=0;j<b[i];j++){
                cout<<">+";
                for(k=0;k<a[i]-2;k++)
                    cout<<"-";
                cout<<"+>"<<endl;;
            }
            cout<<endl;                
        }            
    }
    return 0;
}