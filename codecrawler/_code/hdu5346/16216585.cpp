#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
#define MOD 258280327
LL power(LL x,LL k){
    LL res=1;
    while(k){
        if(k&1)res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}
LL dp[2100][2100];
int main(){
    LL n,x,y,T;scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&x,&y);
        LL dead=x*power(y,MOD-2)%MOD;//dead probability of an attack
        LL live=(MOD+1-dead)%MOD;//live probability of an attack
        dp[1][0]=1;
        for(int j=1;j<n;j++)dp[1][j]=0;
        for(int i=2;i<=n;i++){// i th peolivee
            dp[i][0]=0;
            LL tmp=1;
            for(int j=1;j<i;j++){// j times attacked
                //move = i th live (live^(j-1)) + i th dead (1-live^(j))
                dp[i][j]=dp[i-1][j-1]*tmp%MOD+dp[i-1][j]*(MOD+1-tmp*live%MOD)%MOD;
                tmp=tmp*live%MOD;
            }
        }
        for(int k=0;k<n;k++){
            LL tmp=1;
            LL ans=0;
            for(int i=1;i<=n;i++){
                if(i-1<k)tmp=tmp*live%MOD;
                ans=(ans+dp[i][k])%MOD;
            }
            // ans*live^(k)/n
            ans=ans*tmp%MOD*power(n,MOD-2)%MOD;
            printf("%lld%c",ans,k==n-1?'\n':' ');
        }
    }
    return 0;
}