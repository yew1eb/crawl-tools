#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1e6+10;

#define ll unsigned int 

ll N, L1, R1, a, b, c, d;
ll l[10000010];
ll r[10000010];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>L1>>R1>>a>>b>>c>>d;
        l[1]=L1;
        r[1]=R1;
        
        for(int i=2;i<=N;i++){
            l[i]=l[i-1]*a+b;
            r[i]=r[i-1]*c+d;
        }
        
        ll minR=4294967295u;
        for(int i=1;i<=N;i++){
            if(l[i]>r[i]){
                swap(l[i],r[i]);
            }
            if(r[i]<minR){
                minR=r[i];
            }
        }
        
        ll minR2=4294967295u;
        bool ok=0;
        for(int i=1;i<=N;i++){
            if(l[i]>minR){
                ok=1;
                if(r[i]<minR2){
                    minR2=r[i];
                }
            }
        }
        
        if(ok){
            ok=0;
            for(int i=1;i<=N;i++){
                if(l[i]>minR2){
                    ok=1;
                    break;
                }
            }
            if(ok){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}