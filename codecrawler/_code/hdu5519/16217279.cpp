#include <bits/stdc++.h>
#include <algorithm>
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i < y;-- i)

using namespace std;

typedef vector <int> VT;

const int maxn = 15010;
const int maxm = 30030;
const int Mod = 1e9+7;
const int MSK = 1<<5;

int n,a[5];

void gcd(LL a,LL b,LL& d,LL& x,LL& y){
    if(!b)  {d = a;x = 1;y = 0;}
    else{gcd(b,a%b,d,y,x);y -= x*(a/b);}
}

LL Inv(LL a,LL n){
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d == 1 ? (x+n)%n : -1;
}

LL fac[maxn],inv[maxn],cnt[MSK];

void init(){
    fac[0] = 1; inv[0] = 1;
    FOR(i,1,maxn){
        fac[i] = i*fac[i-1]%Mod;
        LL p = Inv(i,Mod);
        inv[i] = inv[i-1]*p%Mod;
    }
    FOR(i,0,MSK)    cnt[i] = __builtin_popcount(i);
}

LL dp[maxn][MSK];
LL Pow;

LL C(LL p,LL q){
    return fac[p]*inv[q]%Mod*inv[p-q]%Mod;
}

LL quickpow(LL a,LL n,LL m){
    LL ans=1;
    while(n){
        if(n&1) ans = (ans*a)%m;
        a = (a*a)%m;
        n>>=1;
    }
    return ans;
}

void work(){
    LL ans = 0;
    FOR(p,1,5){
        if(!a[p])   continue;
        ans += Pow;
        ans %= Mod;
        -- a[p];
        -- n;
        FOR(j,1,6){
            memset(dp,0,sizeof(dp));
            dp[0][0] = 1;
            FOR(i,1,n+1){
                FOR(msk,0,MSK){
                    if(cnt[msk] <= j){
                        dp[i][msk] = dp[i-1][msk]*(5-j+cnt[msk])%Mod;
                        FOR(k,0,5){
                            if((msk & (1<<k)) && a[k] <= i-1){
                                dp[i][msk] += dp[i-a[k]-1][msk^(1<<k)]*C(i-1,a[k]);
                                dp[i][msk] %= Mod;
                            }
                        }
                    }
                }
            }
            FOR(msk,0,MSK){
                if(cnt[msk] == j){
                    if(j % 2){
                        ans -= dp[n][msk];
                        ans = (ans + Mod)%Mod;
                    }
                    else{
                        ans += dp[n][msk];
                        ans %= Mod;
                    }
                }
            }
        }
        ++ n;
        ++ a[p];
    }
    printf("%I64d\n",ans);
}


int main()
{
    //freopen("test.in","r",stdin);
    init();
    int T,tCase = 0;    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++tCase);
        scanf("%d",&n);
        FOR(i,0,5)  scanf("%d",&a[i]);
        Pow = quickpow(5,n-1,Mod);
        work();
    }
    return 0;
}