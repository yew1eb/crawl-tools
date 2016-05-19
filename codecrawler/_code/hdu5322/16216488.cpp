#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
#define MOD 998244353
#define maxn 100000
LL dp[maxn+10];
LL jie[maxn+10];
LL inv[maxn+10];
LL power(LL x,LL k){
    LL res=1;
    while(k){
        if(k&1)res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}
void init(){
    jie[0]=jie[1]=1;
    inv[0]=inv[1]=1;
    for(int i=2;i<=maxn;i++){
        jie[i]=i*jie[i-1]%MOD;
        inv[i]=power(jie[i],MOD-2);
    }
}
void solve(){
    init();
    dp[0]=0;
    dp[1]=1;
    LL a=2,b=1,c=1;//ä»0å¼å§
    for(LL i=2;i<=maxn;i++){//iè¦LLï¼å¦åi*iä¼ç
        dp[i]=jie[i-1]*(i*i%MOD*a%MOD-2*i*b%MOD+c%MOD+MOD)%MOD;
        a=(a+dp[i]*inv[i]%MOD)%MOD;
        b=(b+i*dp[i]%MOD*inv[i]%MOD)%MOD;
        c=(c+i*i%MOD*dp[i]%MOD*inv[i]%MOD)%MOD;
    }
}
int main(){
    solve();
    int n;
    while(~scanf("%d",&n))
        printf("%lld\n",dp[n]);
    return 0;
}