#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod;
struct Mar{
    ll mat[2][2];
};
Mar E={1,0,0,1},unit2={0,1,1,1};
ll my_pow(ll a,ll b){
    ll ans = 1;
    while(b){
        if (b%2)
            ans = (ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}
Mar mul(Mar a,Mar b){
    ll fumod(ll);
    Mar ans={0,0,0,0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k <2; ++k){
                ans.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%mod;
                ans.mat[i][j]%=mod;
        }
    return ans;
}
Mar pow2(Mar a,ll n){
    Mar ans = E;
    while(n){
        if (n%2)
            ans = mul(ans,a);
        n/=2;
        a=mul(a,a);
    }
    return ans;
}
ll fib(ll n){
    Mar uu={1,1,1,1};
    Mar p=pow2(unit2,n);
    p=mul(uu,p);
    return p.mat[0][0];
}
int main()
{
    ll T,a,b,n,p;
    cin>>T;
    while(T--){
        cin >> a >> b >> n >> p;
        mod = p;
        ll temp1=(my_pow(a,(p-1)/2)+1)%mod;
        ll temp2=(my_pow(b,(p-1)/2)+1)%mod;
        if (!temp1 || !temp2){cout << "0" << endl;continue;}
        --mod;
        ll fn=fib(n);
        ++mod;
        Mar unit={2,2*(a+b)%mod,1,1};
        Mar tmp1={0,-(a-b)*(a-b)%mod,1,2*(a+b)%mod};
        Mar p=pow2(tmp1,fn);
        p=mul(unit,p);
        ll pn=p.mat[0][0];
        ll ans = pn%mod*temp1%mod*temp2%mod;
        while(ans < 0)ans+=mod;
        cout << ans << endl;
    }
    return 0;
}
