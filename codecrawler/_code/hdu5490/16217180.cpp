#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
#define maxn 10007
using namespace std;
#define mod 1000000007
int inv[maxn];
//æ±éå
int pow(int a,int n){
    int ans = 1;
    while(n){
        if(n&1) ans= (ll)ans*a%mod;
        a =(ll)a*a%mod;
        n /= 2;
    }
    return ans;
}
//åå§åï¼çº¿æ§æ±éå
void init(){
    inv[1] = inv[0] = 1;
    for(int i = 2;i < maxn; i++)
        inv[i] = -(ll)mod/i*inv[mod%i]%mod+mod;
}

int com[maxn];
int main(){
    init();
    int t,tt=1,b,q,a,d,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&b,&q,&a,&d,&n,&m);
        a %= mod, q %= mod, d %= mod, b %= mod;
        int invq = pow(q-1,mod-2);
        com[n] = 1;
        for(int i = n-1;i >= 1; i--){
            com[i] = (com[i+1]+(ll)com[i+1]*(m-1)%mod*inv[n-i])%mod;
        }

        int ans = 0;
        for(int i = 1;i <= n; i++){
            //ç­æ¯é¡¹
            b = (ll)b*invq%mod;
            ans = (ans + (ll)com[i] * (a - b) ) % mod;
            //ç­å·®é¡¹
            a += d;
            if(a >= mod) a -= mod;
            if(ans < 0) ans += mod;
            b = (ll)b*q%mod;
        }
        ans = (ans + (ll)b*pow(q,m-1))%mod;
        ans = (ans + mod)%mod;
        printf("Case #%d: %d\n",tt++,ans);
    }
    return 0;
}
