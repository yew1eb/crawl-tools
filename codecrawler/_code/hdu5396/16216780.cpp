#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 105;
ll num[maxn], b[maxn];
char c[maxn];
ll dp[maxn][maxn];

ll sum(ll a, ll b, char ch)
{
    if(ch == '+') {
        return (a+b + mod)%mod;
    }
    if(ch == '-') {
        return (a-b + mod)%mod;
    }
    if(ch == '*') {
        return (a*b + mod)%mod;
    }
}
ll in[maxn];

ll inv(ll a)
{
    ll res=1;
    ll n=mod-2;
    while(n)
    {
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void init()
{
    b[0] = 1;
    in[0] = 1;
    for(int i = 1;i < maxn; ++i) {
        b[i] = (b[i-1]*i) % mod;
        in[i] = inv(b[i]);
        //cout<<in[i]<<endl;
    }
}

int main()
{
    //freopen("in", "r", stdin);
    int n;
    init();

    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%I64d", &num[i]);
        }
        scanf("%s", c+1);

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i) dp[i][i] = (num[i] + mod)%mod;
        ll s1, s2, s;

        for(int i = 0; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                for(int k = i; k >= j+1; --k) {

                    if(c[k] == '*') {
                        s1 = dp[j][k-1];
                        s2 = dp[k][i];
                    }
                    else {
                        s1 = (dp[j][k-1]*b[i-k] + mod) % mod;
                        s2 = (dp[k][i]*b[k-j-1] + mod) % mod;
                    }

                    //s = (sum(s1, s2, c[k]) * (b[i-j-1]/ (b[i-k]*b[k-j-1]) ) + mod) % mod;
                    s = (sum(s1, s2, c[k]) * (b[i-j-1]* in[i-k] % mod * in[k-j-1] % mod ) + mod) % mod;
                    //printf("(%d,%d)%I64d %c (%d,%d)%I64d\n", j, k-1, s1, c[k], k, i, s2);

                    dp[j][i] = (dp[j][i] + s + mod) % mod;
                }
                 //printf("**********************(%d, %d) = %I64d\n", j, i, dp[j][i]);
            }
        }
        printf("%I64d\n", dp[0][n-1] % mod);
    }
    return 0;
}