/*********************************************
    Problem : HDU 2232
    Author  : NMfloat
    InkTime (c) NM . All Rights Reserved .
********************************************/

#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define rep(i,a,b)  for(int i = a ; i <= b ; i ++)
#define rrep(i,a,b) for(int i = b ; i >= a ; i --)
#define repE(p,u) for(Edge * p = G[u].first ; p ; p = p -> next)
#define cls(a,x)   memset(a,x,sizeof(a))

using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
//const int MAXN = 1e5;
const int MAXE = 2e5;

typedef long long LL;

int T,n,m,k;

const int MAXN = 5;//ç©éµçæå¤§é¿åº¦;
const int Mod = 9937;
int N = 4;//ç©éµçå®éé¿åº¦;

class Matrix {  
public:  
    int M[MAXN][MAXN];
    Matrix(){memset(M,0,sizeof(M));}  
    void init() {  //å°Mèµå¼ä¸ºåä½ç©éµ;
        rep(i,1,N) M[i][i]  = 1;  
    }  
    Matrix operator + (const Matrix B) const {
        Matrix ans;
        rep(i,1,N) rep(j,1,N) ans.M[i][j] = (M[i][j] + B.M[i][j]) % Mod;
        return ans;
    }
    Matrix operator * (const Matrix B) const {  
        Matrix ans;
        rep(i,1,N) rep(j,1,N) rep(k,1,N) ans.M[i][j] = (ans.M[i][j] + M[i][k] * B.M[k][j] ) % Mod;   
        //ans = ans + * this;
        return ans;  
    }

    Matrix operator ^ (const int n) const {  
        Matrix ans; int k = n ;
        ans.init(); Matrix base = * this;    
        while(k) {  
            if(k & 1) ans = ans * base;  
            base = base * base;  
            k >>= 1;  
        }  
        //ans.out();  
        return ans;  
    }  

    void out() {  
        printf("N : %d\n",N);  
        rep(i,1,N){rep(j,1,N){printf("%d ",M[i][j]);}puts("");}puts("");}  
};  

Matrix A;

int calc() {
    int ret = 0;
    rep(i1,1,4) rep(i2,1,4) rep(i3,1,4) rep(i4,1,4) {
        if(i1 != i2 && i2 != i3 && i3 != i4 && i1 != i3 && i1 != i4 && i2 != i4) {
            ret = (ret + ((((A.M[1][i1] * A.M[2][i2]) % Mod) * A.M[3][i3]) % Mod) * A.M[4][i4] ) % Mod;
        }
    }
    return ret;
}

int ANS[105];

void init() {
    Matrix base ;
    A.init();
    base.init() ;
    rep(i,1,4) rep(j,1,4) {
        base.M[i][j] = 1;
        if(i == 1 && j == 3) base.M[i][j] = 0; 
        if(i == 2 && j == 4) base.M[i][j] = 0; 
        if(i == 3 && j == 1) base.M[i][j] = 0; 
        if(i == 4 && j == 2) base.M[i][j] = 0; 
    }
    //base.out();
    //A.out();
    rep(i,1,100) {
        A = A * base ;
        //A.out();
        ANS[i] = calc();
    }
}

void input() {
    scanf("%d",&n);
}

void solve() {
    printf("%d\n",ANS[n]);
}

int main(void) {
    //freopen("a.in","r",stdin);
    // scanf("%d",&T);
    // while(T--) {
    init();
    while(~scanf("%d",&n)) {
        //input();
        solve();
    }
    return 0;
}