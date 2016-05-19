// hdu 1817 poj 1286
// by utoppia
// polya

#include<cstdio>
typedef long long ll;
ll pow(ll a,int n) {
    ll ret = 1ll;
    while(n--) ret *= a;
    return ret;
}
int gcd(int a,int b) {
    return b==0 ? a : gcd(b,a%b);
}
int main() {
    int n;
    ll ans;
    while(scanf("%d",&n),n>=0){
        if(n==0) {printf("0\n");continue;}
        ans = 0;
        for(int i=1;i<=n;i++) ans += pow(3ll,gcd(i,n));
        if(n&1) ans += pow(3ll,n/2 + 1)*n;
        else ans += (pow(3ll,n/2+1)*n/2 + pow(3ll,n/2)*n/2);
        ans /= (n*2);
        printf("%I64d\n",ans);
    }
    return 0;
}
