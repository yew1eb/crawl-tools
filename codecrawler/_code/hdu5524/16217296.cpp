#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL f[66];
int main()
{
    f[0]=0;
    LL add=1;
    for(int i=1;i<65;i++){
        f[i]=f[i-1]+add;
        add<<=1;
    }
    LL n;
    while(cin>>n){
        LL nn=n;
        LL cnt=0;
        while(nn){
            nn>>=1;
            cnt++;
        }
        if(f[cnt]==n){
            cout<<cnt<<endl;
            continue;
        }

        LL ans=cnt-2;
        LL l=n-f[cnt-1],r=f[cnt]-n;
        if(l>=r){
            ans++;

        }
         while(!(l&1) && cnt--){
            l >>= 1;
        }

         // cout<<f[cnt]<<"..."<<ans<<"..."<<cnt<<endl;
        cout << ans + cnt - 1 << endl;
    }
    return 0;
}