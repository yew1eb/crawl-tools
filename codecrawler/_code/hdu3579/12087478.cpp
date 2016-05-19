#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=100010;
ll ex_gcd(ll a, ll b, ll &x, ll &y){
    if(a==0 && b==0) return -1;
    if(b==0) {x=1; y=0; return a;}
    ll d = ex_gcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

inline ll ABS(ll x){
    return x<0?-x:x;
}
bool solve(ll &m0, ll &a0, ll m, ll a){
    ll y, x;
    ll g = ex_gcd(m0, m, x, y);
    if( ABS(a-a0)%g ) return false;
    x *= (a-a0)/g;
    x %= m/g;
    a0 = (x*m0 + a0);
    m0 *= m/g;
    a0 %= m0;
    if(a0 < 0) a0 += m0;
    return true;
}

ll mm[maxn], aa[maxn]; 
//Ä£ÊýÎªmm[i],ÓàÊýÎªaa[i],X % mm[i] = aa[i]
// X = a0 + m0*t (0<=a0<m0)
bool MLES(ll &m0, ll &a0, int n){
    bool flag = true;
    m0 = 1;
    a0 = 0;
    for(int i=0; i<n; ++i)
        if( !solve(m0, a0, mm[i], aa[i]) ){
            flag = false;
            break;
        }
    return flag;
}

int main(){
    int T, n;
    //freopen("in.txt","r",stdin);
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            scanf("%lld", &mm[i]);
        }
        for(int i=0; i<n; ++i){
            scanf("%lld", &aa[i]);
        }
        ll m0, a0;
        // 0<(x=a0+m0*t)<=n
        printf("Case %d: ", ca);
        if(!MLES(m0, a0, n) )
            printf("-1\n");
        else{
            if(a0==0) a0 = m0;
            printf("%lld\n", a0);
        }
    }
    return 0;
}













