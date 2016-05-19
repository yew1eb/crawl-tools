#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LL long long
#define eps 1e-7
#define MOD 1000
using namespace std;
int stir2[2005][2005]={1};
int bell[2005];
int main(){
    for(int i=1;i<=2000;i++){
        stir2[i][0]=0;
        stir2[i][i]=1;
        for(int j=1;j<i;j++)
            stir2[i][j]=(stir2[i-1][j-1]+j*stir2[i-1][j])%MOD;
    }
    for(int i=1;i<=2000;i++){
        bell[i]=0;
        for(int j=0;j<=i;j++)
            bell[i]=(bell[i]+stir2[i][j])%MOD;
    }
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<bell[n]<<endl;
    }
    return 0;
}