/*********************************************
    Problem : HDU 5101
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
#define eps 1e-8

using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5;
const int MAXE = 2e5;

typedef long long LL;

int T,n,m,k;

int a[1005][105];
int M[1005];
int A[100005];
int num;

void input() {
    scanf("%d %d",&n,&k); k++;
    num = 1;
    rep(i,1,n) {
        scanf("%d",&m);
        M[i] = m;
        rep(j,1,m) { scanf("%d",&a[i][j]) ; A[num++] = a[i][j] ; }
        sort(a[i]+1,a[i]+m+1);
    }
    sort(A+1,A+num);
}

int erfen1(int value) {//å¯»æ¾æå°ç>=valueçæ°
    if(value > A[num-1]) return 0;
    int left = 1 , right = num - 1;
    int mid ;
    while(left < right) {
        mid = (left + right) >> 1;
        if(A[mid] < value)left = mid + 1;
        else right = mid ;
    }
    return num - left;
}

int erfen2(int value,int ia) {
    if(value > a[ia][M[ia]]) return 0;
    int left = 1 , right = M[ia];
    int mid ;
    while(left < right) {
        mid = (left + right) >> 1;
        if(a[ia][mid] < value)left = mid + 1 ;
        else right = mid ;
    }
    return M[ia] + 1 - left;
}

void solve() {
    int tmp1,tmp2;
    long long ans = 0;
    rep(i,1,n) {
        rep(j,1,M[i]) {
            tmp2 = erfen1(k-a[i][j]);
            tmp1 = erfen2(k-a[i][j],i);
            //printf("%d %d\n",tmp1,tmp2);
            ans += (LL)(tmp2 - tmp1);
        }
    }
    printf("%I64d\n",ans/2);
}

int main(void) {
    //freopen("a.in","r",stdin);
    scanf("%d",&T);
    while(T--) {
    //while(~scanf("%d %d",&n,&m)) {
        input();
        solve();
    }
    return 0;
}