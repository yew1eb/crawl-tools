#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i = 0;i < (n);i++)
typedef long long ll;
ll f[25][3];
void init()
{
    f[0][0] = 1;
    for(int i = 1;i <= 20;i++){
        f[i][0] = f[i-1][0] * 10 - f[i-1][1];
        f[i][1] = f[i-1][0];    // start with 9
        f[i][2] = f[i-1][1] + f[i-1][2]*10;  // contian 49
    }
}
ll query(ll n)
{
    int d[25]={},tot = 0;
    while(n){
        d[++tot] = n % 10;
        n /= 10;
    }
    ll ans = 0,flag = 1;
    for(int i = tot;i > 0;i--){
        ans += f[i-1][2]*d[i];
        if(flag && d[i] > 4) ans += f[i-1][1];
        if(!flag) ans += f[i-1][0]*d[i];
        if(d[i+1] == 4 && d[i] == 9) flag = 0;
    }
    return ans;
}
int main()
{
    init();
    int T;
    cin>>T;
    while(T--){
        ll n;
        scanf("%I64d",&n);
        printf("%I64d\n",query(n+1));
    }
}