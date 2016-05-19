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
    __int64 n,m;
    int i;
    while(cin>>n>>m,n+m){
        for(i=1;i<=n;++i){
            if(m%2)break;
            m=m/2;
        }
        cout<<i<<endl;
    }
    return 0;
} 