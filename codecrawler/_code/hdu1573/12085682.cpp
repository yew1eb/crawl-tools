#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll ex_gcd(ll a, ll b, ll &x, ll &y){
    if(a==0 && b==0) return -1;
    if(b==0) {x=1; y=0; return a;}
    ll d = ex_gcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

bool solve(int &m0, int &a0, int m, int a){
    ll y, x;
    ll g = ex_gcd(m0, m, x, y);
    if( abs(a-a0)%g ) return false;
    x *= (a-a0)/g;
    x %= m/g;
    a0 = (x*m0 + a0);
    m0 *= m/g;
    a0 %= m0;
    if(a0 < 0) a0 += m0;
    return true;
}

int mm[11], aa[11]; 
//Ä£ÊýÎªmm[i],ÓàÊýÎªaa[i],X % mm[i] = aa[i]
// X = a0 + m0*t (0<=a0<m0)
bool MLES(int &m0, int &a0, int n){
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
    int T, n, m;
    //freopen("in.txt","r",stdin);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; ++i) scanf("%d", &mm[i]);
        for(int i=0; i<m; ++i) scanf("%d", &aa[i]);
        int m0, a0;
        // 0< x=a0+m0*t <= n
        if( !MLES(m0, a0, m) || n<a0)
            printf("0\n");
        else 
            printf("%d\n", (n-a0)/m0+1-(a0==0?1:0) );
    }
    return 0;
}
