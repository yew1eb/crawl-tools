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

const int MAX=10000+10;
const int mod=2008;

int pow(int a,int b){
    int sum=1;
    while(b){
        if(b&1)sum=(sum*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return sum;
}

int get(int n){
    if(n == 1)return 2;//è¿åæ¬æºä¸²ä¸ªæ°
    int sum=0;
    for(int i=2;i*i<=n;++i){
        if(n%i == 0){
            sum=(sum+get(i))%mod;
            if(n/i != i)sum=(sum+get(n/i))%mod;
        }
    }
    return (pow(2,n)-sum-2+mod)%mod;
}

int main(){
    int n;
    while(cin>>n){
        cout<<get(n)<<endl;
    }
    return 0;
}