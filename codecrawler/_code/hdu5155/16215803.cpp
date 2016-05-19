#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
using namespace std;


#define ll long long
const ll mod=1e9+7;

ll dp[55][55];
ll cnk[55][55];
ll p2k[55];

int main(){
    //è®¡ç®2çå¹ 
    p2k[0]=1;
    for(int i=1;i<=50;i++){
        p2k[i]=p2k[i-1]<<1;
        p2k[i]%=mod;
    }
    
    //è®¡ç®ç»åæ°C(n,k) 
    for(int i=1;i<=50;i++){
        cnk[i][0]=1;
        cnk[i][1]=i;
        for(int j=1;j<=i/2;j++){
            cnk[i][j]=cnk[i-1][j-1]+cnk[i-1][j];
            cnk[i][j]%=mod;
        }
        for(int j=i/2+1;j<=i;j++){
            cnk[i][j]=cnk[i][i-j];
            cnk[i][j]%=mod;
        }
    }
    
    //dp 
    for(int i=1;i<=50;i++)dp[i][1]=1;
    for(int i=2;i<=50;i++){
        for(int j=2;j<=i;j++){        //è®¡ç®dp[i][j]
            for(int k=1;k<=i;k++){    //åj-1åä¸­ækè¡æä¸è¥¿ 
                //j-1åkè¡æä¸è¥¿çç­æ¡æ¯dp[max(k,j-1)][min(k,j-1)]
                //iè¡ä¸­kè¡æ¾ä¸è¥¿æC(i,k)ç§æåµ
                //æåä¸åä¸­ï¼i-kè¡æ¯ä¸å®æç å®çï¼å¦åå°±ä¸æç«äº
                //ä¹åå·²ç»æç å®çè¡å¯ä»¥ä»»æç»åï¼æåµæ°æ¯2^k(æ³¨æk==içç¹æ®æåµ) 
                if(k==i) dp[i][j]+=((dp[max(k,j-1)][min(k,j-1)]*cnk[i][k])%mod)*(p2k[k]-1);
                else dp[i][j]+=((dp[max(k,j-1)][min(k,j-1)]*cnk[i][k])%mod)*p2k[k];
                dp[i][j]%=mod;
            }
        }
    }
    int n,m;
    while(cin>>n>>m){
        if(n<m)swap(n,m);
        if(m==0){
            cout<<1<<endl;
            continue;
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}