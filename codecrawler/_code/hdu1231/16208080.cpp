#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

int main(){
    int n,a,a0;
    while(cin>>n,n){
        cin>>a0;
        int first=a0,last=a0,Max=a0,temp=a0,x=a0;
        for(int i=1;i<n;++i){
            scanf("%d",&a);
            if(temp>=0){
                temp+=a;
                if(temp>Max)first=x,last=a,Max=temp;
            }
            else{
                temp=a;
                x=a;
                if(temp>Max)first=x,last=a,Max=temp;
            }
        }
        if(Max<0)Max=0,first=a0,last=a;
        cout<<Max<<' '<<first<<' '<<last<<endl;
    }
    return 0;
}