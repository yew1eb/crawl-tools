/*********************************************
    Problem : HDU 5170
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

int a,b,c,d;

void input() {

}

void solve() {
    double a1 = b * log(a);
    double a2 = d * log(c);
    if(fabs(a1-a2)<eps) puts("=");
    else if(a1 > a2) puts(">");
    else puts("<");
}

int main(void) {
    //freopen("a.in","r",stdin);
    //scanf("%d",&T);
    //while(T--) {
    while(~scanf("%d %d %d %d",&a,&b,&c,&d)) {
        input();
        solve();
    }
    return 0;
}